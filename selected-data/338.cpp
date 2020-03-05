#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

void fenjie(int, int, int);
Intercept<int> g_num, g_count;
int main()
{
	Intercept<int> n, i;
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
