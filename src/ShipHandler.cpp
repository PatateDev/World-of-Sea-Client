#include "ShipHandler.h"

ShipHandler::ShipHandler()
{
    m_packet = new sf::Packet;
}

void ShipHandler::setShip(Ship &ship)
{
    m_ship = &ship;
}

void ShipHandler::setSocket(sf::TcpSocket &socket)
{
    m_socket = &socket;
}

void ShipHandler::setNetworkReceive(NetworkReceive &networkReceive)
{
    m_networkReceive = &networkReceive;
}

ShipHandler::~ShipHandler()
{
    m_packet = 0;
}
