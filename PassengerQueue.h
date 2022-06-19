/*
The PassengerQueue class implements the functionality for the metro simulator, adding and removing passengers on the metro simulator as the train moves from one station to another.

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
    Passenger front() { return queue.front(); }
    void dequeue()
    {
        if (!queue.empty()) 
        {
            queue.pop_front(); 
        }
    }
    void enqueue(const Passenger &p) 
    {
        queue.push_back(p);
    }
    int size() 
    {
        return queue.size(); 
    }
    void print(std::ostream &os)
    {
        for (const Passenger &current : queue)
        {
            string out = "[" + to_string(current.id) + ", " + to_string(current.from) + "->" + to_string(current.to) + "]";
            os << out;
        }
    }
private:
    std::list<Passenger> queue;
    // int q_id;
};

#endif;