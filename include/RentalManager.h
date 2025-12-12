#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H

#include "Car.h"
#include "Renter.h"
#include <vector>
#include <string>
using namespace std;

class RentalManager {
private:
    vector<Car> cars;
    vector<Renter> renters;

public:
    RentalManager();

    void addCar(string id, string model, string type, long rate);
    void editCar(string carID, string model, string type, long rate);
    void deleteCar(string carID);
    void viewAllCars();
    void viewAvailableCars();
    Car* findCar(string carID);

    void addRenter(string id, string name, string phone, string address);
    void editRenter(string renterID, string name, string phone, string address);
    void deleteRenter(string renterID);
    void viewAllRenters();
    Renter* findRenter(string renterID);

    void rentCar(string renterID, string carID, int days, long dailyRate);
    void returnCar(string carID);
    void viewRentalHistory();

    void searchCarByType(string type);
    void checkCarAvailability(string carID);

    void loadFromFile(string filename);
    void saveToFile(string filename);

};

#endif
