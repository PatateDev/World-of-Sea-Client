#ifndef SHIP_H
#define SHIP_H

#include "Cannonballs.h"
#include "Cannon.h"
#include "Design.h"

#define MAX_DESIGN 64
#define MAX_CANNONBALLS 32
#define MAX_CANNON 32

class Ship
{
    public:
        Ship();
        // When you buy
        void addCannonballs(Cannonballs ammo);
        void addCannon(Cannon cannon);
        void addDesign(Design design);
        void addMaxHp(int hp);
        void addMaxCannon(int nb);
        //
        void setCannonballs(Cannonballs ammo);
        void setCannonballs(std::string type);
        void setCannonEquiped(Cannon cannon);
        void setDesign(Design design);
        void setDesign(std::string name);
        void setHp(int hp);
        void setMaxCannon(int nb);
        void setGolds(int gold);

        void delCannon(Cannon cannon);

        void resetCannonEquiped(Cannon cannon); // NON FAIT

        Cannonballs getCannonballs();
        std::string getCannonballsType();
        Cannon getCannon();
        Design getDesign();
        std::string getDesignName();
        int getHp();
        int getMaxCannon();
        int getGolds();
        sf::String getStrGolds();

        virtual ~Ship();
    protected:
    private:
        int m_golds;

        int m_mapHp;
        int m_hp;

        Cannon m_cannonArray[MAX_CANNON + 12];
        Cannon m_cannonEquipedArray[MAX_CANNON + 12];
        int m_maxCannon;

        Cannonballs m_ammoArray[MAX_CANNONBALLS + 12];
        int m_ammoEquiped;

        Design m_designArray[MAX_DESIGN + 12];
        int m_designEquiped;

};

#endif // SHIP_H
