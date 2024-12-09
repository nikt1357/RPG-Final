#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <windows.h>
#include "Item.h"
class Monster;
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
         * Function that removes an Item from a Character's inventory given the index of the Item
         */
        void remove_from_inventory(int index);

        /**
        * Function that prints out a Character's stats
        */
        void display_stats();

        /**
        * Function that prints out a Character's inventory
        */
        void display_inventory();

        /**
         * Getter function for a Character's current gold
         * @return the gold
         */
        int get_gold();

        /**
         * Setter function for a Character's gold
         */
        void set_gold(int new_gold);

        /**
         * Getter function for the number of rooms a Character has explored
         * @return number of rooms
         */
        int get_rooms_explored();

        /**
         * Setter function for the number of rooms a Character has explored
         */
        void set_rooms_explored(int new_rooms);

        /**
         * Getter function for the total amount of damage a Character has dealt
         * @return total damage dealt
         */
        int get_damage_dealt();

        /**
         * Setter function for the total amount of damage a Character has dealt
         */
        void set_damage_dealt(int new_damage);

        /**
         * Getter function for the number of Monsters a Character has defeated
         * @return number of Monsters defeated
         */
        int get_monsters_defeated();

        /**
         * Setter function for the number of Monsters a Character has defeated
         */
        void set_monsters_defeated(int new_monsters);

        /**
         * Getter function for the number of Dungeons a Character has explored
         * @return number of Dungeons explored
         */
        int get_dungeons_explored();

        /**
         * Setter function for the number of Dungeons a Character has explored
         */
        void set_dungeons_explored(int new_dungeons);

        /**
        * Function that prints out a Character's final stats
        */
        void display_final_stats();

        /**
        * Function that handles using an Item
        */
        void use_item(Item item, int index);
    private:
        string name;
        int level;
        int max_health;
        int curr_health;
        int attack;
        int max_xp;
        int curr_xp;
        vector<Item> inventory;
        int gold;

        int rooms_explored;
        int damage_dealt;
        int monsters_defeated;
        int dungeons_explored;
};

#endif