#ifndef USER_H
#define USER_H
#include "Attraction.h"
class User
{
private:
    char name[100];
    char email[100];

public:
    User(const char *name = "unknow", const char *email = "unknow")
    {
        strncpy(this->email, email, sizeof(this->email));
        this->email[sizeof(this->email) - 1] = '\0';

        strncpy(this->name, name, sizeof(this->name));
        this->name[sizeof(this->name) - 1] = '\0';
    }

    void set_email(const char *email)
    {
        strncpy(this->email, email, sizeof(this->email));
        this->email[sizeof(this->email) - 1] = '\0';
    }

    void set_name(const char *name)
    {
        strncpy(this->name, name, sizeof(this->name));
        this->name[sizeof(this->name) - 1] = '\0';
    }

    std::string get_name() const
    {
        return std::string(this->name);
    }

    std::string get_email() const
    {
        return std::string(this->email);
    }

    void print() const
    {
        std::cout << "name is : " << this->name << " email is : " << this->email << std::endl;
    }
};
#endif