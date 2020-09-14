
#ifndef DNA_DESIGN_CMD_FACTORY_H
#define DNA_DESIGN_CMD_FACTORY_H

#include "../commands/icommand.h"


class CmdFactory
{
public:
    ICommand* create_command(const std::string& command_name);

};


#endif //DNA_DESIGN_CMD_FACTORY_H
