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
    int min_level = (player_level - 1);
    int max_level = (player_level + 1);
    int monster_level = min_level + rand() % (min_level + max_level + 1);
    
    return Monster(monster_level);
}

Item Dungeon::generate_treasure()
{


    /* TO DO*/
    return Item("Iron Sword", "Weapon", 10);

}

int Dungeon::generate_num_rooms()
{
    rooms = 1 + (rand() % 6);
    return rooms;
}