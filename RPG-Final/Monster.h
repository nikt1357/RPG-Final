#ifndef MONSTER_H
#define MONSTER_H

#include <string>
using namespace std;

/**
 * Monster class that represents any Monster the Character can encounter and fight
 */
class Monster
{
    public:
        /**
         * Constructs a Monster with random stats
         */
        Monster(int level);

        /**
         * Getter function for a Monster's type
         * @return the type
         */
        string get_type();

        /**
         * Getter function for a Monster's health
         * @return the health
         */
        int get_health();

        /**
         * Getter function for a Monster's attack points
         * @return attack points
         */
        int get_attack();

        /**
         * Getter function for a Monster's xp reward
         * @return xp reward
         */
        int get_xp_reward();

        /**
         * Function to generate a random item from a Monster's list of possible drops
         * @return a random item
         */
        string generate_item_dropped();

        /**
         * Function that handles fighting the character
         */
        void fight();
    private:
        string type;
        int health;
        int attack;
        int xp_reward;
        vector<string> rewards_possible;
};

#endif