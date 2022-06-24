/*
Defines the metro sim driver, containing functions for interpreting user commands when using the program. 
*/
#ifndef _METROSIM_H_
#define _METROSIM_H_

class MetroSim
{
    void stop();
    void move();
    void addPassenger(int from, int to);
};

#endif