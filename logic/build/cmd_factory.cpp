
#include "../build/cmd_factory.h"
#include "../commands/load.h"


ICommand* CmdFactory::create_command(const std::string& command_name)
{
    ICommand* command;

    if ("load" == command_name)
        command = new Load();
    else
    {
        throw InvalidCmdName(command_name);
    }
    return command;
}