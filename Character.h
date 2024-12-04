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
         * Getter function for a Character's maximum health
         * @return the max health
         */
        int get_max_health();

        /**
         * Setter function for a Character's maximum health
         */
        void set_max_health(int new_health);

        /**
         * Getter function for a Character's current health
         * @return the current health
         */
        int get_curr_health();

        /**
         * Setter function for a Character's current health
         */
        void set_curr_health(int new_health);

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
         * Getter function for a Character's maximum xp
         * @return the max xp
         */
        int get_max_xp();

        /**
         * Setter function for a Character's maximum xp
         */
        void set_max_xp(int new_xp);

        /**
         * Getter function for a Character's current xp
         * @return the current xp
         */
        int get_curr_xp();

        /**
         * Setter function for a Character's current xp
         */
        void set_curr_xp(int new_xp);

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
        int max_health;
        int curr_health;
        int attack;
        int max_xp;
        int curr_xp;
        vector<Item> inventory;
};

#endif