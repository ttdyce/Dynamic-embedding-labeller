#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

//*************************************************
//*file: 1000012912_006.cpp                       *
//*author: ???                                 *
//*date?2010.12.01                               *
//*function?????                             *
//*************************************************
Intercept<int> sum(Intercept<int>);                      //sum??????????a=a?
Intercept<int> g_count(-1, 3), g_j;                        //count???-1,j?????
int main()
{
	// Intercept<int> n(-1, 1), a, i(-1, 2);      
	// Intercept<int> a;      
	Intercept<int> intercepts[] = {Intercept<int>(-1, 1), Intercept<int>(-1, 2), Intercept<int>(-1, 4)};
	StateIntercept state(intercepts, sizeof(intercepts) / sizeof(intercepts[0]));
	cin >> state[0];
	for ( state[1] = 0; state[1] < state[0]; state[1] ++ )
	{
		g_count = 0;
		g_j = 2;
		cin >> state[2];
		cout << sum(state[2]) + 1 << endl;
	}
	return 0;
}
Intercept<int> sum( Intercept<int> a)
{
	// Intercept<int> i(-1, 2), b(-1, 1);
	Intercept<int> intercepts[2] = {Intercept<int>(-1, 2), Intercept<int>(-1, 1)};
	StateIntercept state(intercepts, 2);
	
	state[1] = (int)sqrt( (double)a );
	for ( state[0] = g_j; state[0] <= state[1]; state[0]++ )           
	{
		if ( a % state[0] == 0 )                  //?a??i????????????1
		{
			g_j = state[0];                       //j??i???????
			g_count++;
			sum( a / state[0] );		
		}
	}
	return g_count;
}
	
