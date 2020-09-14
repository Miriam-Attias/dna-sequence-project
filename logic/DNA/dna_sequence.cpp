
#include <string>
#include <map>
#include "dna_sequence.h"
#include "../exceptions/exceptions.h"


bool DNASequence::is_valid_characters(std::string str) const
{
    size_t strSize = str.length();

    for(size_t i = 0; i < strSize; ++i)
    {
        if(str[i] != 'C' and str[i] != 'T' and str[i]  != 'A' and str[i]  != 'G')
            return true;
    }
    return false;
}

void DNASequence::init(const std::string& str)
{
    size_t strSize = str.length();
    m_nucleotide = new DNASequence::Nucleotide[strSize + 1];

    for(size_t i = 0 ; i < strSize ; ++i)
        m_nucleotide[i] = str[i];
}

DNASequence::DNASequence(const char* c_string) : m_nucleotide(NULL)
{
    if(c_string[strlen(c_string)] != '\0')
        throw NoNullTerminate("Error");

    if(is_valid_characters(c_string))
        throw InvalidDna("Error");

    init(std::string(c_string).c_str());
}

DNASequence::DNASequence(std::string str) : m_nucleotide(NULL)
{
    if(str[str.length()] != '\0')
        throw NoNullTerminate("Error");

    if(is_valid_characters(str))
        throw InvalidDna("Error");

    init(str);
}

DNASequence::DNASequence(const DNASequence& dna_sequence) : m_nucleotide(NULL) 
{
	size_t seqSize = dna_sequence.get_sequence_length();
	m_nucleotide = new DNASequence::Nucleotide[seqSize + 1];
	
	for (std::size_t i = 0; i <= seqSize; ++i) {
		m_nucleotide[i] = dna_sequence.m_nucleotide[i];
	}
}

std::string DNASequence::get_slice_seq(int start, int end) const
{
    std::string seqString = "";

    for(size_t i = start ; i <= size_t(end) ; ++i)
        seqString += m_nucleotide[i].get_letter();

    return seqString;
}

std::string DNASequence::get_pair() const
{
    std::map<char, char> seqPair;
    seqPair['C'] = 'G';
    seqPair['G'] = 'C';
    seqPair['A'] = 'T';
    seqPair['T'] = 'A';

    size_t seqLen = get_sequence_length();
    std::string pairString = "", seqString = get_sequence();

    for(size_t i = 0 ; i <= seqLen ; ++i)
        pairString += seqPair[seqString[i]];

    return pairString;
}

size_t DNASequence::find_subsequence(const DNASequence& dna_sequence) const
{
    size_t flag = 0, seqLen = get_sequence_length(), subseqLen = dna_sequence.get_sequence_length();

    for(size_t i = 0 ; i <= seqLen ; ++i)
    {
        if(m_nucleotide[i].get_letter() == dna_sequence.m_nucleotide[flag].get_letter())
        {
            flag++;

            if(flag == subseqLen)
                return i;
        }
        else flag = 0;
    }
    return -1;
}

std::vector<size_t> DNASequence::find_all_subsequences(const DNASequence& dna_sequence) const
{
    size_t flag = 0, seqLen = get_sequence_length(), subseqLen = dna_sequence.get_sequence_length();
    std::vector<size_t> s_subsequences;

    for(size_t i = 0 ; i <= seqLen ; ++i)
    {
        if(m_nucleotide[i].get_letter() == dna_sequence.m_nucleotide[flag].get_letter())
        {
            flag++;

            if(flag == subseqLen)
                s_subsequences.push_back(i);
        }
        else flag = 0;
    }
    return s_subsequences;
}


