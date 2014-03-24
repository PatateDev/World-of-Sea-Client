#ifndef NETWORKRECEIVE_H
#define NETWORKRECEIVE_H

#include "../Main.h"

class NetworkReceive
{
    public:
        NetworkReceive();

        sf::Packet *getPacket(int ID, sf::TcpSocket &socket);

        virtual ~NetworkReceive();
    protected:
    private:
        sf::TcpSocket *m_socket;

        sf::Packet *m_packet;

        int m_packet_ID;

        bool m_canReceive;
};

#endif // NETWORKRECEIVE_H
