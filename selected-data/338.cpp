#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

void fenjie(Intercept<int>, Intercept<int>, Intercept<int>);
Intercept<int> g_num, g_count;
int main()
{
    int length = 1;
    Intercept<int> intercepts[length] = {Intercept<int>(-1, 2)};
    StateIntercept state(intercepts, length);

	Intercept<int> n; //, i(-1, 2);
	cin >> n;
	for(state[0] = 1; state[0] <= n; state[0]++ )
	{
		g_count = 0;
		cin >> g_num;
		fenjie(2, g_num, 1);
		cout << g_count << endl;
	}
	return 0;
}
void fenjie(Intercept<int> a, Intercept<int> num, Intercept<int> sum)
{
    int length = 2;
    Intercept<int> intercepts[length] = {Intercept<int>(a, 2), Intercept<int>(sum, 3)};
    StateIntercept state(intercepts, length);

	// a = Intercept<int>(a, 2);
	// sum = Intercept<int>(sum, 3);
	while( state[0] <= g_num )
	{
		state[1] *= state[0];
		if( state[1] == g_num )
			g_count++;
		if( state[1] < g_num )
			fenjie(state[0], g_num, state[1]);
		if( state[1] > g_num )
			return;
		state[1] /= state[0];
		state[0]++;
	}
}
