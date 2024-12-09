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


    /* TO DO*/
    return Item("Iron Sword", "Weapon", 10);

}

int Dungeon::generate_num_rooms()
{
    rooms = 1 + (rand() % 5);
    return rooms;
}