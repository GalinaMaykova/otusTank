#include "moveCommand.h"

MoveCommand::MoveCommand(IMovable& movable) : m_movable(movable)
{}

void MoveCommand::execute()
{
    myVector temp = m_movable.getPosition() + m_movable.getVelocity();
    m_movable.setPosition(temp);
}