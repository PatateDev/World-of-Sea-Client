#ifndef SHIPHANDLER_H
#define SHIPHANDLER_H

#include "Ship.h"
#include "NetworkReceive.h"

class ShipHandler
{
    public:
        ShipHandler();

        void setShip(Ship &ship);
        void setSocket(sf::TcpSocket &socket);
        void setNetworkReceive(NetworkReceive &networkReceive);

        virtual ~ShipHandler();
    protected:
        Ship *m_ship;

        sf::TcpSocket *m_socket;

        NetworkReceive *m_networkReceive;

        sf::Packet *m_packet;
    private:
};

#endif // SHIPHANDLER_H
