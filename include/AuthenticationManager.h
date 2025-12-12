#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H

#include "User.h"
#include <vector>
using namespace std;

class AuthenticationManager {
private:
    vector<User> users;
    User* currentUser;

public:
    AuthenticationManager();

    User* login(string username, string password);
    void logout();
    User* getCurrentUser();
    bool isLoggedIn();

    void initializeDefaultUsers();
    bool addUser(string username, string password, UserRole role);
    bool usernameExists(const string& username);
    void printAvailableUsers();

    bool isAdminLoggedIn();
    bool isUserLoggedIn();

};

#endif
