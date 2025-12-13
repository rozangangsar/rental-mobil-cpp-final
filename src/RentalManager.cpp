#include "RentalManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

RentalManager::RentalManager() {
}
void RentalManager::addCar(string id, string model, string type, long rate) {
    if (findCar(id) != NULL) {
        cout << "Error: Mobil dengan ID " << id << " sudah ada!" << endl;
        return;
    }
    Car newCar(id, model, type, rate);
    cars.push_back(newCar);
}

void RentalManager::editCar(string carID, string model, string type, long rate) {
    Car* car = findCar(carID);
    if (car == NULL) {
        cout << "Error: Mobil dengan ID " << carID << " tidak ditemukan!" << endl;
        return;
    }
    car->setCarModel(model);
    car->setCarType(type);
    car->setDailyRate(rate);
    cout << "Data mobil berhasil diperbarui!" << endl;
}

void RentalManager::deleteCar(string carID) {
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].getCarID() == carID) {
            cars.erase(cars.begin() + i);
            cout << "Mobil berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Error: Mobil dengan ID " << carID << " tidak ditemukan!" << endl;
}

void RentalManager::viewAllCars() {
    if (cars.empty()) {
        cout << "Tidak ada data mobil." << endl;
        return;
    }
    cout << "\n=== DAFTAR SEMUA MOBIL ===" << endl;
    for (int i = 0; i < cars.size(); i++) {
        cout << i + 1 << ". ";
        cars[i].printCarInfo();
    }
}

void RentalManager::viewAvailableCars() {
    cout << "\n=== DAFTAR MOBIL TERSEDIA ===" << endl;
    int count = 0;
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].getAvailable()) {
            cout << ++count << ". ";
            cars[i].printCarInfo();
        }
    }
    if (count == 0) {
        cout << "Tidak ada mobil yang tersedia." << endl;
    }
}

Car* RentalManager::findCar(string carID) {
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].getCarID() == carID) {
            return &cars[i];
        }
    }
    return NULL;
}
void RentalManager::addRenter(string id, string name, string phone, string address) {
    if (findRenter(id) != NULL) {
        cout << "Error: Penyewa dengan ID " << id << " sudah ada!" << endl;
        return;
    }
    Renter newRenter(id, name, phone, address);
    renters.push_back(newRenter);
    cout << "Data penyewa berhasil ditambahkan!" << endl;
}

void RentalManager::editRenter(string renterID, string name, string phone, string address) {
    Renter* renter = findRenter(renterID);
    if (renter == NULL) {
        cout << "Error: Penyewa dengan ID " << renterID << " tidak ditemukan!" << endl;
        return;
    }
    renter->setRenterName(name);
    renter->setPhoneNumber(phone);
    renter->setAddress(address);
    cout << "Data penyewa berhasil diperbarui!" << endl;
}

void RentalManager::deleteRenter(string renterID) {
    for (int i = 0; i < renters.size(); i++) {
        if (renters[i].getRenterID() == renterID) {
            renters.erase(renters.begin() + i);
            cout << "Data penyewa berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Error: Penyewa dengan ID " << renterID << " tidak ditemukan!" << endl;
}

void RentalManager::viewAllRenters() {
    if (renters.empty()) {
        cout << "Tidak ada data penyewa." << endl;
        return;
    }
    cout << "\n=== DAFTAR PENYEWA ===" << endl;
    for (int i = 0; i < renters.size(); i++) {
        cout << i + 1 << ". ";
        renters[i].printRenterInfo();
    }
}

Renter* RentalManager::findRenter(string renterID) {
    for (int i = 0; i < renters.size(); i++) {
        if (renters[i].getRenterID() == renterID) {
            return &renters[i];
        }
    }
    return NULL;
}
void RentalManager::rentCar(string renterID, string carID, int days, long dailyRate) {
    Renter* renter = findRenter(renterID);
    Car* car = findCar(carID);

    if (renter == NULL) {
        cout << "Error: Penyewa tidak ditemukan!" << endl;
        return;
    }
    if (car == NULL) {
        cout << "Error: Mobil tidak ditemukan!" << endl;
        return;
    }
    if (!car->getAvailable()) {
        cout << "Error: Mobil sedang disewa oleh penyewa lain!" << endl;
        return;
    }

    long totalCost = days * dailyRate;
    renter->setRentalCar(carID);
    renter->setRentalDays(days);
    renter->setTotalCost(totalCost);

    car->setAvailable(false);
    car->setCurrentRenter(renter->getRenterName());

    cout << "\n=== DETAIL PENYEWAAN ===" << endl;
    cout << "Penyewa: " << renter->getRenterName() << endl;
    cout << "Mobil: " << car->getCarModel() << " (" << car->getCarID() << ")" << endl;
    cout << "Durasi: " << days << " hari" << endl;
    cout << "Tarif: Rp" << dailyRate << "/hari" << endl;
    cout << "TOTAL BIAYA: Rp" << totalCost << endl;
    cout << "Penyewaan berhasil dicatat!" << endl;
}

void RentalManager::returnCar(string carID) {
    Car* car = findCar(carID);
    if (car == NULL) {
        cout << "Error: Mobil tidak ditemukan!" << endl;
        return;
    }
    if (car->getAvailable()) {
        cout << "Error: Mobil tidak sedang disewa!" << endl;
        return;
    }

    string renterName = car->getCurrentRenter();
    car->setAvailable(true);
    car->setCurrentRenter("");

    cout << "Mobil " << car->getCarModel() << " dari penyewa " << renterName << " berhasil dikembalikan!" << endl;
}

void RentalManager::viewRentalHistory() {
    cout << "\n=== RIWAYAT PENYEWAAN ===" << endl;
    int count = 0;
    for (int i = 0; i < renters.size(); i++) {
        if (renters[i].getRentalCar() != "") {
            cout << ++count << ". ";
            renters[i].printRentalDetails();
        }
    }
    if (count == 0) {
        cout << "Tidak ada riwayat penyewaan." << endl;
    }
}
void RentalManager::searchCarByType(string type) {
    cout << "\n=== PENCARIAN MOBIL - TIPE: " << type << " ===" << endl;
    int count = 0;
    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].getCarType() == type) {
            cout << ++count << ". ";
            cars[i].printCarStatus();
        }
    }
    if (count == 0) {
        cout << "Tidak ada mobil dengan tipe " << type << endl;
    }
}

void RentalManager::checkCarAvailability(string carID) {
    Car* car = findCar(carID);
    if (car == NULL) {
        cout << "Error: Mobil tidak ditemukan!" << endl;
        return;
    }
    cout << "\n=== STATUS KETERSEDIAAN ===" << endl;
    car->printCarStatus();
}

void RentalManager::loadFromFile(string filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cout << "Error: File " << filename << " tidak dapat dibuka!" << endl;
        return;
    }

    string line;
    int added = 0;
    while (getline(inputFile, line)) {
        if (line.empty()) continue;

        istringstream iss(line);
        vector<string> parts;
        string token;
        while (iss >> token) {
            parts.push_back(token);
        }
        if (parts.size() < 4) {
            cout << "Baris diabaikan (format salah): " << line << endl;
            continue;
        }

        string id = parts[0];
        string type = parts[parts.size() - 2];
        long rate = 0;
        try {
            rate = stol(parts.back());
        } catch (...) {
            cout << "Baris diabaikan (tarif tidak valid): " << line << endl;
            continue;
        }

        string model;
        for (size_t i = 1; i < parts.size() - 2; i++) {
            if (!model.empty()) model += " ";
            model += parts[i];
        }

        addCar(id, model, type, rate);
        added++;
    }

    inputFile.close();
    cout << "Data berhasil dimuat dari " << filename <<endl;
}

void RentalManager::saveToFile(string filename) {
    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cout << "Error: File " << filename << " tidak dapat dibuka!" << endl;
        return;
    }

    int saved = 0;
    for (int i = 0; i < cars.size(); i++) {
        outputFile << cars[i].getCarID() << " "
                   << cars[i].getCarModel() << " "
                   << cars[i].getCarType() << " "
                   << cars[i].getDailyRate() << endl;
        saved++;
    }

    outputFile.close();
    cout << "Data berhasil disimpan ke " << filename << " (" << saved << " mobil)" << endl;
}
