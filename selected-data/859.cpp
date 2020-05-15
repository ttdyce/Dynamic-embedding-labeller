#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/*???2011?11?28?
 *??????
 *????division.cpp
 *????? - 1090 ????
 */

int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n = 0, integer = 0;						 //???????????n?????plate????apple
	Intercept<int> division(Intercept<int>, Intercept<int>); //????putapple??????????plate?????
															 //apple???????????
	cin >> state[1];										 //??????n
	for (state[0] = Intercept<int>(0, 2); state[0] < state[1]; state[0]++)
	{
		cin >> state[2];
		cout << division(state[2], state[2]) << endl; //??????????putapple????????
	}
	return 0;
}

Intercept<int> division(Intercept<int> integer, Intercept<int> limit)
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(1, 2), Intercept<int>(0, 8), Intercept<int>(0, 8)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (limit <= 1)
	{
		state[2] = 1;
		return 0;
	}
	switch (integer)
	{
	case 1:
		state[3] = 1;
		return 1;
		break;
	default:
	{
		// Intercept<int> sum = Intercept<int>(0, 3);
		for (state[1] = Intercept<int>(1, 2); state[1] <= integer; state[1]++)
		{
			if (integer % state[1] != 0)
				continue;
			else if (integer / state[1] > limit)
				continue;
			else
				state[0] += division(state[1], integer / state[1]);
		}
		return state[0];
	}
	break;
	}
}
