
#ifndef DNA_DESIGN_ICOMMAND_H
#define DNA_DESIGN_ICOMMAND_H

#include <string>
#include <vector>


class ICommand
{
public:
    virtual ~ICommand(){};

    virtual std::string do_action(const std::vector<std::string>& params) = 0;

};


#endif //DNA_DESIGN_ICOMMAND_H
