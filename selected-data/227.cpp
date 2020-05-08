#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(0, 3);                          //?????????????
void ways(Intercept<int> a, Intercept<int> last);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	Intercept<int> num[100]; //n, 
	cin >> state[2];
	for (state[1] = Intercept<int>(0, 2); state[1] < state[2]; state[1]++)
	{
		cin >> num[state[1]];
	}
	for (state[1] = 0; state[1] < state[2]; state[1]++)
	{
		ways(num[state[1]], 2);   //??????????
		cout << state[0] << endl; //??
		state[0] = 0;
	}
	return 0;
}
void ways(Intercept<int> a, Intercept<int> last)
{
	// Intercept<int> i(0, 2), j;
	Intercept<int> intercepts[1] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, 1);
	for (state[0] = last; state[0] <= a; state[0]++)
	{
		if (a < state[0]) //????????????????????????
		{
		}
		else if (a == state[0]) //???????????u?????
		{
			state[0]++;
		}
		else if (a % state[0] == 0) //????????????????????????????????
		{
			ways(a / state[0], state[0]);
		}
	}
}
