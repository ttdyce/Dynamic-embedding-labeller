#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(0, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void divide(Intercept<int> n, Intercept<int> a)
{
	for (state[1] = Intercept<int>(a, 2); state[1] <= n; state[1]++)
	{
		if ((n % state[1] == 0))
		{
			if (n / state[1] == 1){
				state[0]++;
				state[5]++;
			}else
				divide(n / state[1], state[1]);
		}
	}
}
int main()
{
	// Intercept<int> N = 0, n = 0;// , i(0, 2)
	cin >> state[3];
	for (state[2] = 0; state[2] < state[3]; state[2]++)
	{
		cin >> state[4];
		divide(state[4], 2);
		cout << state[0] << endl;
		state[0] = 0;
		state[5] = 0;
	}
	return 0;
}
