/*
Defines the metro sim driver, containing functions for interpreting user commands when using the program. 
this class uniquely records the number of passengers in the simulation.
*/
#ifndef _METROSIM_H_
#define _METROSIM_H_

class MetroSim
{
public:
    void stop();
    void move();
    void addPassenger(int id, int from, int to);
    void printMap();
private:
    void readStations();
    // void readCommandsFile();
    void readCommands();
    void outputToFile();
    int num_passengers = 0;
    Metro metro;
};

#endif