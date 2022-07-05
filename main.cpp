/*
 Users of the simulation interface with the program using this file as a driver. When running then simulation, users can input commands to 
 1) add a new passenger to the simulation, 
 2) move the train to the next stop, 
 3) end the simulation.
 */
#include "Passenger.h"
#include "PassengerQueue.h"
#include "Metro.h"
#include "MetroSim.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string error;
	if (argc < 2 || argc > 3) {
		error = "Usage: ./MetroSim stationsFile outputFile [commandsFile]";
		cerr << error << endl;
		return -1;
	}
	ifstream stations;
	stations.open(argv[1]);
	if (!stations) {
		error = "Error: could not open file" + to_string(*argv[1]);
		cerr << error << endl;
		return -1;
	}
	ofstream output;
	output.open(argv[2]);
	if (!output) {
		error = "Error: could not open file" + to_string(*argv[2]);
		cerr << error << endl;
		return -1;
	}
	ifstream commands;
	if (argc == 3) {
		commands.open(argv[3]);
		if (!commands){
			error = "Error: could not open file" + to_string(*argv[3]);
			cerr << error << endl;
			return -1;
		}
	}
	MetroSim m;
	m.readStations(stations);

	while (m.on){
		cout << "Command? ";
		string input;
		if (commands) {
			getline(commands, input);
		}
		else {
			getline(cin, input);
		}
		m.readCommand(input);
	}

	output << m.output << endl;

	stations.close();
	output.close();
	if (commands) { commands.close(); }
}
