#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int>, Intercept<int>); //????
int main()					//?????
{							//?????

	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> i, a[50]; //n, 
	cin >> state[1]; //??????
	for (state[0]; state[0] < state[1]; state[0]++)
	{
		cin >> a[state[0]];				//????
		cout << f(a[state[0]], 2) << endl; //????
	}
	return 0; //???????????????????
} //?????

Intercept<int> f(Intercept<int> n, Intercept<int> p) //??????????????p?????

{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(p, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum(0,3), m;
	if (n < p)
		return 0;
	else
	{
		for (state[1]; state[1] <= n; state[1]++)
			if (n % state[1] == 0)
			{
				if (state[1] < n)
					state[0] = state[0] + f(n / state[1], state[1]); //n?????state[1]??????n/state[1]??????state[1]???????
				if (state[1] == n)
					state[0] = state[0] + 1; //n?????n??????1
			}
		return state[0];
	}
}
