#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Item.h"
using namespace std;

/**
 * Character class that represents the player
 */
class Character
{
    public:
        /**
         * Constructs a Character with default stats
         */
        Character(string char_name);

        /**
         * Getter function for a Character's name
         * @return the name
         */
        string get_name();

        /**
         * Getter function for a Character's level
         * @return the level
         */
        int get_level();

        /**
         * Setter function for a Character's level
         */
        void set_level(int new_level);

        /**
         * Getter function for a Character's health
         * @return the health
         */
        int get_health();

        /**
         * Setter function for a Character's health
         */
        void set_health(int new_health);

        /**
         * Getter function for a Character's attack points
         * @return attack points
         */
        int get_attack();

        /**
         * Setter function for a Character's attack points
         */
        void set_attack(int new_attack);

        /**
         * Getter function for a Character's xp
         * @return the xp
         */
        int get_xp();

        /**
         * Setter function for a Character's xp
         */
        void set_xp(int new_xp);

        /**
         * Getter function for Character's inventory
         * @return the inventory
         */
        vector<Item> get_inventory();

        /**
         * Function that adds a given Item into the Character's inventory if there is enough space
         * @return 0 on success
         * @return 1 on failure
         */
        int add_to_inventory(Item item);

        /**
         * Function that handles fighting an enemy
         */
        void fight();
    private:
        string name;
        int level;
        int health;
        int attack;
        int xp;
        vector<Item> inventory;
};

#endif