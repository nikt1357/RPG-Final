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
         * Getter function for a Monster's maximum health
         * @return the max health
         */
        int get_max_health();

        /**
         * Getter function for a Monster's current health
         * @return the current health
         */
        int get_curr_health();

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
         * Getter function for a Monster's gold reward
         * @return gold reward
         */
        int get_gold_reward();

        /**
         * Function that handles fighting the character
         */
        void fight();
    private:
        int max_health;
        int curr_health;
        int attack;
        int xp_reward;
        int gold_reward;
};

#endif