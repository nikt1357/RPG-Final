#include <string>
#include <vector>
#include "Item.h"
#include "Character.h"
using namespace std;

Character::Character(string char_name) 
{
    name = char_name;
    level = 1;
    health = 15;
    attack = 5;
    xp = 0;
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

int Character::get_health()
{
    return health;
}

void Character::set_health(int new_health)
{
    health = new_health;
}

int Character::get_attack()
{
    return attack;
}

void Character::set_attack(int new_attack)
{
    attack = new_attack;
}

int Character::get_xp()
{
    return xp;
}

void Character::set_xp(int new_xp)
{
    xp = new_xp;
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
