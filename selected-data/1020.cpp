#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(0, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void f(Intercept<int> a, Intercept<int> s)
{
	// Intercept<int> i;
	if (a == 1)
	{
		state[0]++;
		state[5]++;
	}
	else
	{

		for (state[1] = Intercept<int>(s, 2); state[1] <= a; state[1]++)
		{
			if (a % state[1] == 0)
				f((a / state[1]), state[1]);
		}
	}
	return;
}

int main()
{
	// Intercept<int> n, num; //, j
	cin >> state[3];
	for (state[2] = Intercept<int>(1, 2); state[2] <= state[3]; state[2]++)
	{
		cin >> state[4];
		f(state[4], 2);
		printf("%d\n", state[0]);
		state[0] = 0;
		state[5] = 0;
	}
	return 0;
}
