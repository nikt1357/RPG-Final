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
            bool cont_2 = true;
            while (cont_2) {
                cout << "\nInventory:" << endl;
                player.display_inventory();
                cout << "\n1. Select an Item\n2. Return to Menu" << endl;
                cin >> in;
                if (in.compare("1") == 0)
                {
                    bool cont_3 = true;
                    while (cont_3) {
                        int count = 0;
                        if (player.get_inventory().size() > 0) {
                            for (Item i : player.get_inventory())
                            {
                                cout << "\nInventory:" << endl;
                                cout << (count + 1) << ". " << i.get_name() << endl;
                                count++;
                            }
                        }
                        else
                        {
                            cout << "\nYour inventory is currently empty!" << endl;
                        }
                        cout << "f. Finish" << endl;
                        cin >> in;

                        if (in.compare("f") == 0)
                        {
                            cont_3 = false;
                        }
                        else 
                        { 
                            int index = stoi(in) - 1;
                            if (index < player.get_inventory().size())
                            {
                                bool cont_4 = true;
                                while (cont_4) {
                                    Item i = player.get_inventory().at(index);
                                    cout << "\nName: " << i.get_name() << endl;
                                    cout << "Type: " << i.get_type() << endl;
                                    cout << "Cost: " << i.get_cost() << endl;
                                    cout << "1. Use\n2. Sell\n3. Back to Inventory" << endl;
                                    cin >> in;

                                    if (in.compare("1") == 0)
                                    {
                                        if (i.get_type().compare("Weapon Upgrade") == 0)
                                        {
                                            player.set_attack(player.get_attack() + 2);
                                            cout << "\nYour attack power has been increased!" << endl;
                                        }
                                        else if (i.get_type().compare("Heal") == 0)
                                        {
                                            if (player.get_curr_health() + 10 > player.get_max_health())
                                            {
                                                player.set_curr_health(player.get_max_health());
                                            }
                                            else
                                            {
                                                player.set_curr_health(player.get_curr_health() + 10);
                                            }
                                            cout << "\nYou have been healed!" << endl;
                                        }
                                        else if (i.get_type().compare("Health Upgrade") == 0)
                                        {
                                            player.set_max_health(player.get_max_health() + 2);
                                            cout << "\nYour maximum health has been increased!" << endl;
                                        }
                                        player.remove_from_inventory(index);
                                        cont_4 = false;
                                    }
                                    else if (in.compare("2") == 0)
                                    {
                                        player.set_gold(player.get_gold() + i.get_cost());
                                        cout << "\nYou have sold your " << i.get_name() << " for " << i.get_cost() << " gold!" << endl;
                                        player.remove_from_inventory(index);
                                        cont_4 = false;
                                    }
                                    else if (in.compare("3") == 0)
                                    {
                                        cont_4 = false;
                                    }
                                    else
                                    {
                                        cout << "\nI didn't quite catch that?" << endl;
                                    }
                                }
                            }
                            else
                            {
                                cout << "\nPlease choose a valid item..." << endl;
                            }
                        }
                    }
                }
                else if (in.compare("2") == 0)
                {
                    cont_2 = false;
                }
                else
                {
                    cout << "\nI didn't quite catch that?" << endl;
                }
            }
        }
        else if (in.compare("3") == 0)
        {
            Dungeon dungeon = Dungeon();
            /* TO DO: ACTUAL DUNGEON CRAWL */
            cout << "\nNumber of rooms: " << dungeon.get_rooms() << endl;
            /* TO DO: STATS AFTER DUNGEON (GOLD EARNED, MONSTERS KILLED, ETC.) */
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