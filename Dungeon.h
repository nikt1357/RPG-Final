#ifndef DUNGEON_H
#define DUNGEON_H

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Monster.h"
using namespace std;

/**
 * Dungeon class that represents the area the Character explores and encounters the Character might face
 */
class Dungeon
{
    public:
        /**
         * Constructs a Dungeon with a random layout and random encounters
         */
        Dungeon();

        /**
         * Getter function for the amount of rooms in a Dungeon
         */
        int get_rooms();

        /**
         * Function that generates a random Monster from a given vector
         * @return a random Monster
         */
        Monster generate_monster(int player_level);

        /**
         * Function that generates a random Item from a given vector
         * @return a random Item
         */
        Item generate_treasure();

        /*
        * Function that generates a random number of rooms for a Dungeon
        * @return a random int
        */
        int generate_num_rooms();
    private:
        int rooms;
};

#endif