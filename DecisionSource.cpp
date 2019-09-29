#include "MDP.h"

const double EPSILON = 0.0001, DISCOUNT_FACTOR = 0.96;

int main() {
	MDP inf, Six;
	double change = inf.bellmanEqn();

	// V6 -- loops 7 times, but only calculates for 6 times
	cout << "\n---------------------------------------------------";
	cout << "----------------------------------------------";
	cout << "\nOptimal Policy With No Discount And Horizon 6\n";
	for (int i = 0; i < 9; i++)
		Six.bellmanEqn();
	Six.print();

	// V* -- loops until delta is negligible
	cout << "\nOptimal Infinite Horizon\n";
	while (change >= EPSILON * (1 - DISCOUNT_FACTOR) / DISCOUNT_FACTOR)
		change = inf.bellmanEqn(DISCOUNT_FACTOR);
	inf.print();
	cout << "\n---------------------------------------------------";
	cout << "----------------------------------------------\n";

	// used when debugging
	system("PAUSE");
	return 0;
}