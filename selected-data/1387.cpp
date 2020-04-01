#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> t; //sum?????????,t?????? sum(0, 3),
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void dg(Intercept<int> s) //?s????
{
	for (state[1] = Intercept<int>(s, 2); state[1] <= t; state[1]++)
	{
		if (t % state[1] == 0) //?state[1]??t??
		{
			t = t / state[1];
			if (t == 1)
				state[0]++; //t????,??+1
			else
				dg(state[1]); //??????
			t = t * state[1];
		}
	}
}
int main()
{
	state[2] = Intercept<int>(-1, 2);
	cin >> state[2];
	while (state[2]--) //??n?
	{
		cin >> t;
		dg(2);
		cout << state[0] << endl;
		state[0] = 0;
	}
	return 0;
}
