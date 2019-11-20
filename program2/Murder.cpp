//
// Created by nic on 4/22/19.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#include "Mansion.h"
#include "Weapons.h"
#include "Murder.h"

Murder::Murder(char *filename) {
    ifstream infile;
    infile.open(filename);
    readInfo(infile);
    return;
}

void Murder::readInfo(ifstream& infile){
    int i = 1;
    srand((unsigned)time(0));
    int rn = rand() % 6 + 1;
    while(infile >> what >> where && i != rn) {
        i++;
    }
    return;
}

string Murder::whereCommitted() {
    return where;
}

string Murder::withWhat(){
    return what;
}

bool Murder::weapon_matches(string weapon_clue, Weapons weapons) {
    if(weapons.findWeapon(weapon_clue) == what) {
        return true;
    }
    else {
        return false;
    }
}

bool Murder::room_matches(string room_clue, Mansion mansion) {
    if(mansion.findRoom(room_clue) == where) {
        return true;
    }
    else {
        return false;
    }
}