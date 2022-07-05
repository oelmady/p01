/*
 * This file implements the user-facing functions of the command line when running the metro simulation. 
 */

#include "Metro.h"
#include "Passenger.h"
#include "MetroSim.h"

#include <string>

// Stop the simulation and exit the program, printing exit message
// Delete all contents of the simulation: all the data of the train, passengerqueues, and passengers
void MetroSim::stop()
{
    on = false;
    cout << "Thanks for playing MetroSim. Have a nice day!";
}

/*
moves the train forward one stop and boards passengers at the next station. the print function will indicate the train is present at the next station, and all passengers will at that station will have boarded
*/
void MetroSim::move()
{
    metro.moveTrain();
    metro.printTrain();
}

/*
adds a new passenger to the simulation, which is initialized with an id and assigned to the station "from" 
*/
void MetroSim::addPassenger(int from, int to)
{
    shared_ptr<Passenger> p(new Passenger(++numPassengers, from, to));
    metro.addToStation(*p);
}

// reads the names of the stations in stationsFile in order and assigns new stations to the metro
void MetroSim::readStations(ifstream& stationsFile)
{
    std::string stationName;
    while (getline(stationsFile, stationName))
    {
        metro.newStation(stationName);
    }
}

// reads the command as a line and performs the appropriate function call
void MetroSim::readCommand(string command)
{
    if (command == "m f") { stop(); }
    else if (command == "m m") { 
        output += metro.disembarkAtStation();
        move(); 
    }
    else if (command[0] == 'p') {
        int from = command[2];
        int to   = command[4];
        addPassenger(from, to);
    }
}
