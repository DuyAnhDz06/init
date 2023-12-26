/*
 * Ho Chi Minh City University of Technology
 * Faculty of Computer Science and Engineering
 * Initial code for Assignment 1
 * Programming Fundamentals Winter 2023
 * Author: Tran Huy
 * Date: 07.11.2023
 */

// The library here is concretely set, students are not allowed to include any other libraries.
#ifndef awakened_h
#define awakened_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <algorithm>
#include <limits>
using namespace std;

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int calculateStayDuration(const string &startDay, const string &startTime,const string &endDay, const string &endTime)
{
    // Convert startDay, startTime, endDay, and endTime to integers
    int startDayValue, startTimeValue, endDayValue, endTimeValue;
    stringstream(startDay) >> startDayValue;
    stringstream(startTime) >> startTimeValue;
    stringstream(endDay) >> endDayValue;
    stringstream(endTime) >> endTimeValue;

    // Handle the case with '?' characters
    if (startDay.find('?') != string::npos || startTime.find('?') != string::npos ||
        endDay.find('?') != string::npos || endTime.find('?') != string::npos)
    {
        return -1; // Return -1 to indicate an invalid duration if there are '?' characters
    }

    // Calculate the stay duration
    int startMinutes = startDayValue * 24 * 60 + startTimeValue;
    int endMinutes = endDayValue * 24 * 60 + endTimeValue;

    // Check if the end time is greater than or equal to the start time
    if (endMinutes <= startMinutes)
    {
        return -1; // Return -1 to indicate an invalid duration
    }

    int stayDuration = endMinutes - startMinutes;
    return stayDuration;
}

int invalidTime(const string &schedule)
{
    ifstream file(schedule);
    int count = 0;
    int numberOfShips;

    // Read the line containing "Number of ships:"
    string line;
    getline(file, line);

    // Use stringstream to extract the number of ships
    istringstream iss(line);
    string shipsIdentifier;
    iss >> shipsIdentifier >> numberOfShips;

    // Check if the extraction was successful and shipsIdentifier is "Number"
    if (iss.fail() || shipsIdentifier != "Number")
    {
        cerr << "Error: Invalid format in the first line of " << schedule << endl;
        return 6;
    }

    // Skip the newline after numberOfShips
    file.ignore(numeric_limits<streamsize>::max(), '\n');

    string longestShipName = "";
    int longestDuration = -1;

    for (int i = 0; i < numberOfShips; ++i)
    {
        string shipInfo;
        getline(file, shipInfo);

        // Using stringstream to extract ship information
        stringstream shipStream(shipInfo);
        string shipName, startDay, startTime, endDay, endTime;

        // Extract ship information
        shipStream >> shipName >> startDay >> startTime >> endDay >> endTime;

        // Example: Check if shipName is valid (contains only letters and numbers)
        for (char &c : shipName)
        {
            if (!isalnum(c))
            {
                count++;
                cerr << "Invalid ship: " << shipName << " in " << schedule << endl;
                break;
            }
        }

        // Other checks...

        // Calculate the stay duration in minutes
        int stayDuration = calculateStayDuration(startDay, startTime, endDay, endTime);

        // Update the longest stay duration and ship name if needed
        if (stayDuration > longestDuration)
        {
            longestDuration = stayDuration;
            longestShipName = shipName;
        }
    }

    file.close(); // Close the file after reading

    // Print the result
    cout << "numInvalid: " << count << endl;
    if (longestDuration != -1)
    {
        cout << "longestDurationShip: " << longestShipName << endl;
    }
    else
    {
        cout << "longestDurationShip:" << endl;
    }

    return count;
}

string longestDuration(const string &schedule)
{
    ifstream file(schedule);
    int numberOfShips;

    // Read the line containing "Number of ships:"
    string line;
    getline(file, line);

    // Use stringstream to extract the number of ships
    istringstream iss(line);
    string shipsIdentifier;
    iss >> shipsIdentifier >> numberOfShips;

    if (iss.fail() || shipsIdentifier != "Number")
    {
        // Invalid format in the first line of the schedule file
        cerr << "Error: Invalid format in the first line of " << schedule << endl;
        return "";
    }

    file.ignore(numeric_limits<streamsize>::max(), '\n'); // Skip the newline after numberOfShips

    string longestShipName = "";
    int longestDuration = -1;

    for (int i = 0; i < numberOfShips; ++i)
    {
        string shipInfo;
        getline(file, shipInfo);

        // Using stringstream to extract ship information
        stringstream shipStream(shipInfo);
        string shipName, startDay, startTime, endDay, endTime;

        // Extract ship information
        shipStream >> shipName >> startDay >> startTime >> endDay >> endTime;

        // Calculate the stay duration in minutes
        int stayDuration = calculateStayDuration(startDay, startTime, endDay, endTime);

        // Update the longest stay duration and ship name if needed
        if (stayDuration > longestDuration || longestDuration == -1)
        {
            longestDuration = stayDuration;
            longestShipName = shipName;
        }
    }

    file.close(); // Close the file after reading

    // Print the result
    cout << "numInvalid: 0" << endl;
    if (longestDuration != -1)
    {
        cout << "longestDurationShip: " << longestShipName << endl;
    }
    else
    {
        cout << "longestDurationShip:" << endl;
    }

    return longestShipName;
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
