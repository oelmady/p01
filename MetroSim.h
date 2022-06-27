/*
Defines the metro sim driver, containing functions for interpreting user commands when using the program. 
*/
#ifndef _METROSIM_H_
#define _METROSIM_H_

class MetroSim
{
public:
    void stop();
    void move();
    void addPassenger(int id, int from, int to);
    void print();
private:
    int num_passengers = 0;
    Metro train;
};

#endif