/*
This file implements the functions of the Metro class, which is responsible for managing the status of Passengers in the Metro sim. This class uses the PassengerQueue and Passenger classes to modify data representations of the metro compartments and its stations.
*/

#include "Passenger.h"
#include "PassengerQueue.h"
#include "Metro.h"

// default constructor initializes a metro
// with 2 stations, compartments
Metro::Metro()
{
    std::vector<PassengerQueue> compartments[numStations];
    std::vector<PassengerQueue> stations[numStations]; 
}
// constructs a metro with ns stations, compartments
Metro::Metro(int ns)
{
    std::vector<PassengerQueue> compartments[ns]; 
    std::vector<PassengerQueue> stations[ns]; 
}

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
removes a Passenger from the train when it arrives at its destination (NOTE: function is called BEFORE printing the metro state.)
returns a message to -the output file- (not std::cout), followed by a single newline:
         Passenger ID left train at station STATION_NAME
NOTE: is designed to work in conjunction with the destructive PassengerQueue command dequeue(), which returns the Passenger removed from the PQ

*/
string Metro::disembarkAtStation(Passenger &p, int destination)
{
    string write = "Passenger " + to_string(p.id) + " left train at station " + stations[destination].name + "\n";
    return write;
}

/* calls boardTrain on all passengers, if any, at currentStation before incrementing the currentStation
*/
void Metro::moveTrain()
{
    // departing passengers disembark at currentStation
    PassengerQueue arrival = compartments[currentStation];
    while(arrival.size() > 0)
    {
        Passenger p = arrival.front();
        disembarkAtStation(p, currentStation);
        arrival.dequeue();
    }
    // arriving passengers board as the train is leaving the station...
    PassengerQueue station = stations[currentStation];
    while (station.size() > 0){
        boardTrain(station.front());
        station.dequeue();
    }
    currentStation = (currentStation + 1) & numStations;
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


