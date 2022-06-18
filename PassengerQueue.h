/*
The PassengerQueue class implements the functionality for the metro simulator, adding and removing passengers on the metro simulator as the train moves from one station to another.

*/

#ifndef __PASSENGERQUEUE_H__
#define __PASSENGERQUEUE_H__

#include <iostream>
#include <string>

#include "Passenger.h"

using namespace std;

class PassengerQueue
{
public:
    Passenger front();
    void dequeue();
    void enqueue(const Passenger &p);
    int size();
    void print(ostream &output);
private:

}
#endif