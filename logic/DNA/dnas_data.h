
#ifndef DNA_DESIGN_DNAS_DATA_H
#define DNA_DESIGN_DNAS_DATA_H

#include <map>
#include "meta_data.h"


class DNAsData
{
public:
    static std::vector<DNAMetaData*> m_ids;
    static std::map<std::string, DNAMetaData*> m_names;

};


#endif //DNA_DESIGN_DNA_DATA_H
