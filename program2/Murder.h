//
// Created by nic on 4/22/19.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef PROGRAM2_MURDER_H
#define PROGRAM2_MURDER_H

class Murder {
public:
    Murder(char*);
    bool weapon_matches(string, Weapons);
    bool room_matches(string, Mansion);
    string whereCommitted();
    string withWhat();

private:
    void readInfo(ifstream&);
    string where;
    string what;

};


#endif //PROGRAM2_MURDER_H
