#include <iostream>
#include <sstream>
#include <string> 
#include <vector>
#include "helper.h"

using namespace std;

void askToStopInput(bool* isUserInputValues)
{
    string answer 
        = askFor("Want to continue input values? [y/n]<string>: ", {"n", "y"});

    if (answer == "n")
        *isUserInputValues = false;

    if (answer == "y")
        *isUserInputValues = true;
}

string askFor(string text, vector<string> compareTo) 
{
    bool isCorrectAnswer = false;
    string userInput;

    cout << text;

    while (!isCorrectAnswer)
    {
        cin >> userInput;

        try 
        {

            for (int i = 0; i < compareTo.size(); i++)
                if (userInput == compareTo.at(i))
                    isCorrectAnswer = true;
                
            if(!isCorrectAnswer)
                throw string("Incorrect input. Try again: ");
        }
        catch (string exc) 
        {
            cout << exc;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return userInput;
}

double inputDoubleMass()
{
    bool isValidValue = false;
    double value;

    while (!isValidValue)
    {
        cin >> value;

        try
        {
            if (!cin.good())
            {
                throw string("Non number value. Try again<double>: ");
                isValidValue = false;
            }
            else
            {
                //mass of substance can't be <= 0
                if (value <= 0)
                    throw string("Negative mass or 0? Try again: ");
                else
                    isValidValue = true;
            }

        }
        catch (string exc)
        {
            cout << exc;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return value;
}

vector<vector<string>> castToStringVector(vector<Substance> substances) 
{
    vector<vector<string>> list;

    list.push_back({ "Name", "Mass", "Conductivity"});

    for (int i = 0; i < substances.size(); i++)
    {
        list.push_back({ 
            substances.at(i).name, 
            to_string(substances.at(i).mass), 
            substances.at(i).conductivity });
    }

    return list;
}