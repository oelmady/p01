#include "Passenger.h"
#include "PassengerQueue.h"
#include "Metro.h"

int main(){
    
    Passenger a(1,2,3);
    Passenger b(2,2,4);
    Passenger c(3,1,3);
    Metro metro;
    metro.numStations = 3;
    metro.addToStation(a);
    metro.addToStation(b);
    metro.addToStation(c);
    metro.printTrain();
    metro.moveTrain();
    metro.printTrain();
    metro.moveTrain();
    return 0;
}