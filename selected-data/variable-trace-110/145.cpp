#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
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
	Intercept<int> n(-1, 1), a, i(-1, 2);                        //n????a?????
	cin >> n;
	for ( i = 0; i < n; i ++ )
	{
		g_count = 0;
		g_j = 2;
		cin >> a;
		cout << sum(a) + 1 << endl;
	}
	return 0;
}
Intercept<int> sum( Intercept<int> a)
{
	Intercept<int> i(-1, 2), b(-1, 1);
	b = (int)sqrt( (double)a );
	for ( i = g_j; i <= b; i++ )           
	{
		if ( a % i == 0 )                  //?a??i????????????1
		{
			g_j = i;                       //j??i???????
			g_count++;
			sum( a / i );		
		}
	}
	return g_count;
}
	
