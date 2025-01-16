#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int table[3][4];  //  table with random things (numbers)
bool trust[3][4]; // helper array for show table

// update and show tha table
void show()
{
    cout << "+-------+-------+-------+-------+\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "|";
        for (int j = 0; j < 4; j++)
        {
            if (trust[i][j] == true)
            {
                cout << "   " << table[i][j] << "   " << "|";
            }
            else
            {
                cout << "   " << "?" << "   " << "|";
            }
        }
        cout << endl
             << "+-------+-------+-------+-------+\n";
    }
}

int main()
{
    srand(time(0));
    int numbers[12]; //  make an array of things(numbers) for include the table
    int i = 0, k = 1;
    //  make array numbers
    while (i < 12)
    {
        numbers[i] = k;
        numbers[i + 1] = k;
        k++;
        i += 2;
    }
    //  make table with random numbers
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int randomIndex = rand() % 12;
            while (numbers[randomIndex] == 0)
            {
                randomIndex = rand() % 12;
            }
            table[i][j] = numbers[randomIndex];
            numbers[randomIndex] = 0;
            trust[i][j] = false;
        }
    }
    //  start the game --------------------------------------------------
    cout << "START GAME!" << endl;

    // show the table for 5 second .....
    cout << "+-------+-------+-------+-------+\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "|";
        for (int j = 0; j < 4; j++)
        {
            cout << "   " << table[i][j] << "   " << "|";
        }
        cout << endl
             << "+-------+-------+-------+-------+\n";
    }
    int timer = time(0); // start timer
    while (true)
    {
        if (time(0) - timer == 7)
        {
            system("cls");
            break;
        }
    }
    int start = time(0); // start time
    int s = 0, score = 0,
        x1, y1, x2, y2;
    while (s < 6)
    {
        cout << endl;
        cout << "Please enter the first cell(row and column) : ";
        cin >> x1 >> y1;
        if (x1 > 3 || y1 > 4)
        {
            cout << "Wrong selection\n";
            continue;
        }
        x1--;
        y1--;
        cout << "Please enter the second cell(row and column): ";
        cin >> x2 >> y2;
        if (x2 > 3 || y2 > 4)
        {
            cout << "Wrong selection\n";
            continue;
        }
        x2--;
        y2--;
        //  if user select a same cell
        if (x1 == x2 && y1 == y2)
        {
            cout << "Repeated selection\n";
            continue;
        }
        // if user select a cell that have chosen
        if (trust[x1][y1] == true || trust[x2][y2] == true)
        {
            cout << "You have already chosen\n";
            continue;
        }

        if (table[x1][y1] == table[x2][y2])
        {
            trust[x1][y1] = true;
            trust[x2][y2] = true;
            s++;
            score += 10;
            cout << "yeah! +10\n";
            show();
        }
        else
        {
            score--;
            cout << "oops!! -1\n";
            show();
        }
        cout << "your score of selections : " << score << endl;
    }
    int timeScore = 0;
    if (time(0) - start <= 60)
    {
        timeScore += 20;
    }
    else
    {
        // for each 5 second late -2 score
        timeScore -= ((time(0) - start) / 5) * -2;
    }
    system("cls");
    cout << "END GAME!\n";
    cout << "your score of selections : " << score << endl;
    cout << "your score of time is : " << timeScore << endl;
    cout << "your sum of scores is : " << score + timeScore;
    int wait;
    cin >> wait;
}
