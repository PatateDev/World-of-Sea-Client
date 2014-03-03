#ifndef CANNONBALLS_H
#define CANNONBALLS_H

#include "../Main.h"

class Cannonballs
{
    public:
        Cannonballs();

        void addAmmo(int ammo);

        void setDamage(int damage);
        void setWeight(int weight);
        void setAmmo(int ammo);
        void setType(std::string type);

        int getDamage();
        int getWeight();
        int getAmmo();
        std::string getType();

        //bool operator!=(Cannonballs const& a);

        virtual ~Cannonballs();
    protected:
    private:
        int m_damage;
        int m_weight;
        int m_ammo;
        std::string m_type;
};

#endif // CANNONBALLS_H
