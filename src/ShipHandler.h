#ifndef SHIPHANDLER_H
#define SHIPHANDLER_H

#include "Ship.h"
#include "NetworkReceive.h"
#include "../Main.h"

class ShipHandler
{
    public:
        ShipHandler();

        void setShip(Ship &ship);
        void setSocket(sf::TcpSocket &socket);
        void setNetworkReceive(NetworkReceive &networkReceive);

        int request(int step, int ID, int value1 = 0, int value2 = 0, int value3 = 0, int value4 = 0);

        virtual ~ShipHandler();
    protected:
        Ship *m_ship;

        sf::TcpSocket *m_socket;

        NetworkReceive *m_networkReceive;

        sf::Packet *m_packet;
    private:
};

#endif // SHIPHANDLER_H
