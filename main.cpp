#include <iostream>
#include <stdio.h>
#include "main.h"
#include "table.h"
#include "helper.h"

int main()
{
    vector<Substance> substances;

    bool isProgrammRunning = true;
    bool isUsersValues;
    while (isProgrammRunning)
    {
        isUsersValues 
            = askFor("Use values from what?[custom/db]: ", 
                { "custom", "db" }) == "custom" 
            ? true 
            : false;

        cout << "\n";
        if (isUsersValues)
        {
            userInputSubstances(&substances);
        }

        if(!isUsersValues)
        {
            substances = getCachedSubstances();
            askToShowAllSubstances(&substances);
        }
        cout << "\n";


        userSearchForSubstances(&substances);

        isProgrammRunning 
            = askFor("Another try?[y/n]: ", { "y", "n" }) == "y" 
            ? true 
            : false;
        cout << "\n";

    }
    return 0;
}

Substance inputSubstance()
{
    Substance substance = Substance();
    cout << "Input name: ";
    cin >> substance.name;

    cout << "Input mass: ";
    cin >> substance.mass;
    
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Non number value. Try again: ";
        cin >> substance.mass;
    }

    string answer 
        = askFor("Input conductivity(conductor, semiconductor, insulator)[c/s/i]: ", 
            { "c", "s", "i" });

    if (answer == "c")
        substance.conductivity = "Conductor"; 
    if (answer == "s")
        substance.conductivity = "Semiconductor";
    if (answer == "i")
        substance.conductivity = "Insulator";

    return substance;
}

void userInputSubstances(vector<Substance>* substances) 
{
    bool isUserInput = true;

    while(isUserInput)
    {
        substances->push_back(inputSubstance());
        askToStopInput(&isUserInput);
    }
}

void userSearchForSubstances(vector<Substance>* substances)
{
    bool isSearching = true;
    string searchType;
    while (isSearching) 
    {
       searchType 
           = askFor("U can search by name/mass/conductivity[n/m/c]: ", 
               { "n", "m", "c" });
        
        string substanceFilter;
        if (searchType == "c")
        {
            string conductType 
                = askFor("Write search filter[c/s/i]: ", { "c", "s", "i" });
            if (conductType == "c")
                substanceFilter = "Conductor";
            if (conductType == "s")
                substanceFilter = "Semiconductor";
            if (conductType == "i")
                substanceFilter = "Insulator";
        }
        else
        {
            cout << "Write search filter: ";

            if (searchType == "m")
            {
                double substanceFilterDouble;
                cin >> substanceFilterDouble;
                while (!cin.good())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Non number value. Try again: ";
                    cin >> substanceFilterDouble;
                }
                substanceFilter = to_string(substanceFilterDouble);
            }
            else
            {
                cin >> substanceFilter;
            }
        }

        vector<Substance> substancesFinded 
            = findSubstances(*substances, substanceFilter, searchType);

        if (substancesFinded.size() == 0)
            cout << "No such substance. ";
        else
            createChart(castToStringVector(substancesFinded));

        isSearching 
            = askFor("Want search again?[y/n]: ", { "y", "n" }) == "y" 
            ? true 
            : false;
    }
}

void askToShowAllSubstances(vector<Substance>* substances)
{
    bool isShowTable 
        = askFor("Do u want to see all substances?[y/n]: ", { "y", "n" }) == "y"
        ? true 
        : false;

    if (isShowTable)
        createChart(castToStringVector(*substances));
}