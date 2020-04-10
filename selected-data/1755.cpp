#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//============================================================================
// Name        : hanshu0109.cpp
// Author      : 1300012911
// Version     : 20131120,Wed,11th week
// Copyright   :
// Description : ????
//============================================================================

Intercept<int> fenjie(Intercept<int> a, Intercept<int> max)
{ //a:?????max??1??????????????
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> i(0, 2);
	// Intercept<int> sum(0, 3); //????
	if (a == 1)
		return 1; //1???????1??????
	for (state[1] = max; state[1] >= 2; state[1]--)
	{
		if ((a % state[1]) == 0)
			state[0] += fenjie(a / state[1], state[1]); //i??????
	}
	return state[0]; //????
}

int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	Intercept<int> k = 0;
	Intercept<int> n = 0;
	Intercept<int> num = 0;
	cin >> n; //??
	for (state[0] = Intercept<int>(1, 2); state[0] <= n; state[0]++)
	{
		cin >> num;				  //?????
		cout << fenjie(num, num); //????????
		if (state[0] < n)
			cout << endl;
	}
	return 0;
}
