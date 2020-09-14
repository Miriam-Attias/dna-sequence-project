
#ifndef DNA_DESIGN_CLI_H
#define DNA_DESIGN_CLI_H

#include <iostream> // for cin
#include <vector>
#include "../build/cmd_factory.h" //TODO?


class CLI
{
public: // TODO not create
    CLI();

    ICommand* get_command() const;
    std::vector<std::string> get_params() const;

private:
    std::string m_strCommand;
    ICommand* m_command; // TODO get out
    std::vector<std::string> m_params;

    std::string input() const;
    std::vector<std::string> split(const std::string& strCommand) const;

};


inline CLI::CLI() : m_strCommand(input()), m_command(NULL), m_params(split(m_strCommand))
{
    m_command = CmdFactory().create_command(m_params[0]);
}

inline ICommand* CLI::get_command() const
{
    return m_command;
}

inline std::vector<std::string> CLI::get_params() const
{
    return m_params;
}

inline std::string CLI::input() const
{
    std::string input;
    std::cout << ">> my_cmd :) ";
    std::getline(std::cin, input);
    return input;
}



#endif //DNA_DESIGN_CLI_H
