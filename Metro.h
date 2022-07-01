/*
 * This file contains the header functions for the Metro class, which can enqueue, dequeue, and print passengers and stations on the Metro route of the metro sim
 * this class organizes the passengers among passengerqueues with 0-index order.
 */

#ifndef _Metro_H_
#define _Metro_H_

#include "Passenger.h"
#include "PassengerQueue.h"
#include <vector>
#include <string>
#include <iostream>
#include <ofstream>

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
    std::vector<PassengerQueue*> compartments; 
    std::vector<PassengerQueue*> stations; 
};

#endif
