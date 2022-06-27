/*
This file implements the functions of the Metro class, which is responsible for managing the status of Passengers in the Metro sim. This class uses the PassengerQueue and Passenger classes to modify data representations of the metro compartments and its stations.
*/

#include "Passenger.h"
#include "PassengerQueue.h"
#include "Metro.h"

/* adds a reference to a passenger to the end of the PQ of the stations <vector> with index[p.from]
*/
void Metro::addToStation(const Passenger &p)
{
    stations[p.from].enqueue(p);
}

/*
removes a Passenger p from the station and adds them to the compartment [p.to] of the train;
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
NOTE: is designed to work in conjunction with the destructive PassengerQueue command dequeue(), which returns the Passenger removed from the PQ
*/
string Metro::disembarkAtStation(Passenger &p, int destination)
{
    string write = "Passenger " + to_string(p.id) + " left train at station " + stations[destination].name + "\n";
    return write;
}

/* calls boardTrain on all passengers if any at currentStation before incrementing the currentStation by 1
returns nothing
*/
void Metro::moveTrain()
{
    PassengerQueue station = stations[currentStation];
    for (const Passenger &p : station) {
        int toComp = p.to;
        compartments[toComp].enqueue(p);
    }
    currentStation++;

}
/*
prints the entire train, including 
all passengers on the train
all 0-indexed stations with station names 
and all passengers if any at each station
the location of the train
*/
void Metro::printTrain()
{

}


