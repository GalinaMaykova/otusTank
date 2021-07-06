#include "rotateCommand.h"

RotateCommand::RotateCommand(IRotable& rotable) : m_rotable(rotable){}

void RotateCommand::execute()
{
    int temp = (m_rotable.getDirection() + m_rotable.getAngularVelocity()) % 360;
    m_rotable.setDirection(temp);
}