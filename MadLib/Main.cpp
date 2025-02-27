#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct Entry {
    string type;
    string input;
};

void fixMistakes(Entry entries[], int size) {
    char choice;
    do {
        cout << "Do you want to fix any mistakes? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            int entryNum;
            cout << "Which entry would you like to fix? (1-" << size << "): ";
            cin >> entryNum;

            if (entryNum >= 1 && entryNum <= size) {
                cout << "Enter a " << entries[entryNum - 1].type << ": ";
                cin >> entries[entryNum - 1].input;
            }
        }
    } while (choice == 'y' || choice == 'Y');
}

void displayStory(Entry entries[], int size) {
    cout << "\nYour Mad Lib:\n";
    cout << "There once was a " << entries[0].input << " named " << entries[1].input << ". " << "They went on a journey to find " << entries[2].input
        << ".\n" << "The journey was " << entries[3].input << " and " << entries[4].input <<".\n"
        << "But with determination, discipline, and guts they found themselves in front of a " << entries[5].input << ".\n" 
        << entries[6].input << " they left and returned home forgeting why they bothered to leave home in the first place.\n";
}

int main() {
    Entry entries[] = {
        {"Creature or animal", ""},
        {"Name", ""},
        {"Famous place or person", ""},
        {"Adjective", ""},
        {"Adjective", ""},
        {"Less famous place or person", ""},
        {"Adjective", ""}
    };

    int size = sizeof(entries) / sizeof(entries[0]);

    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". Enter a " << entries[i].type << ": ";
        cin >> entries[i].input;
    }

    fixMistakes(entries, size);

    displayStory(entries, size);

    
    return 0;
}
