/*
 * This file implements the user-facing functions of the command line when running the metro simulation. 
 */

#include "MetroSim.h"
#include "Metro.h"
#include "Passenger.h"


// Stop the simulation and exit the program, printing exit message
// Delete all contents of the simulation: all the data of the train, passengerqueues, and passengers
void MetroSim::stop()
{
    cout << "Thanks for playing MetroSim. Have a nice day!";
}

/*
moves the train forward one stop. the print function will indicate the train is present at station++, and all passengers will board the train AFTER the train leaves the station
*/
void MetroSim::move()
{
    metro.moveTrain();
}

/*
adds a passenger to the simulation, which is initialized with an id and assigned to the station "from" 
returns nothing
*/
void MetroSim::addPassenger(int from, int to)
{
    Passenger * p = new Passenger(++numPassengers, from, to);
    metro.addToStation(*p);
}

void MetroSim::print()
{

}