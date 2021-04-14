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
            = askFor("Use values from what?[custom/db]<string>: ", 
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
            = askFor("Another try?[y/n]<string>: ", { "y", "n" }) == "y" 
            ? true 
            : false;
        cout << "\n";

    }
    return 0;
}

Substance inputSubstance()
{
    Substance substance = Substance();

    cout << "Input name<string>: ";
    cin >> substance.name;

    cout << "Input mass<double>: ";
    substance.mass = inputDoubleMass();

    string answer 
        = askFor("Input conductivity(conductor, semiconductor, insulator)[c/s/i]<string>: ", 
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
           = askFor("U can search by name/mass/conductivity[n/m/c]<string>: ", 
               { "n", "m", "c" });
        
        string substanceFilter;
        if (searchType == "c")
        {
            string conductType 
                = askFor("Write search filter[c/s/i]<string>: ", { "c", "s", "i" });
            if (conductType == "c")
                substanceFilter = "Conductor";
            if (conductType == "s")
                substanceFilter = "Semiconductor";
            if (conductType == "i")
                substanceFilter = "Insulator";
        }
        else
        {
            if (searchType == "m")
            {
                cout << "Write search filter<double>: ";
                substanceFilter = to_string(inputDoubleMass());                
            }
            else
            {
                cout << "Write search filter<string>: ";
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
            = askFor("Want search again?[y/n]<string>: ", { "y", "n" }) == "y" 
            ? true 
            : false;
    }
}

void askToShowAllSubstances(vector<Substance>* substances)
{
    bool isShowTable 
        = askFor("Do u want to see all substances?[y/n]<string>: ", { "y", "n" }) == "y"
        ? true 
        : false;

    if (isShowTable)
        createChart(castToStringVector(*substances));
}