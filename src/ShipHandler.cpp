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

int ShipHandler::request(int step, int ID, int value1, int value2, int value3, int value4)
{
    if (step == 0)
    {
            m_packet = new sf::Packet;
            m_packet->clear();
            *m_packet << ID << value1 << value2 << value3 << value4;
            m_socket->send(*m_packet);
            return 1;
    }
    else if (step == 1)
    {
            delete m_packet;
            m_packet = m_networkReceive->getPacket(ID, *m_socket);

            if (m_packet)
            {
                return 2;
            }
            else
            {
                m_packet = new sf::Packet;
                return 1;
            }
    }

}

ShipHandler::~ShipHandler()
{
    m_packet = 0;
}
