#include <string>
#include <vector>
#include <iostream>
#include "Character.h"
#include "Dungeon.h"
#include "Item.h"
#include "Monster.h"
using namespace std;

int main()
{
    cout << "Welcome traveler, what is your name?" << endl;
    string name;
    cin >> name;
    cout << "\nYour name is... " << name << " is this correct?" << endl;
    string in;
    cout << "1. Yes\n2. No" << endl;
    cin >> in;

    while (in.compare("1") != 0)
    {
        cout << "\nWhat is your name traveler?" << endl;
        cin >> name;
        cout << "\nYour name is... " << name << " is this correct?" << endl;
        cout << "1. Yes\n2. No" << endl;
        cin >> in;
    }
 
    cout << "\n" << name << ", your journey begins now." << endl;
    Character player = Character(name);
    bool cont = true;

    while (cont)
    {
        cout << "\n" << player.get_name() << ", what will you do?" << endl;
        cout << "1. View your stats\n2. View your inventory\n3. Enter a dungeon\n4. Quit" << endl;
        cin >> in;
        if (in.compare("1") == 0)
        {
            player.display_stats();
        }
        else if (in.compare("2") == 0)
        {
            cout << "\nGold: " << player.get_gold() << endl;
            /* TO DO: ITERATE THROUGH INVENTORY */
            /* TO DO: SELLING MECHANIC */
        }
        else if (in.compare("3") == 0)
        {
            Dungeon dungeon = Dungeon();
            /* TO DO: ACTUAL DUNGEON CRAWL */
            cout << "\nNumber of rooms: " << dungeon.get_rooms() << endl;
            /* TO DO: STATS AFTER DUNGEON (GOLD EARNED, MONSTERS KILLED, ETC. */
        }
        else if (in.compare("4") == 0)
        {
            cont = false;
        }
        else
        {
            cout << "\nI didn't quite catch that?" << endl;
        }
    }

    cout << "\nFarewell traveler..." << endl;

}