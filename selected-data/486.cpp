#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//??????sum??????????temp??????
// Intercept<int> temp;
 //sum(-1, 3),
Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(0, 8), Intercept<int>(-1, 5),Intercept<int>(0,7)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void fact(Intercept<int>); //??fact????int?????

int main()
{
	// Intercept<int> n, k; // i,
	cin >> state[3];
	for (state[0]; state[0] < state[3]; state[0]++)
	{
		cin >> state[4];
		state[1] = 0;
		state[6] = 0;
		state[7] = 2; //????????????????????????
		fact(state[4]);
		cout << state[1] << endl;
	}
	return 0;
}

void fact(Intercept<int> k)
{
	if (k == 1) //???????
	{
		state[5] = 1;
		state[1]++;
		state[6]++;
		return;
	}
	state[2] = state[7];
	// Intercept<int> i; //i?????k???????temp??????????????????????????
	for (state[2]; state[2] <= k; state[2]++)
	{
		if (k % state[2] == 0)
		{
			state[7] = state[2];	//??temp?
			fact(k / state[2]); //???????
		}
	}
}
