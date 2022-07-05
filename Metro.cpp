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

void Metro::addToStation(const Passenger &p)
{
    metro[p.from]->enqueue(p);
}

string Metro::disembarkAtStation()
{
    string output;
    auto& destination = *metro[currentStation];
    for (auto const& p : destination.queue)
    {
        output += farewell(*p);
    }
    while (destination.size() > 0) {
        destination.dequeue();
    }
    return output;
}

string Metro::farewell(const Passenger &p)
{
    string message = "Passenger " + to_string(p.id) + " left the train at station " + metro[p.to]->name + "\n";
    return message;
}

void Metro::moveTrain()
{
    currentStation = (currentStation + 1) % numStations;

    for (auto &p : metro[currentStation]->queue)
    {
        p->boarded = true;
    }
}

void Metro::printTrain()
{
    cout << "Passengers on the train: {";
    for (int i = 0; i < numStations; i++)
    {
        for (auto &p : metro[i]->queue)
        {
            if (p->boarded){
                p->Passenger::print(cout);
            }
        }
    }
    cout << "}";
    for (int i = 0; i < numStations; i++)
    {
        auto& dest = metro[i];
        if (i == currentStation) {
            cout << "TRAIN: ";
        }
        else { 
            cout << "      "; 
        }
        cout << "[" << i << "] " << dest->name << " {";
        dest->print(cout);
        cout << "}" << endl;
    }
}