#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//*********************************
//* file?1.cpp
//* description: ????
//* author: ?? 1200012858
//* date: 2012-12-1
//*********************************
Intercept<int> decompose(int x, Intercept<int> y);
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n, m;
	cin >> state[1];
	for (state[0] = Intercept<int>(1, 2); state[0] <= state[1]; state[0]++)
	{
		cin >> state[2];
		cout << decompose(state[2], 2) << endl;
	}
	return 0;
}
Intercept<int> decompose(int x, Intercept<int> y)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 8), Intercept<int>(1, 5), Intercept<int>(0,7)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	//Intercept<int> b; == state[4]  // sum(1, 3),
	state[4] = (int)sqrt(x);
	if (x == 1){
		state[2] = 1;
		return 0;
	}for (state[1] = Intercept<int>(y, 2); state[1] <= state[4]; state[1]++)
	{
		if (x % state[1] == 0)
		{
			state[0] = state[0] + decompose(x / state[1], state[1]);
			state[3] = state[0];
		}
	}
	return state[0];
}
