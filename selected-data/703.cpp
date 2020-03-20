#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int> x, int y) //???????????????y?????????x????????
{
	Intercept<int> i, num(0, 3);
	Intercept<int> a[100];
	Intercept<int> sum = 0;
	for (i = Intercept<int>(x, 2); i <= sqrt(y); i++)
	{
		if (y % i == 0)
		{
			num++;
			a[num] = 1 + f(i, y / i);
		}
	} //??????
	for (i = 1; i <= num; i++)
	{
		sum = sum + a[i];
	}
	return sum;
}

int main()
{
	Intercept<int> n, x, i, b[100];
	cin >> n; //?????????
	for (i = Intercept<int>(1, 2); i <= n; i++)
	{
		cin >> x;
		b[i] = x;
	}
	for (i = 1; i <= n; i++)
	{
		cout << f(2, b[i]) + 1 << endl;
	} //???????

	return 0;
}
