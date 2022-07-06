/*
This file implements the functions of the Metro class, which is responsible for managing the status of Passengers in the Metro sim. This class uses the PassengerQueue and Passenger classes to modify data representations of the metro compartments and its stations.
*/

#include "Passenger.h"
#include "PassengerQueue.h"
#include "Metro.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// adds a passenger to the station of the metro they are departing from
void Metro::addToStation(const Passenger &p)
{
    metro[p.from]->enqueue(p);
}

// a function that creates a new station with the name stationName and appends it to the metro, incrementing the number of stations by 1
void Metro::newStation(string stationName)
{
    PassengerQueue* station = new PassengerQueue(stationName);
    metro.emplace_back(station);
    numStations++;
}

// a function that returns newline-separated data of each departing passenger 
string Metro::disembarkAtStation()
{
    string output;
    auto& destination = *metro[currentStation];
    
    for (auto const& p : destination.queue){
        output += farewell(p);
    }
    while (destination.size() > 0) {
        destination.dequeue();
    }
    return output;
}

// a private helper function that returns the data of the departing passenger 
string Metro::farewell(const Passenger &p)
{
    string message = "Passenger " + to_string(p.id) + " left the train at station " + metro[p.to]->name + "\n";
    return message;
}

// incrememnts the train's position and boards all passengers at the new station
void Metro::moveTrain()
{
    currentStation = (currentStation + 1) % numStations;

    for (auto &p : metro[currentStation]->queue){
        p.boarded = true;
    }
}

// prints the contents of the metro 
// on the first line prints all boarded passengers
// on each subsequent line, prints the passengers waiting at that station 
//also prints the location of the train
void Metro::printTrain()
{
    cout << "Passengers on the train: {";
    for (int i = 0; i < numStations; i++){
        for (auto &p : metro[i]->queue){
            if (p.boarded){ 
                p.Passenger::print(cout); 
            }
        }
    }
    cout << "}\n";
    for (int i = 0; i < numStations; i++){
        auto& dest = metro[i];
        if (i == currentStation) {
            cout << "TRAIN: ";
        }
        else { 
            cout << "       "; 
        }

        cout << "[" << i << "] " << dest->name << " {";
        for (auto &p : dest->queue){
            if (p.boarded == false){
                p.Passenger::print(cout);
            }
        }
        cout << "}" << endl;
    }
}