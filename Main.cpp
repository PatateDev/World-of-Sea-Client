#include "Main.h"
#include "Class.h"

int main(int argc, char*argv[])
{
    sf::RenderWindow window(sf::VideoMode(LAUNCHER_WIDTH_X, LAUNCHER_HEIGHT_Y), "World of Sea v0");
    sf::Event event;

    // CLASS CANNON
    Cannon canonElite;
    canonElite.setCadence(2.5);
    canonElite.setHitRate(75);
    canonElite.setRange(30);
    canonElite.setType("Cannon Elite");
    canonElite.setCannon(100);

    // CLASS CANNON
    Cannon canonSimple;
    canonSimple.setCadence(2.5);
    canonSimple.setHitRate(75);
    canonSimple.setRange(30);
    canonSimple.setType("Cannon Simple");
    canonSimple.setCannon(100);
    // CLASS CANNONBALLS
    Cannonballs bouletCreux;
    bouletCreux.setAmmo(10000);
    bouletCreux.setDamage(100);
    bouletCreux.setType("Boulet Creux");
    bouletCreux.setWeight(10);
    //CLASS DESIGN
    Design elite1;
    elite1.setName("Elite 1");
    Design elite2;
    elite2.setName("Elite 2");

    // CLASS SHIP
    Ship monBateau;
    monBateau.addCannon(canonElite);
    monBateau.addCannon(canonSimple);
    monBateau.setMaxCannon(170);
    monBateau.setCannonEquiped(canonElite);
    monBateau.setCannonEquiped(canonElite);
    monBateau.setCannonEquiped(canonElite);
    monBateau.addDesign(elite1);
    monBateau.setDesign("Elite 1");


    while (window.isOpen())
    {
        window.waitEvent(event);

		if (event.type == sf::Event::Closed)
			window.close();
    }


    return 0;
}
