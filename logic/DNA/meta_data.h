
#ifndef DNA_DESIGN_META_DATA_H
#define DNA_DESIGN_META_DATA_H

#include <string>
#include "dna_sequence.h"


class DNAMetaData
{
public:
    DNAMetaData(const char* sequence, std::string name);
    DNAMetaData(std::string sequence, std::string name);
    ~DNAMetaData();

    std::string get_name() const;
    size_t get_id() const;
    std::string get_DNA_seq() const;

private:
    std::string m_name;
    size_t m_id;
    DNASequence* m_DNA_seq;

    static size_t id;

};


inline DNAMetaData::DNAMetaData(const char* sequence, std::string name) : m_name(name), m_id(++id), m_DNA_seq(NULL)
{
    m_DNA_seq = new DNASequence(sequence);
}

inline DNAMetaData::DNAMetaData(std::string sequence, std::string name) : m_name(name), m_id(id++), m_DNA_seq(NULL)
{
    m_DNA_seq = new DNASequence(sequence);
}

inline DNAMetaData::~DNAMetaData()
{
    delete m_DNA_seq;
}

inline std::string DNAMetaData::get_name() const
{
    return m_name;
}

inline size_t DNAMetaData::get_id() const
{
    return m_id;
}

inline std::string DNAMetaData::get_DNA_seq() const
{
    return m_DNA_seq->get_sequence();
}


#endif //DNA_DESIGN_META_DATA_H
