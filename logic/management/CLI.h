
#ifndef DNA_DESIGN_CLI_H
#define DNA_DESIGN_CLI_H

#include <iostream>
#include <vector>


class CLI
{
public:
    std::string input() const;
    std::vector<std::string> split(const std::string& strCommand) const;
    void output(std::string output) const;

};


inline std::string CLI::input() const
{
    std::string input;
    output(">> my_cmd :) ");
    std::getline(std::cin, input);

    return input;
}

inline void CLI::output(std::string output) const
{
    std::cout << output << std::endl;
}


#endif //DNA_DESIGN_CLI_H
