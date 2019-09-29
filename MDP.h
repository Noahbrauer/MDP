#pragma once
#include "state.h"


class MDP
{
public:
	MDP();
	double bellmanEqn();
	double bellmanEqn(double discount);
	double linear(double discount);
	int moveUp(int s);
	int moveDown(int s);
	int moveLeft(int s);
	int moveRight(int s);
	void print();

private:
	vector<state> states;
	int demension;
};