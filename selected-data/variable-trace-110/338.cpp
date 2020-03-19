#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

void fenjie(Intercept<int>, Intercept<int>, Intercept<int>);
Intercept<int> g_num, g_count;
int main()
{
	Intercept<int> n, i(-1, 2);
	cin >> n;
	for(i = 1; i <= n; i++ )
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
	a = Intercept<int>(a, 2);
	sum = Intercept<int>(sum, 3);
	while( a <= g_num )
	{
		sum *= a;
		if( sum == g_num )
			g_count++;
		if( sum < g_num )
			fenjie(a, g_num, sum);
		if( sum > g_num )
			return;
		sum /= a;
		a++;
	}
}
