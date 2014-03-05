#include "ShipHandler.h"

ShipHandler::ShipHandler()
{
    //ctor
}

void ShipHandler::setShip(Ship &ship)
{
    m_ship = &ship;
}

ShipHandler::~ShipHandler()
{
    //dtor
}
