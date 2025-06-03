#include <iostream>
#include <cstring>
#ifndef ATTRACTION_H
#define ATTRACTION_H
class Attraction
{
private:
    char name[100];
    char type[20];
    char description[400];

public:
    Attraction(const char *name = "unknow", const char *type = "unknow", const char *description = "unknow")
    {
        strncpy(this->name, name, sizeof(this->name));
        this->name[sizeof(this->name) - 1] = '\0';

        strncpy(this->type, type, sizeof(this->type));
        this->type[sizeof(this->type) - 1] = '\0';

        strncpy(this->description, description, sizeof(this->description));
        this->description[sizeof(this->description) - 1] = '\0';
    }

    void set_name(const char *name)
    {
        strncpy(this->name, name, sizeof(this->name));
        this->name[sizeof(this->name) - 1] = '\0';
    }

    void set_type(const char *type)
    {
        strncpy(this->type, type, sizeof(this->type));
        this->type[sizeof(this->type) - 1] = '\0';
    }

    void set_description(const char *description)
    {
        strncpy(this->description, description, sizeof(this->description));
        this->description[sizeof(this->description) - 1] = '\0';
    }

    std::string get_name() const
    {
        return this->name;
    }

    std::string get_type() const
    {
        return this->type;
    }

    std::string get_description() const
    {
        return this->description;
    }

    void print() const
    {
        std::cout << "\n \xF0\x9F\x94\xB5 Name : " << this->name << "\n \xF0\x9F\x94\xB0 Type : " << this->type << "\n \xF0\x9F\x93\x9D Description : " << this->description << std::endl;
        std::cout << "----------------------------------------------------------------------------" << std::endl;
    }
    bool operator==(const Attraction &x) const
    {
        return std::string(this->name) == x.get_name();
    }
};
#endif