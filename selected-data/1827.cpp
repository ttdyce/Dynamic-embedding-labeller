#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> num = 0;
Intercept<int> sum(Intercept<int> a, Intercept<int> i)
{
	i = Intercept<int>(i, 2);

	if (a == 1)
	{
		num++;
	}
	else
	{
		while (i <= a)
		{
			if (a % i == 0)
			{
				sum(a / i, i);
			}
			i++;
		}
	}
	return num;
}
int main()
{
	Intercept<int> a, t, j, i, count;
	cin >> t;
	for (j = Intercept<int>(0, 2); j < t; j++)
	{
		count = 1;
		cin >> a;
		i = Intercept<int>(2, 2);
		while (i <= (a / 2))
		{
			if (a % i == 0)
			{
				num = 0;
				sum(a / i, i);
				count = count + num;
			}
			i++;
		}
		cout << count << endl;
	}

	return 0;
}
