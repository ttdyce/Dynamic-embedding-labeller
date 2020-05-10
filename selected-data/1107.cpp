#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//????????????????????????????

//?a??????????min???
//?????????????
Intercept<int> F(Intercept<int> min, Intercept<int> a)
{
	// Intercept<int> i;
	// Intercept<int> sum(0, 3);
	Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 8), Intercept<int>(0, 8)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	if (min == a)
	{ //????????
		state[2] = 1;
		return 1;
	}
	if (a == 1)
	{
		state[3] = 1;
		return 1; //???????
	}
	for (state[1] = Intercept<int>(min, 2); state[1] <= a; state[1]++)
	{
		if (a % state[1] == 0)
			state[0] += F(state[1], a / state[1]); //??????????
	}
	return state[0]; //???
}

int main()
{
	// Intercept<int> a, n;
	// Intercept<int> i;
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	scanf("%d", &state[1]);
	for (state[0] = Intercept<int>(0, 2); state[0] < state[1]; state[0]++)
	{
		scanf("%d", &state[2]);
		printf("%d\n", F(2, state[2]));
	}
	return 0;
}
