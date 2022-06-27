/*
this file implements the functionality of the Passenger queue class, which is a queue of passengers using the <list> data structure.
*/

#include "Passenger.h"
#include "PassengerQueue.h"
// returns the front of the queue, if any
Passenger PassengerQueue::front() const
{ 
    return queue.front(); 
}
/*
returns the first passegner in the queue, removing them from the queue and decreasing size of the queue by 1.
*/
Passenger PassengerQueue::dequeue()
{
    if (!queue.empty()) 
    {
        Passenger &result = queue.front();
        queue.pop_front(); 
        return result;
    }
    return;
}

// adds a pointer to the passenger
void PassengerQueue::enqueue(const Passenger &p) 
{
    queue.push_back(p);
}

int PassengerQueue::size() 
{
    return queue.size(); 
}

void PassengerQueue::print(std::ostream &os)
{
    for (const Passenger &current : queue)
    {
        string out = "[" + to_string(current.id) + ", " + to_string(current.from) + "->" + to_string(current.to) + "]";
        os << out;
    };
}