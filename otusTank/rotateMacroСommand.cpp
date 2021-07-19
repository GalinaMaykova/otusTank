#include "rotateMacro—ommand.h"
#include "rotableAdapter.h"
#include "rotateCommand.h"
#include "changeVelocityCommand.h"
#include "macroCommand.h"
#include "myException.h"



RotateMacro—ommand::RotateMacro—ommand(UObject& obj) : m_obj(obj) {}
void RotateMacro—ommand::execute()
{
    RotableAdapter rA(m_obj);
    RotateCommand rotateCmd(rA);
    ChangeVelocityCommand changeVelCmd(m_obj);

    std::vector<Command*> vecCmd;
    vecCmd.push_back(&rotateCmd);
    vecCmd.push_back(&changeVelCmd);

    Macro—ommand macroCmd(vecCmd);
    try
    {
        macroCmd.execute();
    }
    catch (CommandException& ex)
    {
        std::cout << ex.what() << std::endl;
        throw ex;
    }
}
