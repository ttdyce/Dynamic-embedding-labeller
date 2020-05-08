#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/************************/
/*        ????      */
/*    ??? pyyaoer    */
/*   ??  2011.11.26   */
/************************/
void yinshu(Intercept<int>);
Intercept<int> j = 2; //sum(1, 3), 

Intercept<int> intercepts[] = {Intercept<int>(1, 3), Intercept<int>(0, 2), Intercept<int>(0, 2)};
StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));

int main()
{
	Intercept<int> n, m;
	// Intercept<int> i;
	cin >> n;
	for (state[1] = Intercept<int>(1, 2); state[1] <= n; state[1]++) //?i????
	{
		cin >> m;
		yinshu(m); //????
		cout << state[0] << endl;
		state[0] = 1, j = 2;
	}
	return 0;
}
void yinshu(Intercept<int> mm) //?????
{
	// Intercept<int> k;
	for (state[2] = Intercept<int>(j, 2); state[2] * state[2] <= mm; state[2]++) //????
	{
		if (mm % state[2] == 0)
		{
			state[0] = state[0] + 1;
			j = state[2];
			yinshu(mm / state[2]); //???????
		}
	}
}
