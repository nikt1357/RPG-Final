#include <string>
#include <vector>
#include "Item.h"
using namespace std;

Item::Item(string item_name, string item_type, int item_cost)
{
    name = item_name;
    type = item_type;
    cost = item_cost;
}

string Item::get_name()
{
    return name;
}

string Item::get_type()
{
    return type;
}

int Item::get_cost()
{
    return cost;
}