#include <iostream>
using namespace std;

struct character {
    char* name = "unknown";
    int health = 0;
    int armor = 0;
};


void take_damage (char* name, int* health, int* armor, int damage) {
    cout << name << " took damage: -" << damage << endl;
    *armor -= damage;
    if (*armor < 0) {
        *health += *armor;
        *armor = 0;
    }
}

int main()
{
    char* names[10];
    int health[10];
    int armor [10];

    

}