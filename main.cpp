// the header files we need map....
#include <iostream>
#include <map>
#include <array>
#include <list>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Creat function to simulate city data over time
void simulate(const map<string, array<list<string>, 3>>& cities, residentn, facilityn, animaln);
    // Parameters: map of cities, number of intervals

//creat function to print 
void display(const map<string, array<list<string>, 3>>& cities) {
    for (const auto& city: cities) {
        cout << "City" << city.first << ":" << endl;

        cout << "   Resident:" << endl;
        for (const auto&  resident: city.second[0]) {
            cout << "       " << resident << endl;
        }
        cout << "   Animal:" << endl;
        for (const auto&  animal: city.second[1]) {
            cout << "       " << animal << endl;
        }
        cout << "   Facility:" << endl;
        for (const auto&  facility: city.second[2]) {
            cout << "       " << facility << endl;
        }
    }
}

int main() {
// int main function
    // Set up a map to store city data, each city have array of lists for residents, facilities, and animals
    srand(static_cast<unsigned int>(time(0)));
    map<string, array<list<string>, 3>> cities;

    // Set up three array of string to store random resident, facility, animal names
    vector<string> residentn, facilityn, animaln;
    // Open each file and read it into array
    // Close the file
    ifstream re("resident.txt");
    if (!re) {
        cout << "Error open resident.txt" << endl;
        return 1;
    }
    string name1;
    while (re>>name1) {
        residentn.push_back(name1);
    }
    re.close();

    ifstream fa("facility.txt");
    if (!fa) {
        cout << "Error open facility.txt" << endl;
        return 1;
    }
    string name2;
    while (fa>>name2) {
        facilityn.push_back(name2);
    }
    fa.close();

    ifstream an("animal.txt");
    if (!an) {
        cout << "Error open animal.txt" << endl;
        return 1;
    }
    string name3;
    while (an>>name3) {
        animaln.push_back(name3);
    }
    an.close();

    // Random insert 10residents 5facilities 10animals into map
    for ( int i = 0; i < 10; i++) {
        cities["A"][0].push_back(residentn[rand() % 25]);
        cities["B"][0].push_back(residentn[rand() % 25]);
        cities["C"][0].push_back(residentn[rand() % 25]);
    }
    for ( int O = 0; O < 5; O++) {
        cities["A"][1].push_back(facilityn[rand() % 25]);
        cities["B"][1].push_back(facilityn[rand() % 25]);
        cities["C"][1].push_back(facilityn[rand() % 25]);
    }
    for ( int P = 0; P < 10; P++) {
        cities["A"][2].push_back(animaln[rand() % 20]);
        cities["B"][2].push_back(animaln[rand() % 20]);
        cities["C"][2].push_back(animaln[rand() % 20]);
    }

    // Display the initial information
    display(cities);


    // Start a time-based simulation for city growth and changes
        // Do 25 time period(25 years)
        for (int i = 1; i < 25; i++) {
            cout << "------Year: " << i << endl;
            // Call function simulate(what is in function)
            simulate(cities, residentn, facilityn, animaln);
            display(cities);
        // Every 1 year, print the new information of three city
        }

    // End of main function
}

// void simulate(const map<string, array<list<string>, 3>>& cities) 
void simulate(const map<string, array<list<string>, 3>>& cities, residentn, facilityn, animaln) {

    // Go through each city in the map
    for (auto& city : cities) {
        // little change:
        // random add people or delete (if radom % 100 : <60 +1 people >60 -1 people)
        if (rand() % 100 < 60) {
            city.second[0].push_back(residentn[rand() % 25]);
            cout << "Resident moved in" << endl;
        }
        else {
            city.second[0].pop_front();
            cout << "Resident moved out" << endl;
        }

        // random add facility or delete (if radom % 100 : <40 +1 facility >40 -1 facility)
        if (rand() % 100 < 40) {
            city.second[1].push_back(facilityn[rand() % 25]);
            cout << "Facility built" << endl;
        }
        else {
            city.second[1].pop_front();
            cout << "Facility closed" << endl;
        }

        // random add animal or delete (if radom % 100 : <50 +1 animal >50 -1 animal)
        if (rand() % 100 < 50) {
            city.second[1].push_back(animaln[rand() % 20]);
            cout << "New animal found" << endl;
        }
        else {
            city.second[1].pop_front();
            cout << "Animal extinct" << endl;
        }
        
        int random;
        random = rand() % 100;
        // If "Economic Boom" (20%)
        if (random < 20) {
            cout << "Economic Boom!!!" << city.first << endl;
            // Add new resident to the resident list
            for ( int a = 0; a < 10; a++) {
                city.second[0].push_back(residentn[rand() % 25]);
            }
            // Add new facilities to the facility list
            for ( int b = 0; b < 5; b++) {
                city.second[1].push_back(facilityn[rand() % 25]);
            }
            // Reduce animals in the animal list
            for ( int c = 0; c < 5; c++) {
                city.second[2].pop_front;
            }
        }

        // If "Economic Depression" (10%)
        if (random < 10) {
            cout << "Economic Depression!!!" << city.first << endl;
            // Remove residents from the resident list
            for ( int a = 0; a < 10; a++) {
                city.second[0].pop_front;
            }
            // Remove  facilities from the facility list
            for ( int b = 0; b < 5; b++) {
                city.second[1].pop_front;
            }
            // Add animals to the animal list
            for ( int c = 0; c < 5; c++) {
                city.second[2].push_back(animaln[rand() % 20]);
            }
        }

        // If "Government Build Factory" (15%)
        if (random < 15) {
            cout << "Government Build Factory!!!" << city.first << endl;
            // Remove residents from the resident list
            for ( int a = 0; a < 10; a++) {
                city.second[0].pop_front;
            }
            // Remove facilities in the facility list
            for ( int b = 0; b < 5; b++) {
                city.second[1].pop_front;
            }
            // Reduce animals in the animal list
            for ( int c = 0; c < 5; c++) {
                city.second[2].pop_front;
            }
        }
    }
}