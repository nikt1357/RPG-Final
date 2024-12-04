#ifndef DUNGEON_H
#define DUNGEON_H

#include <string>
#include <vector>
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
         * Getter function for a Dungeon's possible monsters
         * @return vector of possible monsters
         */
        vector<Monster> get_possible_monsters();

        /**
         * Getter function for a Dungeon's possible items
         * @return vector of possible items
         */
        vector<Item> get_possible_items();

        /**
         * Function that generates a random Monster from a given vector
         * @return a random Monster
         */
        Monster generate_monster(vector<Monster> monsters);

        /**
         * Function that generates a random Item from a given vector
         * @return a random Item
         */
        Item generate_item(vector<Item> items);
    private:
        int rooms;
        vector<Monster> possible_monsters;
        vector<Item> possible_items;
};

#endif