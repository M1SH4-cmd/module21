#include <iostream>
using namespace std;

struct character {
    char* name = "unknown";
    int health = 0;
    int armor = 0;
};


void take_damage (character* person, int damage) {
    cout << person -> name << " took damage: -" << damage << endl; 
    person -> armor -= damage;
    if (person -> armor < 0) {
        person -> health += person -> armor;
        person -> armor = 0;
    }
}

int main()
{
    character person = {"PMC Bear ops", .health = 100};
    person.armor = 20;
    take_damage(&person, 30);

    cout << "Health: " << person.health << " Armor: " << person.armor << endl;
    
}