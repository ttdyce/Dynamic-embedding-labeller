#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//============================================================================
// Name        : 9.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

// Intercept<int> sum(0, 3); //????sum

void devide(Intercept<int> a, Intercept<int> b) //??
{
	if (a == 1){
		state[0]++;
		state[4]++;
	}else
	{
		if (a >= b)
			devide(a, b + 1);
		if (a % b == 0)
			devide(a / b, b);
	}
}

int main() //???
{
	// Intercept<int> n, a;
	cin >> state[2];
	for (state[1] = Intercept<int> (0, 2); state[1] < state[2]; state[1]++)
	{
		cin >> state[3];
		state[0] = 0;
		state[4] = 0;
		devide(state[3], 2);
		cout << state[0] << endl;
	}
	return 0;
}
