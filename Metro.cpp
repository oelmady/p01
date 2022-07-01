/*
This file implements the functions of the Metro class, which is responsible for managing the status of Passengers in the Metro sim. This class uses the PassengerQueue and Passenger classes to modify data representations of the metro compartments and its stations.
*/

#include "Passenger.h"
#include "PassengerQueue.h"
#include "Metro.h"
#include <iostream>
#include <ofstream>

/* points a passenger to the back of the queue of the station with index[p.from]
*/
void Metro::addToStation(const Passenger &p)
{
    stations[p.from].enqueue(p);
}

/*
private function 
points a Passenger p to the back of the queue of their destination compartment [p.to] of the train;
NOTE: must only be called by moveTrain(), which calls boardTrain(p) for all p's at [currentStation];
*/
void Metro::boardTrain(const Passenger &p)
{
    compartments[p.to].enqueue(p); 
}

/*
removes a Passenger from the train when it arrives at its destination 
returns a message to -the output file- (not std::cout), followed by a single newline:
         Passenger ID left train at station STATION_NAME

desired result: every disembarking passenger is coupled to a string written to a file given to the calling function in main() on MetroSim. 
this function is called by the MetroSim class to write the passenger information to a file given by main()
so the disembark function will not have that file 
but it needs to return the string of information to metrosim for every disembarking passenger 
*/
// private helper function returns the information of the departing passenger
string Metro::farewell(Passenger &p) const
{
    string write = "Passenger " + to_string(p.id) + " left train at station " + stations[p.to].name;
    return write;
}

// private helper function removes ALL passengers in the compartment from the simulation and retrieves their information for output
// returns a string containing formatted passenger information for output to a file
string Metro::disembark()
{
    string output;
    PassengerQueue dest = compartments[currentStation];
    while (dest.size() > 0)
    {
        Passenger p = dest.front();
        output += farewell(p) + "\n";
        dest.dequeue();
    }
    return output;
}
// public function removes all passengers at the station if any, and writes their information to a provided file
void Metro::disembarkAtStation(std::ofstream &file)
{
    PassengerQueue dest = stations[currentStation];
    if (dest.size() > 0){
        file << disembark();
    }
}

/* calls boardTrain on all passengers if any, at the next station, so that there are no passengers waiting at the station with the train.
*/
void Metro::moveTrain()
{
    currentStation = (currentStation + 1) & numStations;
    
    // moves passengers from the station to the train
    PassengerQueue station = stations[currentStation];
    while (station.size() > 0){
        boardTrain(std::move(station.front()));
    }
}

// adds a named station to the metro
void Metro::newStation(string name)
{
   PassengerQueue station(name);
   stations.push_back(station);
   numStations++;
}

/*
prints the entire train, including:
all passengers on the train;
all 0-indexed stations with station names;
and all passengers if any at each station;
and the location of the train;
*/
void Metro::printTrain()
{
    string spaces = "       "; // 7 char
    string train = "TRAIN: "; // 7 char

    cout << "Passengers on the train: {";
    for (int i = 0; i < numStations; i++) 
    {
        compartments[i].print(std::cout);
    }
    cout << "}\n";
    for (int i = 0; i < numStations; i++) 
    {
        if (i == currentStation){
            cout << train;
        }
        else { 
            cout << spaces; 
        }
        cout << "[" << i << "] ";
        cout << stations[i].name << " {";
        stations[i].print(std::cout);
        cout << "}\n";
    }
}


