#ifndef LOCATION_H
#define LOCATION_H
#include "Attraction.h"
class Location
{
private:
    char name[100];
    char country[100];
    Attraction attraction[100];
    int count_attraction;

public:
    Location(const char *name = "unknow", const char *country = "unknow", int count = 0, Attraction att[] = nullptr) : count_attraction(count)
    {
        strncpy(this->name, name, sizeof(this->name));
        this->name[sizeof(this->name) - 1] = '\0';

        strncpy(this->country, country, sizeof(this->country));
        this->country[sizeof(this->country) - 1] = '\0';

        for (int i = 0; i < count_attraction; i++)
        {
            this->attraction[i] = att[i];
        }
    }

    void set_name(const char *name)
    {
        strncpy(this->name, name, sizeof(this->name));
        this->name[sizeof(this->name) - 1] = '\0';
    }

    void set_country(const char *country)
    {
        strncpy(this->country, country, sizeof(this->country));
        this->country[sizeof(this->country) - 1] = '\0';
    }

    void set_attraction(Attraction att[])
    {
        for (int i = 0; i < count_attraction; i++)
        {
            this->attraction[i] = att[i];
        }
    }

    std::string get_name() const
    {
        return std::string(this->name);
    }

    std::string get_country() const
    {
        return std::string(this->country);
    }

    Attraction get_attraction(int index) const
    {
        return attraction[index];
    }

    int get_count()
    {
        return this->count_attraction;
    }

    void print()
    {
        std::cout << "\xF0\x9F\x93\x8C name is : " << this->name << "   \xF0\x9F\x8C\x90 country : " << this->country << std::endl;
    }
};

#endif