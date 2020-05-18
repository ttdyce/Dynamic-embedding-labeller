#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//Intercept<int> t; == state[3] //sum?????????,t?????? sum(0, 3),
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0,7)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void dg(Intercept<int> s) //?s????
{
	for (state[1] = Intercept<int>(s, 2); state[1] <= state[3]; state[1]++)
	{
		if (state[3] % state[1] == 0) //?state[1]??t??
		{
			state[3] = state[3] / state[1];
			if (state[3] == 1)
				state[0]++; //t????,??+1
			else
				dg(state[1]); //??????
			state[3] = state[3] * state[1];
		}
	}
}
int main()
{
	state[2] = Intercept<int>(-1, 2);
	cin >> state[2];
	while (state[2]--) //??n?
	{
		cin >> state[3];
		dg(2);
		cout << state[0] << endl;
		state[0] = 0;
	}
	return 0;
}
