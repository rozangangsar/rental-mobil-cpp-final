#include "AuthenticationManager.h"
#include <iostream>
using namespace std;

AuthenticationManager::AuthenticationManager() {
    currentUser = NULL;
    initializeDefaultUsers();
}

void AuthenticationManager::initializeDefaultUsers() {
    users.push_back(User("admin", "admin123", ADMIN));
    users.push_back(User("administrator", "pass123456", ADMIN));

    users.push_back(User("user", "user123", USER));
    users.push_back(User("rozan", "12345678", USER));
    users.push_back(User("john", "johndoe", USER));
}

User* AuthenticationManager::login(string username, string password) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == username) {
            if (users[i].verifyPassword(password)) {
                currentUser = &users[i];
                cout << "\n=========================" << endl;
                cout << "     LOGIN BERHASIL!     " << endl;
                cout << "==========================" << endl;
                cout << "Selamat datang, " << currentUser->getUsername() << "!" << endl;
                cout << "Role: " << currentUser->getRoleAsString() << endl;
                return currentUser;
            } else {
                cout << "Error: Password salah!" << endl;
                return NULL;
            }
        }
    }
    cout << "Error: Username tidak ditemukan!" << endl;
    return NULL;
}

void AuthenticationManager::logout() {
    if (currentUser != NULL) {
        cout << "\nAnda telah logout. Terima kasih!" << endl;
        currentUser = NULL;
    }
}
User* AuthenticationManager::getCurrentUser() {
    return currentUser;
}
bool AuthenticationManager::isLoggedIn() {
    return currentUser != NULL;
}
bool AuthenticationManager::isAdminLoggedIn() {
    return (currentUser != NULL && currentUser->getRole() == ADMIN);
}
bool AuthenticationManager::isUserLoggedIn() {
    return (currentUser != NULL && currentUser->getRole() == USER);
}

bool AuthenticationManager::addUser(string username, string password, UserRole role) {
    if (usernameExists(username)) {
        cout << "Error: Username sudah dipakai!" << endl;
        return false;
    }
    users.push_back(User(username, password, role));
    cout << "Akun berhasil dibuat. Silakan login." << endl;
    return true;
}

bool AuthenticationManager::usernameExists(const string& username) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUsername() == username) {
            return true;
        }
    }
    return false;
}
void AuthenticationManager::printAvailableUsers() {
    cout << "\n========================================" << endl;
    cout << "     AKUN YANG TERSEDIA UNTUK LOGIN     " << endl;
    cout << "==========================================" << endl;

    cout << "\n--- ADMIN ACCOUNTS ---" << endl;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getRole() == ADMIN) {
            cout << "Username: " << users[i].getUsername() << " | Password: " << users[i].getPassword() << endl;
        }
    }

    cout << "\n--- USER ACCOUNTS ---" << endl;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getRole() == USER) {
            cout << "Username: " << users[i].getUsername() << " | Password: " << users[i].getPassword() << endl;
        }
    }
    cout << endl;
}
