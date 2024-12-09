#include <string>
#include <vector>
#include "Item.h"
#include "Monster.h"
#include "Dungeon.h"
using namespace std;

Dungeon::Dungeon()
{
    rooms = generate_num_rooms();
}

int Dungeon::get_rooms()
{
    return rooms;
}

Monster Dungeon::generate_monster(int player_level)
{
    int monster_level = 3 + (rand() % player_level);   
    return Monster(monster_level);
}

Item Dungeon::generate_treasure()
{
    int type = 1 + rand() % (1 + 3 + 1);
    if (type == 1)
    {
        int weapon_upgrade = 1 + rand() % (1 + 3 + 1);
        if (weapon_upgrade == 1)
        {
            return Item("Scrap Metal", "Weapon Upgrade", 10);
        }
        else if (weapon_upgrade == 2)
        {
            return Item("Whetstone", "Weapon Upgrade", 15);
        }
        else if (weapon_upgrade == 3)
        {
            return Item("Raw Ore", "Weapon Upgrade", 20);
        }
    }
    else if (type == 2)
    {
        return Item("Potion of Healing", "Heal", 20);
    }
    else if (type == 3)
    {
        return Item("Health ELixer", "Health Upgrade", 25);
    }
}

int Dungeon::generate_num_rooms()
{
    rooms = 1 + rand() % (1 + 5 + 1);
    return rooms;
}