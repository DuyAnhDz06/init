#ifndef awakened_h
#define awakened_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <limits> // Để sử dụng numeric_limits
using namespace std;

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
// awakened.h
int invalidTime(const string &schedule)
{
    ifstream file(schedule);
    int count = 0;
    int numberOfShips;

    // Log #1
    if (!(file >> numberOfShips))
    {
        cout << "Log #1: Error reading number of ships!" << endl;
        return -1;
    }

    for (int i = 0; i < numberOfShips; ++i)
    {
        string shipName, startDay, startTime, endDay, endTime;

        // Log #2
        getline(file, shipName);
        // Log #3
        getline(file, startDay);
        // Log #4
        getline(file, startTime);
        // Log #5
        getline(file, endDay);
        // Log #6
        getline(file, endTime);

        // Now process the data as needed...

        // Example: Check if shipName is valid (contains only letters and numbers)
        for (char &c : shipName)
        {
            if (!isalnum(c))
            {
                count++;
                cout << "Log #" << 7 + i * 4 << ": Ship " << i + 1 << ": " << shipName << " | Invalid Ship Name: " << shipName << endl;
                break;
            }
        }

        // Example: Check if startDay contains invalid characters
        for (char &c : startDay)
        {
            if (!isdigit(c) && c != '?')
            {
                count++;
                cout << "Log #" << 8 + i * 4 << ": Ship " << i + 1 << ": " << shipName << " | Invalid Start Day: " << startDay << endl;
                break;
            }
        }

        // Example: Check if startTime contains invalid characters
        for (char &c : startTime)
        {
            if (!isdigit(c) && c != '?' && c != ':')
            {
                count++;
                cout << "Log #" << 9 + i * 4 << ": Ship " << i + 1 << ": " << shipName << " | Invalid Start Time: " << startTime << endl;
                break;
            }
        }

        // Add similar logic for endDay and endTime as needed
    }

    return count;
}

string longestDuration(const string &schedule)
{
    ifstream file(schedule);
    string longestShip;
    int startTime, endTime, maxDuration = 0;

    while (file >> startTime >> endTime)
    {
        // Your logic to find and calculate duration goes here
        // Example: Calculate duration between startTime and endTime
        int duration = endTime - startTime;

        // Example: Update longestShip if current duration is greater
        if (duration > maxDuration)
        {
            maxDuration = duration;
            stringstream ss;
            ss << startTime << "-" << endTime;
            longestShip = ss.str();
        }
    }

    return longestShip;
}



bool investigateTemple(const string &map, const string &moveStyle, int stamina, int &outTime, string &outPath)
{
    // Complete this function to gain point
    return false;
}

int solveCrate(int *arr, int size, int k)
{
    // Complete this function to gain point
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* awakened_h */
