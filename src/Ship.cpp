#include "ship.h"

Ship::Ship()
{
    //ctor
}

// Buy functions
void Ship::addCannonballs(Cannonballs ammo)
{
    int i;
    for (i = 0;((m_ammoArray[i].getType() != ammo.getType()) && (i < MAX_CANNONBALLS)); i++)
    {
        std::cout << "Array: " << m_ammoArray[i].getType() << " New: " << ammo.getType() << " i " << i << std::endl;
    }

    if (i == MAX_CANNONBALLS)
    {
        int a;
        for (a = 0; m_ammoArray[a].getType() != "NULL"; a++ );

        m_ammoArray[a] = ammo;
    }
    else
    {
        m_ammoArray[i].addAmmo(ammo.getAmmo());
    }
}

void Ship::addCannon(Cannon cannon)
{
    int i;
    for (i = 0;((m_cannonArray[i].getType() != cannon.getType()) && (i < MAX_CANNON)); i++)
    {
        std::cout << "Array: " << m_cannonArray[i].getType() << " New: " << cannon.getType() << " i " << i << std::endl;
    }
    std::cout << "Array: " << m_cannonArray[i].getType() << " New: " << cannon.getType() << " i " << i << std::endl;

    if (i == MAX_CANNON)
    {
        int a;
        for (a = 0; m_cannonArray[a].getType() != "NULL"; a++ );

        m_cannonArray[a] = cannon;
    }
    else
    {
        m_cannonArray[i].addCannon(cannon.getNbCannon());
    }
}

void Ship::addDesign(Design design)
{
    int i;
    for (i = 0;((m_designArray[i].getName() != design.getName()) && (i < MAX_DESIGN)); i++)
    {
        std::cout << "Array: " << m_designArray[i].getName() << " New: " << design.getName() << " i " << i << std::endl;
    }
    std::cout << "Array: " << m_designArray[i].getName() << " New: " << design.getName() << " i " << i << std::endl;

    if (i == MAX_DESIGN)
    {
        int a;
        for (a = 0; m_designArray[a].getName() != "NULL"; a++ );

        m_designArray[a] = design;
    }
    else
    {
        std::cout << "You have aleady this design." << std::endl;
    }
}

void Ship::addMaxHp(int hp)
{
    m_mapHp = m_mapHp + hp;
}

// Equip function
void Ship::setCannonballs(Cannonballs ammo)
{
    int i;
    for (i = 0;((m_ammoArray[i].getType() != ammo.getType()) && (i < MAX_CANNONBALLS)); i++)
    {
        std::cout << "Array: " << m_ammoArray[i].getType() << " New: " << ammo.getType() << " i " << i << std::endl;
    }

    if (i == MAX_CANNONBALLS)
    {
        std::cout << "You haven't got " << ammo.getType() << std::endl;
    }
    else
    {
        m_ammoEquiped = i;
    }
}

void Ship::setCannonballs(std::string type)
{
    int i;
    for (i = 0;((m_ammoArray[i].getType() != type) && (i < MAX_CANNONBALLS)); i++)
    {
        std::cout << "Array: " << m_ammoArray[i].getType() << " New: " << type << " i " << i << std::endl;
    }

    if (i == MAX_CANNONBALLS)
    {
        std::cout << "You haven't got " << type << std::endl;
    }
    else
    {
        m_ammoEquiped = i;
    }
}


//void Ship::setCannon(Cannon cannon, int number);
void Ship::setDesign(Design design)
{
    int i;
    for (i = 0;((m_designArray[i].getName() != design.getName()) && (i < MAX_DESIGN)); i++)
    {
        std::cout << "Array: " << m_designArray[i].getName() << " New: " << design.getName() << " i " << i << std::endl;
    }
    std::cout << "Array: " << m_designArray[i].getName() << " New: " << design.getName() << " i " << i << std::endl;

    if (i == MAX_DESIGN)
    {
        std::cout << "You haven't got: " << design.getName() << std::endl;
    }
    else
    {
        m_designEquiped = i;
    }
}

void Ship::setDesign(std::string name)
{
    int i;
    for (i = 0;((m_designArray[i].getName() != name) && (i < MAX_DESIGN)); i++)
    {
        std::cout << "Array: " << m_designArray[i].getName() << " New: " << name << " i " << i << std::endl;
    }
    std::cout << "Array: " << m_designArray[i].getName() << " New: " << name << " i " << i << std::endl;

    if (i == MAX_DESIGN)
    {
        std::cout << "You haven't got: " << name << std::endl;
    }
    else
    {
        m_designEquiped = i;
    }
}

void Ship::setHp(int hp)
{
    m_hp = hp;
}


Cannonballs Ship::getCannonballs()
{
    return m_ammoArray[m_ammoEquiped];
}

std::string Ship::getCannonballsType()
{
    return m_ammoArray[m_ammoEquiped].getType();
}
//Cannon Ship::getCannon();
Design Ship::getDesign()
{
    return m_designArray[m_designEquiped];
}

std::string Ship::getDesignName()
{
    return m_designArray[m_designEquiped].getName();
}

int Ship::getHp()
{
    return m_hp;
}

Ship::~Ship()
{
    //dtor
}
