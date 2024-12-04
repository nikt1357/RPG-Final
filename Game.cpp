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
    string in;
    cin >> in;
    cout << "Your name is... " << in << " is this correct?" << endl;
    cout << "1. Yes \t\t 2. No" << endl;
    return 0;
}