//
// Created by nic on 4/22/19.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef PROGRAM2_MANSION_H
#define PROGRAM2_MANSION_H


class Mansion {
public:
    Mansion(char*, int);
    int get_number_of_suspects();
    string findRoom(string);
private:
    int readInfo(ifstream&);
    string rooms[20];
    string rooms_hint[20];
    int no_rooms;
    int no_suspects;
};


#endif //PROGRAM2_MANSION_H
