#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

void f(int, Intercept<int>);
Intercept<int> sum(0, 3), res(1, 3);
int main()
{
	Intercept<int> n, a, i, j;
	cin >> n;
	for (i = Intercept<int>(0, 2); i < n; i++) //n???
	{
		res = 1; //??????a=a
		cin >> a;
		for (j = Intercept<int>(2, 2); j <= (int)sqrt((float)a); j++) //??????
		{
			if (a % j == 0)
			{
				sum = 0;
				f(a / j, j); //????????
				res += sum;
			}
		}
		cout << res << endl;
	}
	return 0;
}
void f(int x, Intercept<int> y)
{
	y = Intercept<int>(y, 2);

	if (x == 1)
		sum++;
	while (y <= x) //?????????????
	{
		if (x % y == 0)
			f(x / y, y);
		y++;
	}
	return;
}
