#ifndef CANON_H
#define CANON_H

#include "../Main.h"

class Cannon
{
    public:
        Cannon();

        void addCannon(int nb);
        void delCannon(int nb);

        void setHitRate(int probabilitie);
        void setCadence(double time);
        void setRange(int range);
        void setType(std::string type);
        void setCannon(int nb);

        int getHitRate();
        double getCadence();
        int getRange();
        int getNbCannon();
        std::string getType();

        virtual ~Cannon();
    protected:
    private:
        int m_hitRate;
        int m_range;
        int m_nbCannon;
        double m_time;
        std::string m_type;
};

#endif // CANON_H
