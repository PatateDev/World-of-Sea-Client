#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <SFML/UI.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <cstdlib>
#include <sstream>

#include "Config.h"

#define LAUNCHER_WIDTH_X 1280
#define LAUNCHER_HEIGHT_Y 800

#define CLIENT_VERSION_MAJOR 0
#define CLIENT_VERSION_MINOR 0
#define CLIENT_VERSION_PATCH 1

enum EnumRequest
{
    CONNECT = 0,
    LOGOUT = 1,
    STOP = 2,
    GETSHIP = 3,
    OK = 4,

    WOODEN_CANNONBALLS = 5,
    STONE_CANNONBALLS = 6,
    COBBLESTONE_CANNONBALLS = 7,
    METAL_CANNONBALLS = 8,

    BUY_WOODEN_CANNONBALLS = 10,
    BUY_STONE_CANNONBALLS = 11,
    BUY_COBBLESTONE_CANNONBALLS = 12,
    BUY_METAL_CANNONBALLS = 13,
    BUY_LIGHT_CANNONS = 14,
    BUY_HEAVY_CANNONS = 15,

    EQUIP_WOODEN_CANNONBALLS = 20,
    EQUIP_STONE_CANNONBALLS = 21,
    EQUIP_COBBLESTONE_CANNONBALLS = 22,
    EQUIP_METAL_CANNONBALLS = 23,
    EQUIP_LIGHT_CANNONS = 24,
    EQUIP_HEAVY_CANNONS = 25,
};

#endif // MAIN_H_INCLUDED
