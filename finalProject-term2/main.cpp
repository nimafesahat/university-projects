#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Location.h"
#include "User.h"
#include "Review.h"
using namespace std;

void home()
{
    cout << "\n\xF0\x9F\x8C\x8E ===== TOURIST ASSISTANT ===== \xF0\x9F\x8C\x8E \n\n";
    cout << "1. " << "\xF0\x9F\x93\x8D Show Locations\n";
    cout << "0. " << "\xE2\x9D\x8C Exit\n";
    cout << "\n\xF0\x9F\x91\x89 Enter your Choice : ";
}

int main(int argc, const char **argv)
{
    while (true)
    {
        home();
        int result;
        cin >> result;

        if (result == 1)
        {
            while (true)
            {
                system("clear");
                static Location list[1000];
                Location location;
                ifstream loc("locations.bin", ios::binary);
                int i = 0;
                // Show all locations and fill an array of locations
                cout << "\t\t\tLocations Menu\n";
                while (loc.read((char *)&location, sizeof(location)))
                {
                    cout << i + 1 << ". ";
                    list[i] = location;
                    list[i].print();
                    i++;
                }
                loc.close();
                cout << "\n0. \xF0\x9F\x94\x99 Back\n\n";
                cout << "\xF0\x9F\x91\x89 Enter your Choice : ";
                cin >> result;
                while (true)
                {
                    if (result == 0)
                    {
                        break;
                    }
                    else if (result > i)
                    {
                        cout << "\xE2\x9B\x94 ERROR : Please enter correct selection!!!" << endl;
                        cout << "\xF0\x9F\x91\x89 Enter your Choice : ";
                        cin >> result;
                        continue;
                    }
                    break;
                }
                if (result == 0)
                {
                    system("clear");
                    break;
                }
                system("clear");
                result--;
                int listId = result;
                int attractionCount = list[listId].get_count();
                while (true)
                {
                    i = 0;
                    cout << "\t\t\tAttraction Menu\n";
                    while (i < attractionCount)
                    {
                        cout << i + 1 << ". ";
                        (list[listId].get_attraction(i)).print();
                        i++;
                    }
                    cout << "\n0. \xF0\x9F\x94\x99 Back\n\n";
                    cout << "\xF0\x9F\x91\x89 Enter your Choice : ";
                    cin >> result;
                    while (true)
                    {
                        if (result == 0)
                        {
                            break;
                        }
                        else if (result > i)
                        {
                            cout << "\xE2\x9B\x94 ERROR : Please enter correct selection!!!" << endl;
                            cout << "\xF0\x9F\x91\x89 Enter your Choice : ";
                            cin >> result;
                            continue;
                        }
                        break;
                    }
                    if (result == 0)
                    {
                        system("clear");
                        break;
                    }
                    system("clear");
                    result--;
                    int reviewId = result;
                    Review reviewList[1000];
                    Review review;
                    while (true)
                    {
                        ifstream rev("reviews.bin", ios::binary);
                        int i = 0;
                        // Show all Reviews and fill an array of Reviews
                        while (rev.read((char *)&review, sizeof(review)))
                        {
                            if (review.get_attraction() == list[reviewId].get_attraction(reviewId))
                            {
                                cout << i + 1 << ". ";
                                reviewList[i] = review;
                                reviewList[i].print();
                                i++;
                            }
                        }
                        rev.close();
                        cout << "\n01. \xE2\x9E\x95\xF0\x9F\x93\x9D Add review\n";
                        cout << "\n0. \xF0\x9F\x94\x99 Back\n\n";
                        cout << "\xF0\x9F\x91\x89 Enter your Choice : ";
                        cin >> result;
                        while (true)
                        {
                            if (result == 0 || result == 1)
                            {
                                break;
                            }
                            else
                            {
                                cout << "\xE2\x9B\x94 ERROR : Please enter correct selection!!!" << endl;
                                cout << "\xF0\x9F\x91\x89 Enter your Choice : ";
                                cin >> result;
                                continue;
                            }
                        }
                        system("clear");
                        if (result == 0)
                        {
                            break;
                        }
                        else
                        {
                            string name, email, comment;
                            int rating, action;
                            cout << "\xF0\x9F\x91\xA4 Please enter your name : ";
                            cin >> name;
                            cout << "\xF0\x9F\x93\xA7 Please enter your email : ";
                            cin >> email;
                            while (true)
                            {
                                cout << "\xE2\xAD\x90 rating (1-5) : ";
                                cin >> rating;
                                if (rating > 5 || rating < 0)
                                {
                                    cout << "\xE2\x9B\x94 ERROR : Please enter rating between 1 - 5 !!!" << endl;
                                    continue;
                                }
                                break;
                            }
                            cout << "\xF0\x9F\x92\xAC Comment : ";
                            cin.ignore();
                            getline(cin, comment);
                            
                            while (true)
                            {
                                cout << "\xF0\x9F\x94\xB4 0. Cancel\t\xF0\x9F\x92\xBE 1. Save\n";
                                cin >> action;
                                if (action != 1 && action != 0)
                                {
                                    cout << "\xE2\x9B\x94 ERROR : Please enter correct selection!!!" << endl;
                                    continue;
                                }
                                break;
                            }
                            if (action == 1)
                            {
                                User newUser(name.c_str(), email.c_str());
                                ofstream insertUser("users.bin", ios::binary | ios::app);
                                insertUser.write((char *)&newUser, sizeof(newUser));
                                insertUser.close();

                                Attraction attractionDetails;
                                attractionDetails = reviewList[0].get_attraction();
                                Review newReview(rating, comment.c_str(), attractionDetails, newUser);
                                ofstream insertReview("reviews.bin", ios::binary | ios::app);
                                insertReview.write((char *)&newReview, sizeof(newReview));
                                insertReview.close();
                                system("clear");
                                continue;
                            }
                            else
                            {
                                system("clear");
                                continue;
                            }
                        }
                    }
                    if (result == 0)
                    {
                        continue;
                    }
                }
            }
        }
        else if (result == 0)
        {
            system("clear");
            cout << "\xF0\x9F\x91\x8B Have a good time" << endl;
            break;
        }
        else
        {
            system("clear");
            cout << "\xE2\x9B\x94 ERROR : Please enter correct selection!!!" << endl;
            continue;
        }
    }
}