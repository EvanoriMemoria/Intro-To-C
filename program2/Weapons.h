//
// Created by nic on 4/22/19.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef PROGRAM2_WEAPONS_H
#define PROGRAM2_WEAPONS_H


class Weapons {
public:
    Weapons(char*);
    string findWeapon(string);
private:
    int readInfo(ifstream&);
    string weaps[20];
    string weaps_hint[20];
    int no_weaps;
};


#endif //PROGRAM2_WEAPONS_H
