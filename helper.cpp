#include <iostream>
#include <sstream>
#include <string> 
#include <vector>
#include "helper.h"

using namespace std;

void askToStopInput(bool* isUserInputValues)
{
    string answer 
        = askFor("Want to continue input values? [y/n]: ", {"n", "y"});

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

        for(int i = 0; i < compareTo.size(); i++)
            if (userInput == compareTo.at(i))
                isCorrectAnswer = true;
    }

    return userInput;
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