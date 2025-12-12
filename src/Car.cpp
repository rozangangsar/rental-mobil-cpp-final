#include "Car.h"
#include <iostream>
using namespace std;

Car::Car() {
    carID = "";
    carModel = "";
    carType = "";
    dailyRate = 0;
    available = true;
    currentRenter = "";
}

Car::Car(string id, string model, string type, long rate) {
    carID = id;
    carModel = model;
    carType = type;
    dailyRate = rate;
    available = true;
    currentRenter = "";
}
void Car::setCarID(string id) {
    carID = id;
}

void Car::setCarModel(string model) {
    carModel = model;
}

void Car::setCarType(string type) {
    carType = type;
}

void Car::setDailyRate(long rate) {
    dailyRate = rate;
}

void Car::setAvailable(bool status) {
    available = status;
}

void Car::setCurrentRenter(string renter) {
    currentRenter = renter;
}

string Car::getCarID() {
    return carID;
}

string Car::getCarModel() {
    return carModel;
}

string Car::getCarType() {
    return carType;
}

long Car::getDailyRate() {
    return dailyRate;
}

bool Car::getAvailable() {
    return available;
}

string Car::getCurrentRenter() {
    return currentRenter;
}

void Car::printCarInfo() {
    cout << "ID: " << carID << " | Model: " << carModel
         << " | Tipe: " << carType << " | Tarif: Rp" << dailyRate << "/hari" << endl;
}

void Car::printCarStatus() {
    cout << "ID: " << carID << " | Model: " << carModel
         << " | Status: " << (available ? "Tersedia" : "Sedang Disewa") << endl;
    if (!available) {
        cout << "  Penyewa: " << currentRenter << endl;
    }
}
