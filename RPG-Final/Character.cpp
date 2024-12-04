#include <string>
#include <vector>
#include "Item.h"
#include "Character.h"
using namespace std;

Character::Character(string char_name) 
{
    name = char_name;
    level = 1;
    max_health = 15;
    curr_health = 15;
    attack = 5;
    max_xp = 20;
    curr_xp = 0;
}

string Character::get_name()
{
    return name;
}

int Character::get_level()
{
    return level;
}

void Character::set_level(int new_level)
{
    level = new_level;
}

int Character::get_max_health()
{
    return max_health;
}

void Character::set_max_health(int new_health)
{
    max_health = new_health;
}

int Character::get_curr_health()
{
    return curr_health;
}

void Character::set_curr_health(int new_health)
{
    curr_health = new_health;
}

int Character::get_attack()
{
    return attack;
}

void Character::set_attack(int new_attack)
{
    attack = new_attack;
}

int Character::get_max_xp()
{
    return max_xp;
}

void Character::set_max_xp(int new_xp)
{
    max_xp = new_xp;
}

int Character::get_curr_xp()
{
    return curr_xp;
}

void Character::set_curr_xp(int new_xp)
{
    curr_xp = new_xp;
}

vector<Item> Character::get_inventory()
{
    return inventory;
}

int Character::add_to_inventory(Item item) 
{
    if (inventory.size() >= 5)
    {
        return 1;
    } 
    inventory.push_back(item);
    return 0;
}

void Character::fight() 
{


    /* TO DO */

    
}
