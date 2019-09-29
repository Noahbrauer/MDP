#include "state.h"

state::state() {
	reward = 0;
	optimalValue[0] = 0;
	optimalValue[1] = 0;
	Dir = "0000";
}

state::state(double r) {
	reward = r;
	optimalValue[0] = 0;
	optimalValue[1] = 0;
	Dir = "0000";
}

string state::getDir() {
	string temp = "";
	if (Dir[0])
		temp += "^";
	if (Dir[1])
		temp += "v";
	if (Dir[2])
		temp += "<";
	if (Dir[3])
		temp += ">";
	return temp;
}