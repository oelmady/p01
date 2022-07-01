#include "Passenger.h"
#include "PassengerQueue.h"
#include "Metro.h"

int main(){
    Passenger a(1,1,2);
    Passenger b(2,0,1);
    Passenger c(3,1,2);
    Metro metro;
    metro.printTrain(); // should show only top line

    metro.newStation("One Direction");
    metro.newStation("Two Directions");
    metro.newStation("BTS");
    metro.newStation("Dhul Hijjah");
    metro.printTrain(); // should have stations

    metro.addToStation(a);
    metro.addToStation(b);
    metro.addToStation(c);
    metro.printTrain();

    metro.moveTrain();
    metro.printTrain();
    metro.moveTrain();
    metro.printTrain();
    return 0;
}