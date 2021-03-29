#pragma once
#include <string> 
#include <vector>

using namespace std;

struct Substance {
	string name;
	double mass;

	//conductors, semiconductors, insulators
	string conductivity;
};

vector<Substance> getCachedSubstances();
vector<Substance> findSubstances(
	vector<Substance> substances, 
	string compareTo, 
	string searchType);
Substance inputSubstance();
void userInputSubstances(vector<Substance>* substances);
void userSearchForSubstances(vector<Substance>* substances);
void askToShowAllSubstances(vector<Substance>* substances);