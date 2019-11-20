//
// Created by nic on 4/22/19.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Mansion.h"

Mansion::Mansion(char* filename, int nopeps) {
    no_suspects = nopeps;

    ifstream infile;
    infile.open(filename);
    no_rooms = readInfo(infile);
    return;
}

int Mansion::readInfo(ifstream & infile) {
    int i = 0;
    while(infile >> rooms[i] >> rooms_hint[i]) {
        i++;
    }
    return i;
}

int Mansion::get_number_of_suspects() {
    return no_suspects;
}

string Mansion::findRoom(string room_clue) {
    for(int i = 0; i < no_rooms; ++i) {
        if(rooms_hint[i] == room_clue) {
            return rooms[i];
        }
    }
    cerr << "ERROR: room not found\n";
    exit(1);
}