
#include <sstream>  // for istringstream
#include "CLI.h"


std::vector<std::string> CLI::split(const std::string& strCommand) const
{
    std::istringstream iss(strCommand);
    std::string word;
    std::vector<std::string> res;

    while (std::getline(iss, word, ' '))
    {
        res.push_back(word);
    }
    return res;
}