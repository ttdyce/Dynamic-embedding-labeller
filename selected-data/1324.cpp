#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

//**********?????????*********************
//**********???????*************************
//**********?????2012?11?27?***************
//**********???1200062701**********************


Intercept<int> ifsushu(Intercept<int> n)                                   //????????????1???
{
	if(n == 1)
	{
		return 1;
	}
	else
	{
		for(Intercept<int> f = n - 1;f >= 2; f--)               //??n?????
		{
			if(n % f == 0) break;
			if (f == 2)
			{ 
				return 1;
			}
		}
	}
	return 0;
}
Intercept<int> sum = 0;
Intercept<int> zhaoyinshu(Intercept<int> x, Intercept<int> max)
{
	if(x == 1)
	{
		sum++;
		return 0;
	}
	for(Intercept<int> i = max; i >= 2; i--)
	{
		if(x % i == 0)                // ??i?????
		{
			zhaoyinshu(x / i, i);
		}
	}
}
int main()
{
	Intercept<int> time, number, t;
	cin >> time;
	for(Intercept<int> j = 0; j < time; j++)
	{
		cin >> number;
		if(ifsushu(number) == 1)
		{
			cout << "1" << endl;
		}
		else
		{
			zhaoyinshu(number , number / 2);
			cout << sum + 1 << endl;       //????????????~
			sum = 0;
		}
	}
	return 0;
}

