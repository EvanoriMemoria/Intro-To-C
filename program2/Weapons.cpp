//
// Created by nic on 4/22/19.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Weapons.h"

Weapons::Weapons(char* filename) {
    ifstream infile;
    int i = 0;
    infile.open(filename);
    no_weaps = readInfo(infile);
    infile.close();
    return;
}

int Weapons::readInfo(ifstream& infile) {
    int i = 0;
    while(infile >> weaps[i] >> weaps_hint[i]) {
        i++;
    }
    return i;
}

string Weapons::findWeapon(string weaps_clue) {
    for (int i = 0; i < no_weaps; ++i) {
        if(weaps_hint[i] == weaps_clue) {
            return weaps[i];
        }
    }
    cerr << "ERROR: weapon not found\n";
    exit(1);
}