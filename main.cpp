
#include "logic/exceptions/exceptions.h"
#include "logic/management/controller.h"


int main()
{
    Controller controller;
    while (true)
    {
        try
        {
            controller.run();
        }
        catch (const MyExceptions &ex)
        {
            controller.get_cli()->output(ex.what());
        }
    }
    return 0;
}
