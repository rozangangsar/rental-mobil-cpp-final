#include "Renter.h"
#include <iostream>
using namespace std;

Renter::Renter() {
    renterID = "";
    renterName = "";
    phoneNumber = "";
    address = "";
    rentalCar = "";
    rentalDays = 0;
    totalCost = 0;
}

Renter::Renter(string id, string name, string phone, string addr) {
    renterID = id;
    renterName = name;
    phoneNumber = phone;
    address = addr;
    rentalCar = "";
    rentalDays = 0;
    totalCost = 0;
}

void Renter::setRenterID(string id) {
    renterID = id;
}

void Renter::setRenterName(string name) {
    renterName = name;
}

void Renter::setPhoneNumber(string phone) {
    phoneNumber = phone;
}

void Renter::setAddress(string addr) {
    address = addr;
}

void Renter::setRentalCar(string carID) {
    rentalCar = carID;
}

void Renter::setRentalDays(int days) {
    rentalDays = days;
}

void Renter::setTotalCost(long cost) {
    totalCost = cost;
}

string Renter::getRenterID() {
    return renterID;
}

string Renter::getRenterName() {
    return renterName;
}

string Renter::getPhoneNumber() {
    return phoneNumber;
}

string Renter::getAddress() {
    return address;
}

string Renter::getRentalCar() {
    return rentalCar;
}

int Renter::getRentalDays() {
    return rentalDays;
}

long Renter::getTotalCost() {
    return totalCost;
}

void Renter::printRenterInfo() {
    cout << "ID: " << renterID << " | Nama: " << renterName
         << " | Telepon: " << phoneNumber << " | Alamat: " << address << endl;
}

void Renter::printRentalDetails() {
    cout << "Penyewa: " << renterName << " | Mobil: " << rentalCar
         << " | Hari: " << rentalDays << " | Total: Rp" << totalCost << endl;
}
