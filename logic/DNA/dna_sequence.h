#ifndef DNA_DNA_SEQUENCE_H
#define DNA_DNA_SEQUENCE_H

#include <cstring>
#include <vector>
#include "../exceptions/exceptions.h"


class DNASequence
{
private:
	class Nucleotide
	{   
	public:
        Nucleotide();
        Nucleotide(char letter);

        Nucleotide& operator=(char letter);
		bool operator!=(Nucleotide sequence);
		
		char get_letter();
	    bool is_valid_letter(char letter);

		friend std::ostream& operator<< (std::ostream& output, const Nucleotide& sequence);
		
	private:
		char m_letter;
	};

    Nucleotide* m_nucleotide;

public:
	void init(const std::string& str);
    DNASequence(const char* c_string);
    DNASequence(std::string str);
    ~DNASequence();
    DNASequence(const DNASequence& dna_sequence);

    DNASequence& operator=(const DNASequence&);
    DNASequence& operator=(const char* seqStr);
    DNASequence::Nucleotide& operator[](size_t index) const;
    size_t get_sequence_length() const;
    std::string get_sequence() const;
    bool is_valid_characters(std::string) const;
    std::string get_slice_seq(int start, int end) const;
    std::string get_pair() const;
    size_t find_subsequence(const DNASequence&) const;
    std::vector<size_t> find_all_subsequences(const DNASequence&) const;
    size_t count_subsequences(const DNASequence&) const;

	friend std::ostream& operator<<(std::ostream& output, const DNASequence& dna_sequence);
	friend std::ostream& operator<<(std::ostream& output, const DNASequence::Nucleotide& sequence);
    
};


bool operator==(const DNASequence&, const DNASequence&);
bool operator!=(const DNASequence&, const DNASequence&);
    

inline DNASequence::~DNASequence()
{
    delete[] m_nucleotide;
    m_nucleotide = NULL;
}

inline size_t DNASequence::get_sequence_length() const
{
    size_t len;

	for(len = 0; m_nucleotide[len].get_letter(); ++len);
	
	return len;
}

inline std::string DNASequence::get_sequence() const
{
    std::string seqString;
    size_t seqLen = get_sequence_length();

    for(size_t i = 0 ; i <= seqLen ; ++i)
        seqString += m_nucleotide[i].get_letter();

    return seqString;
}

inline DNASequence& DNASequence::operator=(const DNASequence& dna_sequence)
{
	size_t len = dna_sequence.get_sequence_length();
	DNASequence::Nucleotide* sequence = new DNASequence::Nucleotide[len + 1];
	
	for (std::size_t i = 0; i <= len; i++) 
		sequence[i] = dna_sequence.m_nucleotide[i];
		
	delete[] m_nucleotide;
	m_nucleotide = sequence;
	
	return *this;
}

inline DNASequence& DNASequence::operator=(const char* seqStr)
{
	try
	{
		size_t len = strlen(seqStr);
		DNASequence::Nucleotide* sequence = new DNASequence::Nucleotide[len + 1];
		delete[] m_nucleotide;
		
		for (std::size_t i = 0; i <= len; i++) 
		{
			sequence[i] = sequence[i];
		}
		m_nucleotide = sequence;
	}
	catch(InvalidLetter& error) {
		delete[] m_nucleotide;
		throw;
	}
	return *this;
}

inline bool operator==(const DNASequence& dna_sequence1 , const DNASequence& dna_sequence2)
{
	size_t len1 = dna_sequence1.get_sequence_length(), len2 = dna_sequence2.get_sequence_length();
	
	if(len1 != len2) 
		return false;
	
	for(size_t i = 0; i < len1; ++i)
	
		if(dna_sequence1[i] != dna_sequence2[i])
			return false;

	return true;
}

inline bool operator!=(const DNASequence& dna_sequence1 , const DNASequence& dna_sequence2)
{
    return !(dna_sequence1 == dna_sequence2);
}

inline DNASequence::Nucleotide& DNASequence::operator[](size_t index) const
{
    return m_nucleotide[index];
}

inline size_t DNASequence::count_subsequences(const DNASequence& dna_sequence) const
{
    return find_all_subsequences(dna_sequence).size();
}

////////////////////////////////////////////

inline std::ostream& operator<<(std::ostream& output, const DNASequence::Nucleotide& sequence)
{
    output << sequence.m_letter;
    
    return output;

}

inline DNASequence::Nucleotide::Nucleotide(){}

inline DNASequence::Nucleotide::Nucleotide(char letter) : m_letter(letter)
{
    if(0 == is_valid_letter(letter))
    	throw InvalidLetter("Error");
}

inline char DNASequence::Nucleotide::get_letter()
{
	return m_letter;
}

inline DNASequence::Nucleotide& DNASequence::Nucleotide::operator=(char letter)
{
    if(0 == is_valid_letter(letter))
    {
    	throw InvalidLetter("Error");
    }
    	
	m_letter = letter;
	
	return *this;
}

inline bool DNASequence::Nucleotide::operator!=(Nucleotide nucleotide)
{
	return m_letter == nucleotide.get_letter();
}

inline bool DNASequence::Nucleotide::is_valid_letter(char letter)
{
	return 'A' == letter || 'T' == letter  || 'G' == letter || 'C' == letter  || '\0' == letter;
}

inline std::ostream& operator<<(std::ostream& output, const DNASequence& dna_sequence) 
{
	size_t len = dna_sequence.get_sequence_length();
	
	for (std::size_t i = 0; i < len; ++i)
		output << dna_sequence.m_nucleotide[i];

	return output;
}


#endif
