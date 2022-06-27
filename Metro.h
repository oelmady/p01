/*
 * This file contains the header functions for the Metro class, which interacts directly with the driver MetroSim class for the metro simulation program.
 * The Metro class can be used to enqueue, dequeue and print passengers and stations on the Metro route of the metro sim
 */

#ifndef _Metro_H_
#define _Metro_H_

#include "Passenger.h"
#include "PassengerQueue.h"
#include <vector>
#include <string>


class Metro
{
public:
    void addToStation(const Passenger &p);
    void boardTrain(const Passenger &p);
    string disembarkAtStation(Passenger &p, int destination);
    void moveTrain();
    void printTrain();
    int currentStation = 0;
private:
    int num_stations;
    std::vector<PassengerQueue> compartments; 
    std::vector<PassengerQueue> stations; 
};

#endif
