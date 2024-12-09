#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Monster.h"
using namespace std;

Monster::Monster(int level)
{
    srand(time(0));
    max_health = (level * 2);
    curr_health = max_health;
    attack = (level + 2);

    int min_xp = (level * 4);
    int max_xp = (level * 8);
    xp_reward = min_xp + rand() % (max_xp - min_xp + 1);

    int min_gold = (level * 6);
    int max_gold = (level * 10);
    gold_reward = min_gold + rand() % (max_gold - min_gold + 1);
}

int Monster::get_max_health()
{
    return max_health;
}

int Monster::get_curr_health()
{
    return curr_health;
}

void Monster::set_curr_health(int new_health)
{
    curr_health = new_health;
}

int Monster::get_attack()
{
    return attack;
}

int Monster::get_xp_reward()
{
    return xp_reward;
}

int Monster::get_gold_reward()
{
    return gold_reward;
}
