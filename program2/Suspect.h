//
// Created by nic on 4/22/19.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef PROGRAM2_SUSPECT_H
#define PROGRAM2_SUSPECT_H


class Suspect {
public:
    Suspect();
    void readSuspect(ifstream&);
    string getName();
    string get_room_clue();
    string get_weapon_clue();

private:
    string name;
    string weapon_clue;
    string room_clue;

};


#endif //PROGRAM2_SUSPECT_H
