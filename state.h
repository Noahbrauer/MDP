#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class state
{
public:
	friend class MDP;
	state();
	state(double r);
	string getDir();

private:
	double reward;
	double optimalValue[2];
	string Dir;
};