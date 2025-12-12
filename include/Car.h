#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car {
private:
    string carID;
    string carModel;
    string carType;
    long dailyRate;
    bool available;
    string currentRenter;

public:
    Car();
    Car(string id, string model, string type, long rate);

    void setCarID(string id);
    void setCarModel(string model);
    void setCarType(string type);
    void setDailyRate(long rate);
    void setAvailable(bool status);
    void setCurrentRenter(string renter);

    string getCarID();
    string getCarModel();
    string getCarType();
    long getDailyRate();
    bool getAvailable();
    string getCurrentRenter();

    void printCarInfo();
    void printCarStatus();

};

#endif
