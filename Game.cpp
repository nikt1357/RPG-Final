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
                        cout << "e. Exit" << endl;
                        cin >> in;

                        if (in.compare("e") == 0)
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
                                        player.use_item(i, index);
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
            if (dungeon.get_rooms() == 1)
            {
                cout << "\nYou are now entering a Dungeon, there is " << dungeon.get_rooms() << " room before you reach the end..." << endl;
            }
            else
            {
                cout << "\nYou are now entering a Dungeon, there are " << dungeon.get_rooms() << " rooms before you reach the end..." << endl;
            }
            bool cont_2 = true;
            while (cont_2)
            {
                for (int room = 1; room <= dungeon.get_rooms(); room++)
                {
                    bool combat = true;
                    int encounter = 0 + rand() % (0 + 100 + 1);
                    if (encounter <= 30)
                    {
                        cout << "\nThis room appears to be empty..." << endl;
                    }
                    else
                    {
                        cout << "\nYou encounter a Monster!" << endl;
                        Monster monster = dungeon.generate_monster(player.get_level());

                        while ((monster.get_curr_health() > 0 and player.get_curr_health() > 0) and combat)
                        {
                            cout << "\n" << player.get_name() << "'s health: " << player.get_curr_health() << "/" << player.get_max_health()
                                << "\nMonster's health: " << monster.get_curr_health() << "/" << monster.get_max_health() << endl;
                            
                            /* Player's Turn */
                            bool cont_3 = true;
                            string in;
                            while (cont_3)
                            {
                                cout << "\nIt is your turn, what will you do?" << endl;
                                cout << "1. Attack\n2. Flee\n3. Inventory" << endl;
                                cin >> in;
                                if (in.compare("1") == 0)
                                {
                                    monster.set_curr_health(monster.get_curr_health() - player.get_attack());
                                    cout << "\nYou attack the Monster for " << player.get_attack() << " damage!" << endl;
                                    player.set_damage_dealt(player.get_damage_dealt() + player.get_attack());
                                    cont_3 = false;
                                }
                                else if (in.compare("2") == 0)
                                {
                                    cont_3 = false;
                                    combat = false;
                                }
                                else if (in.compare("3") == 0)
                                {
                                    cout << "\nInventory stuff" << endl;
                                    cont_3 = false;                                 
                                }
                                else
                                {
                                    cout << "\nI didn't quite catch that?" << endl;
                                }
                            }

                            /* Monster's Turn */
                            if (monster.get_curr_health() > 0)
                            {
                                player.set_curr_health(player.get_curr_health() - monster.get_attack());
                                cout << "\nThe Monster attacks you for " << monster.get_attack() << " damage!" << endl;
                            }
                        }

                        if (combat)
                        {
                            if (player.get_curr_health() > 0)
                            {
                                int gold = monster.get_gold_reward();
                                int xp = monster.get_xp_reward();
                                cout << "\nYou have defeated the Monster!" << endl;
                                cout << "You gained " << gold << " gold!" << endl;
                                cout << "You gained " << xp << " xp!" << endl;
                                player.set_gold(player.get_gold() + gold);

                                if (player.get_curr_xp() + xp >= player.get_max_xp())
                                {
                                    int new_xp = (player.get_curr_xp() + xp) - player.get_max_xp();
                                    player.set_level(player.get_level() + 1);
                                    player.set_max_xp(player.get_max_xp() + 5);
                                    player.set_curr_xp(new_xp);
                                    player.set_max_health(player.get_max_health() + 2);
                                    player.set_curr_health(player.get_curr_health() + 2);
                                    cout << "\nLevel Up! Your stats have been increased!" << endl;
                                }

                                player.set_monsters_defeated(player.get_monsters_defeated() + 1);
                            }
                            else if (monster.get_curr_health() > 0)
                            {
                                cout << "\nThe Monster has bested you, you have met your end in the Dungeon..." << endl;
                                player.display_final_stats();
                                return 0;
                            }
                        }
                        else
                        {
                            cout << "\nYou have fleed the Dungeon, abandoning any potential treasure..." << endl;
                            cont_2 = false;
                            break;
                        }
                    }
                    player.set_rooms_explored(player.get_rooms_explored() + 1);
                    if (combat)
                    {
                        cout << "\nYou proceed to the next room..." << endl;
                    }
                    else
                    {
                        cont_2 = false;
                        break;
                    }
                }
                if (cont_2)
                {
                    cout << "\nYou have reached the end of the Dungeon, in front of you there is a treasure chest..." << endl;
                    cout << "Inside you find: " << endl;

                    /* Generate a random item */
                    /* Add to inventory or leave it */

                    player.set_dungeons_explored(player.get_dungeons_explored() + 1);
                    cont_2 = false;
                }
            }
            /* TO DO: STATS AFTER DUNGEON (GOLD EARNED, MONSTERS KILLED, HEALTH REMAINING, ETC.) */
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
    player.display_final_stats();

}