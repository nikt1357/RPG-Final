#include <string>
#include <vector>
#include <iostream>
#include "Item.h"
#include "Character.h"
using namespace std;

Character::Character(string char_name) 
{
    name = char_name;
    level = 3;
    max_health = 25;
    curr_health = 25;
    attack = 7;
    max_xp = 30;
    curr_xp = 0;
    gold = 0;

    rooms_explored = 0;
    damage_dealt = 0;
    monsters_defeated = 0;
    dungeons_explored = 0;

    /* TEMP */
    inventory.push_back(Item("Scrap Metal", "Weapon Upgrade", 10));


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

void Character::remove_from_inventory(int index)
{
    inventory.erase(inventory.begin() + index);
}

void Character::fight() 
{


    /* TO DO */

    
}

void Character::display_stats()
{
    cout << "\nName: " << get_name() << endl;
    cout << "Level: " << get_level() << endl;
    cout << "Health: " << get_curr_health() << "/" << get_max_health() << endl;
    cout << "Attack Power: " << get_attack() << endl;
    cout << "Experience Points: " << get_curr_xp() << "/" << get_max_xp() << endl;
    cout << "Current Gold: " << get_gold() << endl;
}

void Character::display_inventory()
{
    for (Item i : inventory)
    {

        cout << i.get_name() << endl;
    }
}

int Character::get_gold()
{
    return gold;
}

void Character::set_gold(int new_gold)
{
    gold = new_gold;
}

int Character::get_rooms_explored()
{
    return rooms_explored;
}

void Character::set_rooms_explored(int new_rooms)
{
    rooms_explored = new_rooms;
}

int Character::get_damage_dealt()
{
    return damage_dealt;
}

void Character::set_damage_dealt(int new_damage)
{
    damage_dealt = new_damage;
}

int Character::get_monsters_defeated()
{
    return monsters_defeated;
}

void Character::set_monsters_defeated(int new_monsters)
{
    monsters_defeated = new_monsters;
}

int Character::get_dungeons_explored()
{
    return dungeons_explored;
}

void Character::set_dungeons_explored(int new_dungeons)
{
    dungeons_explored = new_dungeons;
}
