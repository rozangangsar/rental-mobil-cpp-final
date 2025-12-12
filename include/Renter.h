#ifndef RENTER_H
#define RENTER_H

#include <string>
using namespace std;

class Renter {
private:
    string renterID;
    string renterName;
    string phoneNumber;
    string address;
    string rentalCar;
    int rentalDays;
    long totalCost;

public:
    Renter();
    Renter(string id, string name, string phone, string addr);

    void setRenterID(string id);
    void setRenterName(string name);
    void setPhoneNumber(string phone);
    void setAddress(string addr);
    void setRentalCar(string carID);
    void setRentalDays(int days);
    void setTotalCost(long cost);

    string getRenterID();
    string getRenterName();
    string getPhoneNumber();
    string getAddress();
    string getRentalCar();
    int getRentalDays();
    long getTotalCost();

    void printRenterInfo();
    void printRentalDetails();

};

#endif
