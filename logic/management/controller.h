
#ifndef UNTITLED3_CONTROLLER_H
#define UNTITLED3_CONTROLLER_H

#include "CLI.h"
#include "../commands/icommand.h"
#include "../build/cmd_factory.h"


class Controller
{
public:
    void run();

    CLI* get_cli() const;

private:
    CLI* m_cli;
    CmdFactory* m_factory;
};


inline void Controller::run()
{
    std::vector<std::string> params = m_cli->split(m_cli->input());

    ICommand* command = m_factory->create_command(params[0]);

    m_cli->output(command->do_action(params));

    delete command;
    command = NULL;
}

inline CLI* Controller::get_cli() const
{
    return m_cli;
}


#endif //UNTITLED3_CONTROLLER_H
