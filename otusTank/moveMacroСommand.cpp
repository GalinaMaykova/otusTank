
#include "moveMacro—ommand.h"
#include "checkFuelCommand.h"
#include "burnFuelCommand.h"
#include "movableAdapter.h"
#include "MacroCommand.h"
#include "moveCommand.h"
#include "myException.h"

MoveMacro—ommand::MoveMacro—ommand(UObject& obj) : m_obj(obj) {}
void MoveMacro—ommand::execute()
{
    CheckFuelCommand fuelCmdCheck(m_obj);
    BurnFuelCommand fuelCmdBurn(m_obj);

    MovableAdapter mAdapter(m_obj);
    MoveCommand moveCmd(mAdapter);

    std::vector<Command*> vecCmd;
    vecCmd.push_back(&fuelCmdCheck);
    vecCmd.push_back(&moveCmd);
    vecCmd.push_back(&fuelCmdBurn);
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
