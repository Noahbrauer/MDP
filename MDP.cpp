#include "MDP.h"

// constructs the states and values given to them
MDP::MDP() {
	states.push_back(state(0));
	states.push_back(state(0));
	states.push_back(state(6));
	states.push_back(state(80));
	states.push_back(state(0));
	states.push_back(state(2));
	states.push_back(state(0));
	states.push_back(state(5));
	states.push_back(state(45));
	states.push_back(state(12));
	states.push_back(state(1));
	states.push_back(state(0));
	states.push_back(state(8));
	states.push_back(state(0));
	states.push_back(state(0));
	states.push_back(state(4));
	demension = 4;
}

// default constructor for bellman equation
double MDP::bellmanEqn() {
	return bellmanEqn(1);
}

// performs one iteration of the bellman equation
double MDP::bellmanEqn(double discount) {
	double change = 0;
	int sizeVal = states.size();
	for (int i = 0; i < sizeVal; i++) {	// sets all optimal
		states[i].optimalValue[0] = states[i].optimalValue[1];
	}

	for (int i = 0; i < sizeVal; i++) {
		double up, down, left, right, maximum;
		// finds values of all avaliable moves
		up = down = left = right = 0.1 * states[i].optimalValue[0];
		up += states[moveUp(i)].optimalValue[0] * 0.7 + states[moveDown(i)].optimalValue[0] * 0.2;
		down += states[moveDown(i)].optimalValue[0] * 0.7 + states[moveUp(i)].optimalValue[0] * 0.2;
		left += states[moveLeft(i)].optimalValue[0] * 0.7 + states[moveRight(i)].optimalValue[0] * 0.2;
		right += states[moveRight(i)].optimalValue[0] * 0.7 + states[moveLeft(i)].optimalValue[0] * 0.2;
		// gets maximum
		maximum = max(max(up, down), max(left, right));
		// next 4 are to know which direction to point
		states[i].Dir[0] = (maximum == up);
		states[i].Dir[1] = (maximum == down);
		states[i].Dir[2] = (maximum == left);
		states[i].Dir[3] = (maximum == right);
		// optimal
		states[i].optimalValue[1] = states[i].reward + discount * maximum;
		// change
		change = states[i].optimalValue[1] - states[i].optimalValue[0];
	}
	return change;
}

// the next four functions returns tile after movement, and if there is none, it returns itself
int MDP::moveUp(int s) {
	if (s - demension >= 0)
		return s - demension;
	return s;
}

int MDP::moveDown(int s) {
	int sizeVal = states.size();
	if (s + demension < sizeVal)
		return s + demension;
	return s;
}

int MDP::moveLeft(int s) {
	if (s % demension != 0)
		return s - 1;
	return s;
}

int MDP::moveRight(int s) {
	if ((s + 1) % demension != 0)
		return s + 1;
	return s;
}

// prints out the grid with values and the policy with arrows
void MDP::print() {
	int sizeVal = states.size();
	cout << "Values";
	for (int i = 0; i < sizeVal; i++) {
		if (i % demension == 0)
			cout << endl << "\t-----------------------------------------------------------------" << endl << "\t|\t";
		cout << states[i].optimalValue[0] << "\t|\t";
	}
	cout << endl << "\t-----------------------------------------------------------------" << endl;

	cout << "Optimal Policy";
	for (int i = 0; i < sizeVal; i++) {
		if (i % demension == 0)
			cout << endl << "\t-----------------------------------------------------------------" << endl << "\t|\t";
		cout << states[i].getDir() << "\t|\t";
	}
	cout << endl << "\t-----------------------------------------------------------------" << endl;
}