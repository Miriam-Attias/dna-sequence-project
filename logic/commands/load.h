
#ifndef DNA_DESIGN_LOAD_H
#define DNA_DESIGN_LOAD_H


#include "icommand.h"
#include "../DNA/meta_data.h"


class Load: public ICommand
{
public:
    /*virtual*/ std::string do_action(const std::vector<std::string>& params);

private:
    void is_valid_params(const std::vector<std::string>& params) const;
    std::string create_seq_name(const std::vector<std::string>& params) const;
    std::string create_output_seq(const DNAMetaData& metaData) const;
    void update_DNA_data(DNAMetaData& metaData) const;

};


#endif //DNA_DESIGN_LOAD_H
