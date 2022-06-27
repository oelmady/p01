/*
The PassengerQueue class defines the functionality for the metro simulator, adding and removing passengers on the metro simulator as the train moves from one station to another.
*/

#ifndef __PASSENGERQUEUE_H__
#define __PASSENGERQUEUE_H__

#include <iostream>
#include <string>
#include <list>

#include "Passenger.h"

class PassengerQueue
{
public:
    Passenger front() const;
    Passenger dequeue();
    void enqueue(const Passenger &p);
    int size();
    void print(std::ostream &os);
    string name;
private:
    std::list<Passenger> queue;
    
};

#endif