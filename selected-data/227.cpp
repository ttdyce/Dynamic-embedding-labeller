#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

// Intercept<int> sum(0, 3);                          //?????????????
void ways(Intercept<int> a, Intercept<int> last);
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 5)};
StateIntercept gState(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	Intercept<int> num[100]; //n, 
	cin >> gState[2];
	for (gState[1] = Intercept<int>(0, 2); gState[1] < gState[2]; gState[1]++)
	{
		cin >> num[gState[1]];
	}
	for (gState[1] = 0; gState[1] < gState[2]; gState[1]++)
	{
		ways(num[gState[1]], 2);   //??????????
		cout << gState[0] << endl; //??
		gState[0] = 0;
		gState[3] = 0;
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
			gState[0]++;
			gState[3]++;
		}
		else if (a % state[0] == 0) //????????????????????????????????
		{
			ways(a / state[0], state[0]);
		}
	}
}
