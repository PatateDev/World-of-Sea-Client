#include "Ship.h"

Ship::Ship()
{
    //ctor
}

// Buy functions
void Ship::addCannonballs(Cannonballs ammo)
{
    int i, a;

    for (i = 0;((m_ammoArray[i].getType() != ammo.getType()) && (i < MAX_CANNONBALLS)); i++)
    {
        //std::cout << "Array: " << m_ammoArray[i].getType() << " New: " << ammo.getType() << " i " << i << std::endl;
    }

    if (i == MAX_CANNONBALLS)
    {
        for (a = 0; m_ammoArray[a].getType() != "NULL"; a++ );

        m_ammoArray[a] = ammo;
        std::cout << "Ammo created." << std::endl;
        i = a;
    }
    else
    {
        std::cout << "Default: " << ammo.getAmmo() << std::endl;
        std::cout << "Array: " << m_ammoArray[i].getAmmo() << std::endl;
        m_ammoArray[i].addAmmo(ammo.getAmmo());
    }

    std::cout << "Ship::addCannonballs, " << ammo.getType() << " has been added. x"<< m_ammoArray[i].getAmmo() << std::endl;
}

void Ship::addCannon(Cannon cannon)
{
    int i, a;

    for (i = 0;((m_cannonArray[i].getType() != cannon.getType()) && (i < MAX_CANNON)); i++)
    {
       // std::cout << "Array: " << m_cannonArray[i].getType() << " New: " << cannon.getType() << " i " << i << std::endl;
    }
    //std::cout << "Array: " << m_cannonArray[i].getType() << " New: " << cannon.getType() << " i " << i << std::endl;

    if (i == MAX_CANNON)
    {
        for (a = 0; m_cannonArray[a].getType() != "NULL"; a++ );

        m_cannonArray[a] = cannon;
        i = a;
    }
    else
    {
        std::cout << "i: " << i << " nbToAdd: " << cannon.getNbCannon() << " Actual: " << m_cannonArray[i].getNbCannon() << std::endl;
        m_cannonArray[i].addCannon(cannon.getNbCannon());
    }
    std::cout << "Ship::addCannons, Cannons " << cannon.getType() << " has been added. x"<< m_cannonArray[i].getNbCannon() << std::endl;
}

void Ship::addDesign(Design design)
{
    int i, a;
    for (i = 0;((m_designArray[i].getName() != design.getName()) && (i < MAX_DESIGN)); i++)
    {
        //std::cout << "Array: " << m_designArray[i].getName() << " New: " << design.getName() << " i " << i << std::endl;
    }
    //std::cout << "Array: " << m_designArray[i].getName() << " New: " << design.getName() << " i " << i << std::endl;

    if (i == MAX_DESIGN)
    {
        for (a = 0; m_designArray[a].getName() != "NULL"; a++ );

        m_designArray[a] = design;
        std::cout << "Ship::addDesign, Design " << design.getName() << " has been added." << std::endl;
    }
    else
    {
        std::cout << "Ship::addDesign, You have already this design." << std::endl;
    }
}

void Ship::addMaxHp(int hp)
{
    m_maxHp = m_maxHp + hp;
    std::cout << "Ship::addMaxHp, Hp increase from " << m_maxHp - hp << " to "<< m_maxHp << "." << std::endl;
}

void Ship::addMaxCannon(int nb)
{
    m_maxCannon = m_maxCannon + nb;
    std::cout << "Ship::addMaxCannon, Cannons max quantity increase from " << m_maxCannon - nb << " to " << m_maxCannon << "." <<std::endl;
}
// Equip function
void Ship::setCannonballs(Cannonballs ammo)
{
    int i;
    for (i = 0;((m_ammoArray[i].getType() != ammo.getType()) && (i < MAX_CANNONBALLS)); i++)
    {
        //std::cout << "Array: " << m_ammoArray[i].getType() << " New: " << ammo.getType() << " i " << i << std::endl;
    }

    if (i == MAX_CANNONBALLS)
    {
        std::cout << "Ship::setCannonballs, You haven't got " << ammo.getType() << std::endl;
    }
    else
    {
        m_ammoEquiped = i;
        std::cout << "Ship::Cannonballs, you equiped " << m_ammoArray[i].getType() << "." << std::endl;
    }
}

void Ship::setCannonballs(std::string type)
{
    int i;
    for (i = 0;((m_ammoArray[i].getType() != type) && (i < MAX_CANNONBALLS)); i++)
    {
        //std::cout << "Array: " << m_ammoArray[i].getType() << " New: " << type << " i " << i << std::endl;
    }

    if (i == MAX_CANNONBALLS)
    {
        std::cout << "Ship::setCannonballs, You haven't got " << type << std::endl;
    }
    else
    {
        m_ammoEquiped = i;
        std::cout << "Ship::Cannonballs, you equiped " << m_ammoArray[i].getType() << "." << std::endl;
    }
}


void Ship::setCannonEquiped(Cannon cannon)
{
    int i, j, a, b;
    int actualCannon = 0;
    int overage = 0;
    bool haveCannon = false;

    for (b = 0; (m_cannonArray[b].getType() != cannon.getType()) && (b < MAX_CANNON); b++);
    //std::cout << "NB CANNON ARRAY: " << m_cannonArray[b].getNbCannon() << " " << m_cannonArray[b].getType() << std::endl;
    if ((b != MAX_CANNON) && (m_cannonArray[b].getNbCannon() >= cannon.getNbCannon()))
    {
        for (j = 0; (m_cannonEquipedArray[j].getType() != cannon.getType()) && (j < MAX_CANNON); j++);
        //std::cout << "j: " << j << std::endl;

        for (a = 0; a <= i; a++)
        {
                actualCannon += m_cannonEquipedArray[a].getNbCannon();
        }
        //std::cout << "ActualCannon: " << actualCannon << std::endl;

        if (j == MAX_CANNON)
        {
            for (i = 0; m_cannonEquipedArray[i].getType() != "NULL"; i++);


            if ((actualCannon + cannon.getNbCannon()) <= m_maxCannon)
            {
                m_cannonEquipedArray[i] = cannon;
                std::cout << "Ship::setCannonEquiped, You equiped " << m_cannonArray[i].getType() << " x" << m_cannonArray[i].getNbCannon() << "." << std::endl;
            }
            else
            {
                overage = (actualCannon + cannon.getNbCannon()) - m_maxCannon;
                cannon.delCannon(overage);
                m_cannonEquipedArray[i] = cannon;
                std::cout << "Ship::setCannonEquiped, You can't add more cannon than " << m_maxCannon << ", " << overage << " cannons were disabled." << std::endl;
            }
        }
        else
        {
            if ((actualCannon + cannon.getNbCannon()) <= m_maxCannon)
            {
                m_cannonEquipedArray[i].addCannon(cannon.getNbCannon());
                std::cout << "Ship::setCannonEquiped, You equiped " << m_cannonArray[i].getType() << " x" << cannon.getNbCannon() << "." << std::endl;
            }
            else
            {
                overage = (actualCannon + cannon.getNbCannon()) - m_maxCannon;
                cannon.delCannon(overage);
                m_cannonEquipedArray[j].addCannon(cannon.getNbCannon());
                std::cout << "Ship::setCannonEquiped, You can't add more cannon than " << m_maxCannon << ", " << overage << " cannons were disabled." << std::endl;
            }
        }

        actualCannon = 0;
        for (a = 0; a <= i; a++)
        {
            actualCannon += m_cannonEquipedArray[a].getNbCannon();
            std::cout << "Ship::setCannonEquiped, Finnaly you have " << m_cannonEquipedArray[a].getType() << " x" << m_cannonEquipedArray[a].getNbCannon() << "." << std::endl;
        }

        m_cannonArray[b].delCannon(cannon.getNbCannon());
    }
}

void Ship::setDesign(Design design)
{
    int i;
    for (i = 0;((m_designArray[i].getName() != design.getName()) && (i < MAX_DESIGN)); i++)
    {
        //std::cout << "Array: " << m_designArray[i].getName() << " New: " << design.getName() << " i " << i << std::endl;
    }
    //std::cout << "Array: " << m_designArray[i].getName() << " New: " << design.getName() << " i " << i << std::endl;

    if (i == MAX_DESIGN)
    {
        std::cout << "Ship::setDesign, You haven't got " << design.getName() << "." << std::endl;
    }
    else
    {
        m_designEquiped = i;
        std::cout << "Ship::setDesign, You have equiped " << m_designArray[i].getName() << "." << std::endl;
    }
}

void Ship::setDesign(std::string name)
{
    int i;
    for (i = 0;((m_designArray[i].getName() != name) && (i < MAX_DESIGN)); i++)
    {
        //std::cout << "Array: " << m_designArray[i].getName() << " New: " << name << " i " << i << std::endl;
    }
    //std::cout << "Array: " << m_designArray[i].getName() << " New: " << name << " i " << i << std::endl;

    if (i == MAX_DESIGN)
    {
        std::cout << "Ship::setDesign, You haven't got " << name << "." << std::endl;
    }
    else
    {
        m_designEquiped = i;
        std::cout << "Ship::setDesign, You have equiped " << m_designArray[i].getName() << "." << std::endl;
    }
}

void Ship::setHp(int hp)
{
    m_hp = hp;
    std::cout << "Ship::hp, You set " << m_hp << " max hp." << std::endl;
}

void Ship::setMaxCannon(int nb)
{
    m_maxCannon = nb;
    std::cout << "Ship::setMaxCannon, You set " << m_maxCannon << " max cannons." << std::endl;
}

void Ship::delCannon(Cannon cannon)
{
    int i;
    for (i = 0;((m_cannonArray[i].getType() != cannon.getType()) && (i < MAX_CANNON)); i++)
    {
        //std::cout << "Array: " << m_cannonArray[i].getType() << " New: " << cannon.getType() << " i " << i << std::endl;
    }
    //std::cout << "Array: " << m_cannonArray[i].getType() << " New: " << cannon.getType() << " i " << i << std::endl;

    if (i == MAX_CANNON)
    {
        std::cout << "Ship::delCannon, You haven't got these cannons." << std::endl;
    }
    else
    {
        m_cannonArray[i].delCannon(cannon.getNbCannon());
        std::cout << "Ship::delCannon, You delete " << cannon.getNbCannon() << cannon.getType() << "." << std::endl;
    }
}

void Ship::setGolds(int golds)
{
    m_golds = golds;
}

Cannonballs Ship::getCannonballs()
{
    return m_ammoArray[m_ammoEquiped];
}

std::string Ship::getCannonballsType()
{
    return m_ammoArray[m_ammoEquiped].getType();
}
//Cannon Ship::getCannon(); //TODO Ship::getCannon();
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

int Ship::getMaxCannon()
{
    return m_maxCannon;
}

int Ship::getGolds()
{
    return m_golds;
}

sf::String Ship::getStrGolds()
{
    std::ostringstream oss;
    oss << m_golds;
    return oss.str();
}

Ship::~Ship()
{
    //dtor
}
