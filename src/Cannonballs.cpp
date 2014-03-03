#include "Cannonballs.h"

Cannonballs::Cannonballs()
: m_type("NULL")
{
    //ctor
}

void Cannonballs::addAmmo(int ammo)
{
    m_ammo = m_ammo + ammo;
}

//

void Cannonballs::setDamage(int damage)
{
    m_damage = damage;
}

void Cannonballs::setWeight(int weight)
{
    m_weight = weight;
}

void Cannonballs::setAmmo(int ammo)
{
    m_ammo = ammo;
}

void Cannonballs::setType(std::string type)
{
    m_type = type;
}

//

int Cannonballs::getDamage()
{
    return m_damage;
}

int Cannonballs::getWeight()
{
    return m_weight;
}

int Cannonballs::getAmmo()
{
    return m_ammo;
}

std::string Cannonballs::getType()
{
    return m_type;
}

//

Cannonballs::~Cannonballs()
{
    //dtor
}
