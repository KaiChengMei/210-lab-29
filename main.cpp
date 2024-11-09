// the header files we need map....
#include <iostream>
#include <map>
#include <array>
#include <list>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Creat function to simulate city data over time
    // Parameters: map of cities, number of intervals

// int main function
    // Set up a map to store city data, each city have array of lists for residents, facilities, and animals
    srand(static_cast<unsigned int>(time(0)));
    map<string, array<list<string>, 3>> cities;

    // Set up three array of string to store random resident, facility, animal names
    vector<string> residentn;
    vector<string> facilityn;
    vector<string> animaln;
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
    

    // Display the initial information

    // Start a time-based simulation for city growth and changes
        // Do 25 time period(25 years)
            // Go through each city in the map
                // For each city, apply changes based on the event:
                    // little change:
                    // random add people or delete (if radom % 100 : <60 +1 people >60 -1 people)
                    // random add facility or delete (if radom % 100 : <40 +1 facility >40 -1 facility)
                    // random add animal or delete (if radom % 100 : <50 +1 animal >50 -1 animal)
                    
                    // Simulated events:
                    // If "Economic Boom" (20%)
                        // Add new resident to the resident list
                        // Add new facilities to the facility list
                        // Reduce animals in the animal list

                    // If "Economic Depression" (10%)
                        // Remove residents from the resident list
                        // Remove  facilities from the facility list
                        // Add animals to the animal list

                    // If "Government Build Factory" (15%)
                        // Remove residents from the resident list
                        // Remove facilities in the facility list
                        // Reduce animals in the animal list

                    // Print the update ove the time,  "Added {number} residents to {city}" or "Closed {facility} in {city}"

        // Every 1 year, print the new information of three city

    // End of main function