#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

void f(int, Intercept<int>);
// Intercept<int> sum(0, 3), res(1, 3);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	Intercept<int> n, a, i, j;
	cin >> n;
	for (state[2] = Intercept<int>(0, 2); state[2] < n; state[2]++) //n???
	{
		state[1] = 1; //??????a=a
		cin >> a;
		for (state[3] = Intercept<int>(2, 2); state[3] <= (int)sqrt((float)a); state[3]++) //??????
		{
			if (a % state[3] == 0)
			{
				state[0] = 0;
				f(a / state[3], state[3]); //????????
				state[1] += state[0];
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
