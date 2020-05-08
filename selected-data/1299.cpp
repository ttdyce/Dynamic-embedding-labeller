#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> used[32770] = {0}; //????sum???????????used?i???i???????? sum(0, 3),
Intercept<int> intercepts[] = {Intercept<int>(0, 3), Intercept<int>(0, 2), Intercept<int>(0, 2), Intercept<int>(0, 4)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

void f(Intercept<int> n)					 //??f??n????????
{
	for (state[1] = Intercept<int> (2, 2); state[1] <= n; state[1]++)
	{
		if (n % state[1] == 0 && used[state[1]] == 0)
		{
			if (state[1] != 2)
			{
				for (Intercept<int> j(2, 2); j <= state[1] - 1; j++)
					used[j] = 1;
			}
			if (n / state[1] == 1) //??????????
			{
				state[0]++;
				break;
			}
			else
			{
				f(n / state[1]);
			}
			memset(used, 0, sizeof(used)); //?used???????
		}
	}
}
int main()
{
	Intercept<int> a[100]; // m,
	cin >> state[3];
	for (state[2] = Intercept<int>(1, 2); state[2] <= state[3]; state[2]++)
	{
		cin >> a[state[2]];
		if (a[state[2]] == 1)
			cout << 1 << endl;
		else
		{
			f(a[state[2]]);
			cout << state[0] << endl;
			state[0] = 0; //??
			memset(used, 0, sizeof(used));
		}
	}
	return 0;
}
