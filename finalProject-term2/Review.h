#ifndef REVIEW_H
#define REVIEW_H
#include "User.h"
class Review
{
private:
    int rating;
    char comment[1000];
    Attraction attraction;
    User user;

public:
    Review(int rating = 0, const char *comment = "unknow", Attraction att = Attraction(), User u = User())
        : rating(rating), attraction(att), user(u)
    {
        strncpy(this->comment, comment, sizeof(this->comment));
        this->comment[sizeof(this->comment) - 1] = '\0';
    }

    void set_rating(int rating)
    {
        this->rating = rating;
    }

    void set_comment(const char *comment)
    {
        strncpy(this->comment, comment, sizeof(this->comment));
        this->comment[sizeof(this->comment) - 1] = '\0';
    }

    void set_attraction(Attraction att)
    {
        this->attraction = att;
    }

    void set_user(User u)
    {
        this->user = u;
    }

    int get_rating() const
    {
        return this->rating;
    }

    std::string get_comment() const
    {
        return std::string(this->comment);
    }

    Attraction get_attraction() const
    {
        return this->attraction;
    }

    User get_user() const
    {
        return this->user;
    }

    void print() const
    {
        std::cout << "\xF0\x9F\x93\x8C attraction: " << this->attraction.get_name() << std::endl;
        std::cout << "\xF0\x9F\x91\xA4 user : " << this->user.get_name() << std::endl
                  << "\xF0\x9F\x93\xA7 email : " << user.get_email() << std::endl;
        std::cout << "\xE2\xAD\x90 rating : ";
        int i = 0;
        while (i < this->rating)
        {
            std::cout << "\xE2\xAD\x90";
            i++;
        }
        std::cout << " (5/" << this->rating << ")\n";
        std::cout << "\xF0\x9F\x92\xAC comment : \n"
                  << "\xE2\x9C\xA8 " << this->comment << std::endl;
        std::cout << "----------------------------------------------------------------------------" << std::endl;
    }
};
#endif