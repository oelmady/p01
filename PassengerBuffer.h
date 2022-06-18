/*
Purpose: to implement a class that represents
and ordered sequence of elements, in this case
Passengers!
The properties of the class allow translation 
to the Queue data structure

author: Omar Elmady
*/


#ifndef Passenger_BUFFER_H
#define Passenger_BUFFER_H

#include "Passenger.h"

class PassengerBuffer
{
public:
        PassengerBuffer();     
        PassengerBuffer(int givenCapcity); 
        ~PassengerBuffer(); 

        void      addAtBack (Passenger p);
        void      addAtFront(Passenger p);
        Passenger removeFromBack();
        Passenger removeFromFront();
        
        void      printBuffer();

private:
        static const int INIT_CAPACITY = 5;

        Passenger *bufferArray;
        int        currentSize;
        int        capacity;
        int        front;
        int        back;

        int  nextIndex(int index);
        int  prevIndex(int index);
        void expand();
        void init(int givenCapacity);
};

#endif