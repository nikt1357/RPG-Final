#include <string>
#include <vector>
#include "Item.h"
#include "Monster.h"
#include "Dungeon.h"
using namespace std;

Dungeon::Dungeon()
{
    /* TO DO */
}

int Dungeon::get_rooms()
{
    /*return rooms; */
    return 1;
}

vector<Monster> Dungeon::get_possible_monsters() 
{
    return possible_monsters;
}

vector<Item> Dungeon::get_possible_items()
{
    return possible_items;
}

Monster Dungeon::generate_monster(vector<Monster> monsters)
{


    /* TO DO*/
    return Monster(1);
    

}

Item Dungeon::generate_item(vector<Item> items)
{


    /* TO DO*/
    return Item("Item");

}