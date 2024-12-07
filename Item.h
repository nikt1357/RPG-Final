#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
using namespace std;

/**
 * Item class that represents things a Character can have and use
 */
class Item 
{
    public:
        /**
         * Constructs an Item with stats for a given type (Weapon, Comsumable, etc.)
         */
        Item(string name, string type, int cost);

        /**
         * Getter function for an Item's name
         * @return the name
         */
        string get_name();

        /**
         * Getter function for an Items's type
         * @return the type
         */
        string get_type();

        /**
         * Getter function for an Item's cost
         * @return the cost
         */
        int get_cost();
    private:
        string type;
        string name;
        int cost;
};

#endif