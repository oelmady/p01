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


class Metro
{
public:
    Metro();
    Metro(int stations);
    void addToStation(const Passenger &p);
    void moveTrain();
    void printTrain();
    int currentStation = 0;
private:
    void boardTrain(const Passenger &p);
    string disembarkAtStation(Passenger &p, int destination);
    int numStations = 2;
    std::vector<PassengerQueue> compartments; 
    std::vector<PassengerQueue> stations; 
};

#endif
