#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

enum UserRole {
    ADMIN = 1,
    USER = 2
};

class User {
private:
    string username;
    string password;
    UserRole role;

public:
    User();
    User(string uname, string pwd, UserRole r);

    void setUsername(string uname);
    void setPassword(string pwd);
    void setRole(UserRole r);

    string getUsername();
    string getPassword();
    UserRole getRole();

    string getRoleAsString();
    bool verifyPassword(string inputPassword);

};

#endif
