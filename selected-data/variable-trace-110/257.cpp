#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sort(Intercept<int>, int, Intercept<int>);

int main()
{
	Intercept<int> t = 0;
	cin >> t;
	Intercept<int> k(1, 2);
	for (k = 1; k <= t; k++)
	{
		Intercept<int> vacancy = 0;
		Intercept<int> num = 1;
		cin >> num;
		Intercept<int> i(1, 2);
		Intercept<int> temp = num;
		for (i = 2; i <= temp; i++)
		{
			while (temp % i == 0)
			{
				vacancy = vacancy + 1;
				temp = temp / i;
			}
		}
		cout << sort(Intercept<int>(1), vacancy, num) << endl;
	}
	return 0;
}

Intercept<int> sort(Intercept<int> start, int vacancy, Intercept<int> num)
{
	if (num < start)
		return 0;

	if (vacancy == 1)
		return 1;

	Intercept<int> sum(0, 3);
	Intercept<int> i(1, 2);
	for (i = start; i <= num; i++)
	{
		if (num % i == 0)
		{
			sum = sum + sort(i, vacancy - 1, num / i);
		}
	}

	return sum;
}
