#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

void f(int, Intercept<int>);
// Intercept<int> sum(0, 3), res(1, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(1, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	// Intercept<int> n, a, i, j;
	cin >> state[5];
	for (state[2] = Intercept<int>(0, 2); state[2] < state[5]; state[2]++) //n???
	{
		state[1] = 1; //??????a=a
		state[7] = 1; //??????a=a
		cin >> state[6];
		for (state[3] = Intercept<int>(2, 2); state[3] <= (int)sqrt((float)state[6]); state[3]++) //??????
		{
			if (state[6] % state[3] == 0)
			{
				state[0] = 0;
				f(state[6] / state[3], state[3]); //????????
				state[1] += state[0];
				state[7] += state[0];
			}
		}
		cout << state[1] << endl;
	}
	return 0;
}
void f(int x, Intercept<int> y)
{
	state[4] = Intercept<int>(y, 2);

	if (x == 1)
		state[0]++;
	while (state[4] <= x) //?????????????
	{
		if (x % state[4] == 0)
			f(x / state[4], state[4]);
		state[4]++;
	}
	return;
}
