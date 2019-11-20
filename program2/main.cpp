#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#include "Mansion.h"
#include "Suspect.h"
#include "Weapons.h"
#include "Murder.h"

int main(int argc, char** argv) {
    Suspect suspects[10];
    ifstream sinfile;
    sinfile.open("suspects.txt");

    int i = 0;
    while(!sinfile.eof()) {
        suspects[i++].readSuspect(sinfile);
    }

    sinfile.close();
    int number_suspects = i;

    Murder murder("murder.txt");
    Mansion mansion("mansion.txt", number_suspects);
    Weapons weapons("weaponclues.txt");

    string weapon_clue, room_clue;
    for (int j = 0; j < mansion.get_number_of_suspects(); j++) {
        weapon_clue = suspects[j].get_weapon_clue();
        room_clue = suspects[j].get_room_clue();
        if(murder.weapon_matches(weapon_clue, weapons) &&
            murder.room_matches(room_clue, mansion)) {

            cout << "The murder was committed by " <<
                suspects[j].getName() << " in the " <<
                murder.whereCommitted() << " with a " <<
                murder.withWhat() << endl;
            break;
        }
    }

    return 0;
}