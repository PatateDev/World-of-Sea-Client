#ifndef SHIPHANDLER_H
#define SHIPHANDLER_H

#include "Ship.h"

class ShipHandler
{
    public:
        ShipHandler();

        void setShip(Ship &ship);

        virtual ~ShipHandler();
    protected:
        Ship *m_ship;
    private:
};

#endif // SHIPHANDLER_H
