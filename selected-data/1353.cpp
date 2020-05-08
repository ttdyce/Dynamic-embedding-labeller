#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//********************************
//*???1.cpp   **
//*?????? 1200012768 **
//*???2012.11.28  **
//*???????  **
//********************************
Intercept<int> fun(int n, Intercept<int> m);
int main()
{
	Intercept<int> intercepts[] = {Intercept<int>(0, 2), Intercept<int>(0, 4), Intercept<int>(0, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> n, num;
	cin >> state[1];
	for (state[0] = Intercept<int>(0, 2); state[0] < state[1]; state[0]++)
	{
		cin >> state[2];
		cout << fun(state[2], 2) << endl;
	}
	return 0;
}
Intercept<int> fun(int n, Intercept<int> m)
{
	Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

	// Intercept<int> sum(1, 3); //n??????????
	double t = sqrt(n);
	for (state[1] = Intercept<int>(m, 2); state[1] <= t; state[1]++) //???????????????t
		if (n % state[1] == 0)										 //???state[1]?n???????????
			state[0] += fun(n / state[1], state[1]);
	return state[0];
}
