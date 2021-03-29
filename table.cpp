#include <iostream>
#include <iomanip>
#include <sstream>
#include "table.h"

using namespace std;

char lineVertical = char(186);
char lineVerticalThin = char(179);
char lineHorizontal = char(205);
char lineHorizontalThin = char(196);
char lineEdgeHorToVertTop = char(187);
char lineEdgeVertToHorTop = char(201);
char lineEdgeHorToVertBottom = char(188);
char lineEdgeVertToHorBottom = char(200);
char lineVertToMiddleHorRight = char(204);
char lineVertToMiddleHorRightThin = char(199);
char lineVertToMiddleHorLeft = char(185);
char lineVertToMiddleHorLeftThin = char(182);
char lineHorToMiddleVertDown = char(203);
char lineHorToMiddleVertTop = char(202);
char lineCross = char(206);
char lineCrossThinHor = char(215);

int widthAdditionalSpacer = 3;

void printCell(string& text, int& width);
void printDividerThin(vector<int>& widths);
void printVerticalDivider();
void printVerticalDividerThin();
void newLine();
void printTopEdgeOfChart(vector<int>& widths);
void printDownEdgeOfChart(vector<int>& widths);
void printDivider(vector<int>& widths);
void printDividerThin(vector<int>& widths);

void getWidths(vector<vector<string>>* items, vector<int>* widths);

void createChart(vector<vector<string>> items)
{
    vector<int> widths = {};

    getWidths(&items, &widths);

    printTopEdgeOfChart(widths);

    for (int i = 0; i < items.size(); i++)
    {
        vector<string> columns = items.at(i);
        printVerticalDivider();

        for (int j = 0; j < columns.size(); j++)
        {
            printCell(columns.at(j), widths.at(j));
            printVerticalDivider();
        }
        newLine();

        if (i != items.size() - 1)
            printDividerThin(widths);
    }

    printDownEdgeOfChart(widths);
}

void getWidths(vector<vector<string>>* items, vector<int>* widths)
{
    for (int i = 0; i < items->size(); i++)
    {
        vector<string> columns = items->at(i);
        for (int j = 0; j < columns.size(); j++)
        {
            if (widths->size() <= j)
                widths->push_back(0);

            if (widths->at(j) < columns.at(j).length())
                widths->at(j) = columns.at(j).length() + widthAdditionalSpacer;
        }
    }
}

void printCell(string& text, int& width)
{
    cout << setw(width) << setfill(' ') << left << text;
}

void printVerticalDivider() 
{
    cout << lineVertical;
}

void printVerticalDividerThin()
{
    cout << lineVerticalThin;
}

void newLine()
{
    cout << endl;
}

void printDivider(vector<int>& widths)
{
    string centerString = "";

    centerString.push_back(lineVertToMiddleHorRight);

    for (int i = 0; i < widths.size(); i++)
    {
        centerString.append(widths.at(i), lineHorizontal);

        if (i == widths.size() - 1)
            centerString.push_back(lineVertToMiddleHorLeft);
        else
            centerString.push_back(lineCross);
    }

    cout << centerString << endl;
}

void printDividerThin(vector<int>& widths)
{
    string centerString = "";

    centerString.push_back(lineVertToMiddleHorRightThin);

    for (int i = 0; i < widths.size(); i++)
    {
        centerString.append(widths.at(i), lineHorizontalThin);

        if (i == widths.size() - 1)
            centerString.push_back(lineVertToMiddleHorLeftThin);
        else
            centerString.push_back(lineCrossThinHor);
    }

    cout << centerString << endl;
}

void printTopEdgeOfChart(vector<int>& widths)
{
    string centerString = "";

    centerString.push_back(lineEdgeVertToHorTop);

    for (int i = 0; i < widths.size(); i++)
    {
        centerString.append(widths.at(i), lineHorizontal);

        if(i == widths.size() - 1)
            centerString.push_back(lineEdgeHorToVertTop);
        else
            centerString.push_back(lineHorToMiddleVertDown);
    }
    
    cout << centerString << endl;
}

void printDownEdgeOfChart(vector<int>& widths)
{
    string centerString = "";

    centerString.push_back(lineEdgeVertToHorBottom);

    for (int i = 0; i < widths.size(); i++)
    {
        centerString.append(widths.at(i), lineHorizontal);

        if (i == widths.size() - 1)
            centerString.push_back(lineEdgeHorToVertBottom);
        else
            centerString.push_back(lineHorToMiddleVertTop);
    }

    cout << centerString << endl;
}