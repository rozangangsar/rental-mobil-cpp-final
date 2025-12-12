#include "User.h"
#include <iostream>
using namespace std;

User::User() {
    username = "";
    password = "";
    role = USER;
}
User::User(string uname, string pwd, UserRole r) {
    username = uname;
    password = pwd;
    role = r;
}
void User::setUsername(string uname) {
    username = uname;
}

void User::setPassword(string pwd) {
    password = pwd;
}

void User::setRole(UserRole r) {
    role = r;
}
string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}

UserRole User::getRole() {
    return role;
}
string User::getRoleAsString() {
    if (role == ADMIN) {
        return "ADMIN";
    } else {
        return "USER";
    }
}

bool User::verifyPassword(string inputPassword) {
    return (password == inputPassword);
}
