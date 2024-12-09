#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Dungeon.h"
#include "Item.h"
#include "Monster.h"
using namespace std;

int main()
{
    srand(time(0));
    system("Color 07");
    /* Intro, entering in your name and creating your Character */
    cout << "Welcome traveler, what is your name?" << endl;
    string name;
    cin >> name;
    Sleep(1000);
    cout << "\nYour name is... " << name << " is this correct?" << endl;
    string in;
    cout << "1. Yes\n2. No" << endl;
    cin >> in;

    /* Making sure you entered the name you want */
    while (in.compare("1") != 0)
    {
        cout << "\nWhat is your name traveler?" << endl;
        cin >> name;
        Sleep(1000);
        cout << "\nYour name is... " << name << " is this correct?" << endl;
        cout << "1. Yes\n2. No" << endl;
        cin >> in;
    }
 
    Sleep(1000);
    system("cls");
    cout << name << ", your journey begins now." << endl;
    Character player = Character(name);
    bool cont = true;

    /* Main Menu handling while loop, keep going until player chooses to quit the game */
    while (cont)
    {
        cout << "\nWhat will you do?" << endl;
        cout << "1. View your stats\n2. View your inventory\n3. Enter a dungeon\n4. Quit" << endl;
        cin >> in;

        /* View stats */
        if (in.compare("1") == 0)
        {
            system("cls");
            player.display_stats();
        }
        /* Handles inventory management */
        else if (in.compare("2") == 0)
        {          
            /* Inventory menu, keep looping until player chooses to return to the main menu or no items in inventory */
            bool cont_2 = true;
            while (cont_2) {
                system("cls");
                if (player.get_inventory().size() > 0)
                {
                    cout << "Inventory:" << endl;
                    player.display_inventory();
                    cout << "\n1. Select an Item\n2. Return to Menu" << endl;
                    cin >> in;
                }
                else
                {
                    cout << "Your inventory is currently empty!" << endl;
                    break;
                }
                
                /* Selecting an item */
                if (in.compare("1") == 0)
                {
                    bool cont_3 = true;
                    while (cont_3) {
                        system("cls");
                        int count = 0;
                        if (player.get_inventory().size() > 0) {
                            cout << "Select an Item:" << endl;
                            for (Item i : player.get_inventory())
                            {
                                cout << (count + 1) << ". " << i.get_name() << endl;
                                count++;
                            }
                            cout << "e. Exit" << endl;
                            cin >> in;
                        }
                        else
                        {
                            cout << "Your inventory is currently empty!" << endl;
                            cont_3 = false;
                            break;
                        }

                        if (in.compare("e") == 0)
                        {
                            cont_3 = false;
                        }
                        else 
                        { 
                            /* Item has been selected, what will you do with it? */
                            int index = stoi(in) - 1;
                            if (index < player.get_inventory().size())
                            {
                                bool cont_4 = true;
                                while (cont_4) {
                                    system("cls");
                                    Item i = player.get_inventory().at(index);
                                    cout << "Name: " << i.get_name() << endl;
                                    cout << "Type: " << i.get_type() << endl;
                                    cout << "Cost: " << i.get_cost() << endl;
                                    cout << "1. Use\n2. Sell\n3. Back to Inventory" << endl;
                                    cin >> in;

                                    /* Use the item */
                                    if (in.compare("1") == 0)
                                    {
                                        player.use_item(i, index);
                                        cont_4 = false;
                                    }
                                    /* Sell the item */
                                    else if (in.compare("2") == 0)
                                    {
                                        player.set_gold(player.get_gold() + i.get_cost());
                                        cout << "\nYou have sold your " << i.get_name() << " for " << i.get_cost() << " gold!" << endl;
                                        player.remove_from_inventory(index);
                                        cont_4 = false;
                                    }
                                    /* Back to the main inventory menu */
                                    else if (in.compare("3") == 0)
                                    {
                                        cont_4 = false;
                                    }
                                    /* Handles invalid menu choices */
                                    else
                                    {
                                        Sleep(500);
                                        cout << "\nI didn't quite catch that?" << endl;
                                        Sleep(1500);
                                    }
                                }
                            }
                            else
                            {
                                Sleep(500);
                                cout << "\nPlease choose a valid item..." << endl;
                                Sleep(1500);
                            }
                        }
                    }
                }
                /* Return to main menu */
                else if (in.compare("2") == 0)
                {
                    cont_2 = false;
                }
                /* Handles invalid menu choices */
                else
                {
                    Sleep(500);
                    cout << "\nI didn't quite catch that?" << endl;
                    Sleep(1500);
                }
            }
        }
        /* Handles the dungeon crawl */
        else if (in.compare("3") == 0)
        {
            /* Beginning of dungeon crawl, tells player how many rooms are in a randomly generated dungeon */
            system("cls");
            Sleep(1000);
            Dungeon dungeon = Dungeon();
            if (dungeon.get_rooms() == 1)
            {
                cout << "You are now entering a Dungeon, there is " << dungeon.get_rooms() << " room before you reach the end..." << endl;
            }
            else
            {
                cout << "You are now entering a Dungeon, there are " << dungeon.get_rooms() << " rooms before you reach the end..." << endl;
            }
            Sleep(2500);
            bool cont_2 = true;

            /* While loop in charge of keeping track of if a player flees the dungeon */
            while (cont_2)
            {
                /* For each room in the dungeon randomly generate an encounter */
                for (int room = 1; room <= dungeon.get_rooms(); room++)
                {
                    bool combat = true;
                    int encounter = 0 + rand() % (0 + 100 + 1);
                    /* Empty room */
                    if (encounter <= 30)
                    {
                        Sleep(1000);
                        system("cls");
                        cout << "This room appears to be empty..." << endl;
                        Sleep(2000);
                    }
                    /* Monster encounter, generate a randomly leveled monster and begin combat */
                    else
                    {
                        Sleep(1000);
                        system("cls");
                        cout << "You encounter a Monster!" << endl;
                        Sleep(2000);
                        Monster monster = dungeon.generate_monster(player.get_level());

                        /* Continue combat until player flees or one of the combatants is dead */
                        while ((monster.get_curr_health() > 0 and player.get_curr_health() > 0) and combat)
                        {
                            /* Print player and monster health */
                            Sleep(1000);
                            cout << "\n" << player.get_name() << "'s health: " << player.get_curr_health() << "/" << player.get_max_health()
                                << "\nMonster's health: " << monster.get_curr_health() << "/" << monster.get_max_health() << endl;

                            /* Player's Turn */
                            bool cont_3 = true;
                            string in;
                            /* Player's turn menu */
                            while (cont_3)
                            {
                                Sleep(1000);
                                cout << "\nIt is your turn, what will you do?" << endl;
                                cout << "1. Attack\n2. Flee" << endl;
                                cin >> in;
                                /* Player attacks monster */
                                if (in.compare("1") == 0)
                                {
                                    Sleep(1000);
                                    monster.set_curr_health(monster.get_curr_health() - player.get_attack());
                                    cout << "\nYou attack the Monster for " << player.get_attack() << " damage!" << endl;
                                    player.set_damage_dealt(player.get_damage_dealt() + player.get_attack());
                                    cont_3 = false;
                                    Sleep(1000);
                                }
                                /* Player flees the dungeon */
                                else if (in.compare("2") == 0)
                                {
                                    cont_3 = false;
                                    combat = false;
                                }
                                /* Handles invalid menu choices */
                                else
                                {
                                    Sleep(500);
                                    cout << "\nI didn't quite catch that?" << endl;
                                    Sleep(1500);
                                }
                            }

                            /* Monster's Turn, always attacks */
                            if (combat and monster.get_curr_health() > 0)
                            {
                                Sleep(1000);
                                player.set_curr_health(player.get_curr_health() - monster.get_attack());                               
                                cout << "\nThe Monster attacks you for " << monster.get_attack() << " damage!" << endl;
                                Sleep(2000);
                            }
                        }

                        /* Combat has ended, someone is dead */
                        if (combat)
                        {
                            /* Player survived, get gold and xp from defeated monster */
                            if (player.get_curr_health() > 0)
                            {
                                system("cls");
                                int gold = monster.get_gold_reward();
                                int xp = monster.get_xp_reward();
                                Sleep(750);
                                cout << "You have defeated the Monster!" << endl;
                                Sleep(750);
                                cout << "You gained " << gold << " gold!" << endl;
                                Sleep(750);
                                cout << "You gained " << xp << " xp!" << endl;
                                player.set_gold(player.get_gold() + gold);

                                /* Check to see if player leveled up */
                                if (player.get_curr_xp() + xp >= player.get_max_xp())
                                {
                                    int new_xp = (player.get_curr_xp() + xp) - player.get_max_xp();
                                    player.set_level(player.get_level() + 1);
                                    player.set_max_xp(player.get_max_xp() + 5);
                                    player.set_curr_xp(new_xp);
                                    player.set_max_health(player.get_max_health() + 2);
                                    player.set_curr_health(player.get_curr_health() + 2);
                                    player.set_attack(player.get_attack() + 2);
                                    Sleep(750);
                                    cout << "\nLevel Up! Your stats have been increased!" << endl;
                                }
                                else
                                {
                                    player.set_curr_xp(player.get_curr_xp() + xp);
                                }

                                Sleep(2000);
                                player.set_monsters_defeated(player.get_monsters_defeated() + 1);
                            }
                            /* Player has died, game over man */
                            else if (monster.get_curr_health() > 0)
                            {
                                system("cls");
                                cout << "\nThe Monster has bested you, you have met your end in the Dungeon..." << endl;
                                Sleep(500);
                                player.display_final_stats();
                                Sleep(2000);
                                cout << "\n\nFarewell traveler..." << endl;
                                return 0;
                            }
                        }
                        /* Player fled the dungeon, coward */
                        else
                        {
                            cout << "You have fled the Dungeon, abandoning any potential treasure..." << endl;
                            cont_2 = false;
                            Sleep(2000);
                            break;
                        }
                    }

                    /* Room has been explored, keep on movin */
                    player.set_rooms_explored(player.get_rooms_explored() + 1);
                    if (combat)
                    {
                        Sleep(1000);
                        cout << "You proceed to the next room..." << endl;
                        Sleep(2000);
                    }
                    else
                    {
                        cont_2 = false;
                        break;
                    }
                }

                /* End of the dungeon has been reached, treasure time */
                if (cont_2)
                {
                    system("cls");
                    Item treasure = dungeon.generate_treasure();
                    bool cont_3 = true;
                    cout << "You have reached the end of the Dungeon, in front of you there is a treasure chest..." << endl;
                    Sleep(750);
                    cout << "Inside you find: " << treasure.get_name() << endl;
                    Sleep(1000);
                    cout << "1. Take it\n2. Leave it" << endl;
                    cin >> in;

                    /* You can't leave the dungeon until the treasure is dealt with */
                    while (cont_3)
                    {
                        /* Take the treasure */
                        if (in.compare("1") == 0)
                        {
                            Sleep(500);
                            int try_to_take = player.add_to_inventory(treasure);
                            /* Added to inventory no problem */
                            if (try_to_take == 0)
                            {
                                cout << "\nThe treasure has been added to your inventory!" << endl;
                                cont_3 = false;
                                Sleep(1000);
                                cout << "\nYou now exit the Dungeon..." << endl;
                                Sleep(1500);
                            }
                            /* Inventory is full, something has to go */
                            else
                            {
                                bool cont_4 = true;
                                while (cont_4)
                                {
                                    cout << "\nYour inventory is full, choose an Item to replace with your new treasure:" << endl;
                                    int count = 0;
                                    for (Item i : player.get_inventory())
                                    {
                                        cout << (count + 1) << ". " << i.get_name() << endl;
                                        count++;
                                    }
                                    cin >> in;

                                    int index = stoi(in) - 1;
                                    if (index < player.get_inventory().size())
                                    {
                                        Sleep(1000);
                                        player.remove_from_inventory(index);
                                        int try_to_take = player.add_to_inventory(treasure);
                                        cout << "\nThe treasure has been added to your inventory!" << endl;
                                        cont_3 = false;
                                        Sleep(1000);
                                        cout << "\nYou now exit the Dungeon..." << endl;
                                        Sleep(1500);
                                    }
                                    else
                                    {
                                        Sleep(1000);
                                        cout << "\nPlease choose a valid item..." << endl;
                                        Sleep(1000);
                                    }
                                }
                            }
                        }
                        /* Leave the treasure */
                        else if (in.compare("2") == 0)
                        {
                            Sleep(500);
                            cout << "\nYou choose to leave the treasure and exit the Dungeon..." << endl;
                            Sleep(1500);
                            cont_3 = false;
                        }
                        /* Handles invalid menu choice */
                        else
                        {
                            Sleep(500);
                            cout << "\nI didn't quite catch that?" << endl;
                            Sleep(1500);
                        }
                    }

                    player.set_dungeons_explored(player.get_dungeons_explored() + 1);
                    cont_2 = false;
                }
            }
        }
        /* Quit the game, exit the loop */
        else if (in.compare("4") == 0)
        {
            cont = false;
        }
        /* Handles invalid menu choice */
        else
        {
            Sleep(500);
            cout << "\nI didn't quite catch that?" << endl;
            Sleep(1500);
        }
    }

    system("cls");
    player.display_final_stats();
    Sleep(500);
    cout << "\n\nFarewell traveler..." << endl;
    Sleep(2000);

}