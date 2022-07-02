/*
 * This file contains the header functions for the Metro class, which can enqueue, dequeue, and print passengers and stations on the Metro route of the metro sim
 */

#ifndef _Metro_H_
#define _Metro_H_

#include "Passenger.h"
#include "PassengerQueue.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Metro
{
public:
    void addToStation(const Passenger &p);
    void moveTrain();
    void disembarkAtStation(std::ofstream &file);
    void printTrain();
    void newStation(string name);
    int currentStation = 0;
private:
    void boardTrain(const Passenger &p);
    string disembark();
    string farewell(Passenger &p) const;
    int numStations = 0;
};

#endif
