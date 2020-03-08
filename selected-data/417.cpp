#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum = Intercept<int>(0, 3); //???????
void fj(int n, Intercept<int> m)
{
	Intercept<int> i;			   //?????
	for (i = Intercept<int>(m, 2); i <= sqrt(n); i++) //???????
	{
		if (n % i == 0)
		{
			sum++;
			fj(n / i, i); //???????
		}
	}
}
int main()
{
	Intercept<int> j, N;   //??????????????
	Intercept<int> a[100]; //?????
	cin >> N;
	for (j = Intercept<int>(1, 2); j <= N; j++)
	{
		cin >> a[j]; //?????
	}
	for (j = 1; j <= N; j++)
	{
		sum = 0;
		fj(a[j], 2); //?????
		cout << sum + 1 << endl;
	}
	return 0;
}
