#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum RoomType {
    LIVING,
    CHILDREN,
    KITCHEN,
    BATHROOM,
    GUEST
};

enum BuildingType {
    HOUSE,
    GARAGE,
    SHED,
    BATHHOUSE
};

struct Room {
    RoomType type;
    double area;
};

struct Floor {
    int numberOfRooms;
    double ceilingHeight;
    vector<Room> rooms;
};

struct Building {
    BuildingType type;
    double area;
    bool hasStove;
    int numberOfFloors;
    vector<Floor> floors;
};

struct Plot {
    int plotNumber;
    double totalArea;
    vector<Building> buildings;
};

struct Village {
    vector<Plot> plots;
};

void inputVillageData(Village &village) {
    int numberOfPlots;
    cout << "Enter number of plots: ";
    cin >> numberOfPlots;

    village.plots.resize(numberOfPlots);

    for (int i = 0; i < numberOfPlots; i++) {
        Plot &plot = village.plots[i];
        plot.plotNumber = i + 1;

        cout << "Enter summary plot's square " << plot.plotNumber << ": ";
        cin >> plot.totalArea;

        int numberOfBuildings;
        cout << "Enter number of buildings on the plot " << plot.plotNumber << ": ";
        cin >> numberOfBuildings;

        plot.buildings.resize(numberOfBuildings);

        for (int j = 0; j < numberOfBuildings; j++) {
            Building &building = plot.buildings[j];
            int buildingType;
            cout << "Enter building type (0 - House, 1 - Garage, 2 - Barn, 3 - Banya): ";
            cin >> buildingType;
            building.type = (BuildingType)buildingType;

            cout << "Enter square of the building: ";
            cin >> building.area;

            if (building.type == HOUSE || building.type == BATHHOUSE) {
                cout << "Enter ammount of floors: ";
                cin >> building.numberOfFloors;
                building.floors.resize(building.numberOfFloors);

                for (int k = 0; k < building.numberOfFloors; k++) {
                    Floor &floor = building.floors[k];
                    cout << "Enter ammount of rooms on the floor " << (k + 1) << ": ";
                    cin >> floor.numberOfRooms;

                    cout << "Enter the height of ceiling: ";
                    cin >> floor.ceilingHeight;

                    floor.rooms.resize(floor.numberOfRooms);
                    for (int l = 0; l < floor.numberOfRooms; l++) {
                        int roomType;
                        cout << "Enter room type (0 - living, 1 - kidsroom, 2 - kitchen, 3 - bathroom): ";
                        cin >> roomType;
                        floor.rooms[l].type = (RoomType)roomType;

                        cout << "Enter room's square: ";
                        cin >> floor.rooms[l].area;
                    }
                }

                int hasStove;
                cout << "Has Stove? (1 - Y, 0 - N): ";
                cin >> hasStove;
                building.hasStove = (hasStove == 1);
            } else {
                building.numberOfFloors = 0;
                building.floors.clear();
            }
        }
    }
}


int main() {
    Village village;
    inputVillageData(village);

    double totalLandArea = 0;
    double totalBuildingArea = 0;

    for ( int i = 0; i < village.plots.size(); i++) {
        Plot plot = village.plots[i];
        totalLandArea += plot.totalArea;
        for (int j = 0; j < plot.buildings.size(); j++) {
            Building building = plot.buildings[j];
            totalBuildingArea += building.area;
        }
    }

    double occupiedPercentage = (totalBuildingArea / totalLandArea) * 100;
    cout << "Percentage of land, occupied by buildings: " << occupiedPercentage << "%" << endl;

    return 0;
}