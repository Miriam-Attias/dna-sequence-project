
#include <sstream> // for stringstream
#include "load.h"
#include "../files_handler/files_handler.h"
#include "../DNA/dnas_data.h"


void Load::is_valid_params(const std::vector<std::string>& params) const
{
    if (params.size() < 2 || params.size() > 3)
    {
        throw InvalidAmountOfArguments("Error");
    }

    if(params.size() == 3)
    {
        if (params.at(2)[0] != '@' || params.at(2).length() < 2)
        {
            throw InvalidArgument("Error");
        }
    }
}

std::string Load::create_seq_name(const std::vector<std::string>& params) const
{
    std::string sequence_name;

    if (params.size() == 2) // create default name
    {
        sequence_name = params[1].substr(0, params[1].size() - 4); //remove ".txt" suffix
    }
    else
    {
        sequence_name = params[2];
    }
    return sequence_name;
}

std::string Load::create_output_seq(const DNAMetaData& metaData) const
{
    std::string sequence = metaData.get_DNA_seq();
    std::stringstream output_seq;

    output_seq << "[" << metaData.get_id() << "] " << metaData.get_name()  << ": ";

    if (sequence.length() > 40)
    {
        output_seq << sequence.substr(0, 32) << "..."
        << sequence.substr(sequence.size() - 3 , sequence.size());
    }
    else
    {
        output_seq << sequence;
    }
    return output_seq.str();
}

void Load::update_DNA_data(DNAMetaData& metaData) const
{
    DNAsData::m_ids.resize(DNAsData::m_ids.size() + 1);

    DNAsData::m_ids[metaData.get_id()] = &metaData;
    DNAsData::m_names[metaData.get_name()] = &metaData;
}

std::string Load::do_action(const std::vector<std::string>& params)
{
    is_valid_params(params);

    std::string sequence, seq_name, output;

    sequence = read_from_file(params[1]);

    seq_name = create_seq_name(params);
    DNAMetaData metaData(sequence, seq_name);

    update_DNA_data(metaData);

    output = create_output_seq(metaData);

    delete &metaData;

    return output;
}