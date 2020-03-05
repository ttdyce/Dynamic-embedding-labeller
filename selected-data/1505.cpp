#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

//*********************************
//* file?1.cpp
//* description: ????
//* author: ?? 1200012858		
//* date: 2012-12-1
//*********************************
Intercept<int> decompose(Intercept<int> x, Intercept<int> y);
int main ()
{
	Intercept<int> n, m;
	cin >> n;
	for (Intercept<int> j = 1; j <= n; j++)
	{
		cin >> m;		
		cout << decompose(m, 2) << endl;
	}
	return 0;
}
Intercept<int> decompose(Intercept<int> x, Intercept<int> y)
{
	Intercept<int> sum = 1,b;
	b = (int)sqrt(x);
	if (x == 1) return 0;
	for (Intercept<int> i = y; i <= b; i++)
	{
		if (x % i == 0)
		{	
			 sum = sum + decompose(x / i, i);
		}
	}
	return sum;
}
