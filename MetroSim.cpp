/*
 * This file implements the user-facing functions of the command line when running the metro simulation. 
 */

#include "Metro.h"
#include "Passenger.h"


// Stop the simulation and exit the program, printing exit message
// Delete all contents of the simulation: all the data of the train, passengerqueues, and passengers
void MetroSim::stop()
{
    cout << "Thanks for playing MetroSim. Have a nice day!";
    delete metro;
}

/*
moves the train forward one stop. the print function will indicate the train is present at station++, and all passengers will board the train AFTER the train leaves the station
*/
void MetroSim::move()
{
    metro.moveTrain();
    metro.printTrain();
}

/*
adds a passenger to the simulation, which is initialized with an id and assigned to the station "from" 
returns nothing
*/
void MetroSim::addPassenger(int from, int to)
{
    Passenger * p = new Passenger(++numPassengers, from, to);
    metro.addToStation(p);
}

// reads the names of the stations in stationsFile in order and assigns new stations to the metro
void MetroSim::readStations(ifstream& stationsFile)
{
    std::string stationName;
    while (stationsFile >> stationName)
    {
        metro.newStation(stationName);
    }
}

// reads the command as a line and performs the appropriate function call
void MetroSim::readCommands(std::string command)
{
    if (command == "m f") { stop(); }
    else if (command == "m m") { move(); }
    else if (command[0] == "p") {
        int from = command[2];
        int to   = command[4];
        addPassenger(from, to);
    }
}

void MetroSim::readCommandsFile(ifstream & file)
{
    std::string line;
    while (std::getline(file, line))
    {
        readCommands(line);
    }
}