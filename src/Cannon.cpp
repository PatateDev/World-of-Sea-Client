#include "../include/Cannon.h"

Cannon::Cannon()
: m_type("NULL")
{
    //ctor
}

void Cannon::addCannon(int nb)
{
    m_nbCannon =  m_nbCannon + nb;
}

void Cannon::setHitRate(int probabilitie)
{
    m_hitRate = probabilitie;
}

void Cannon::setCadence(double time)
{
    m_time = time;
}

void Cannon::setRange(int range)
{
    m_range = range;
}

void Cannon::setType(std::string type)
{
    m_type = type;
}

void Cannon::setCannon(int nb)
{
    m_nbCannon = nb;
}

//

int Cannon::getHitRate()
{
    return m_hitRate;
}

double Cannon::getCadence()
{
    return m_time;
}

int Cannon::getRange()
{
    return m_range;
}

int Cannon::getNbCannon()
{
    return m_nbCannon;
}

std::string Cannon::getType()
{
    return m_type;
}

Cannon::~Cannon()
{
    //dtor
}
