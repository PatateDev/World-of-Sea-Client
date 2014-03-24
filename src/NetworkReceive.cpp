#include "NetworkReceive.h"

NetworkReceive::NetworkReceive()
:m_canReceive(true)
{
    m_packet = new sf::Packet;
}

sf::Packet* NetworkReceive::getPacket(int ID, sf::TcpSocket &socket)
{
    if (m_canReceive)
    {
        m_packet->clear();
        socket.receive(*m_packet);
        *m_packet >> m_packet_ID;
        m_canReceive = false;
    }

    if (ID == m_packet_ID)
    {
        m_canReceive = true;
        //std::cout << "NetworkReceive: Return packet" << std::endl;
        return m_packet;
    }
    else
    {
        //std::cout << "NetworkReceive: Return Null packet"<< std::endl;
        return 0;
    }

}

NetworkReceive::~NetworkReceive()
{
    delete m_packet;
}
