/*
this file implements the functionality of the Passenger queue class, which is a queue of passengers using the doubly linked list data structure std::list.
*/

#include "Passenger.h"
#include "PassengerQueue.h"
#include <iostream>
#include <string>
#include <list>
// constructor for stations only, assigns station a name
PassengerQueue::PassengerQueue(string str)
{
    name = str;
}
// returns the front of the queue, if any
Passenger PassengerQueue::front() const
{ 
    return *queue.front(); 
}

/*
destroys the passenger at the front of the list, reformatting the list and reducing its size by 1
returns nothing
*/
void PassengerQueue::dequeue()
{
    if (length == 0) return;

    queue.pop_front();
    length--;
}

// points the passenger to the back of the queue
void PassengerQueue::enqueue(const Passenger &p) 
{
    queue.push_back(&p);
    length++;
}

// returns number of passengers in the queue
int PassengerQueue::size() 
{
    return length; 
}

// prints formatted content of the passengers in the queue, without spaces between them
void PassengerQueue::print(std::ostream &os)
{
    for (auto it = queue.begin(); it != queue.end(); ++it)
    {
        Passenger * p = *it;
        string out = "[" + to_string(p->id) + ", " + to_string(p->from) + "->" + to_string(p->to) + "]";
        os << out;
    };
}