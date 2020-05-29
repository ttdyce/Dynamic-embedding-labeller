#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//*************************************************************************
//*????????? *****************************************************
//*??????? 1200012979 **********************************************
//*???2012.11.27 *******************************************************
//*************************************************************************
void breakup(Intercept<int>, Intercept<int>);
// Intercept<int> sum(-1, 3);
Intercept<int> intercepts[] = {Intercept<int>(-1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4), Intercept<int>(-1, 5)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	// Intercept<int> n, x; //, count(0, 2)
	cin >> state[3]; //??????
	while (state[1] < state[3])
	{
		state[0] = 0;
		state[5] = 0;
		state[1]++;		 //?????
		cin >> state[4]; //??????
		if (state[4] > 3)
			breakup(state[4], 2); //????
		state[5] += 1;
		cout << state[5] << endl; //???????????
	}
	return 0;
}

void breakup(Intercept<int> x, Intercept<int> j)
{
	Intercept<int> interceptss[] = {Intercept<int>(0, 7),Intercept<int>(0,7)};
	StateIntercept states(interceptss, sizeof(interceptss) / sizeof(interceptss[0]));

	//Intercept<int> p; == states[1] //m; == states[0] //i,
	states[0] = x;				 //???????
	states[1] = sqrt((double)x); //p??????????
	for (state[2] = Intercept<int>(j, 2); state[2] <= states[1]; state[2]++)
		if (states[0] % state[2] == 0) //????????????????
		{
			state[0]++; //??????
			state[5]++; //??????
			x = states[0] / state[2];
			breakup(x, state[2]);
		}
	return;
}
