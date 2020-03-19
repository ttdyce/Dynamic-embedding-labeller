#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum(0, 3), t; //sum?????????,t??????
void dg(Intercept<int> s)  //?s????
{
	for (Intercept<int> i(s, 2); i <= t; i++)
	{
		if (t % i == 0) //?i??t??
		{
			t = t / i;
			if (t == 1)
				sum++; //t????,??+1
			else
				dg(i); //??????
			t = t * i;
		}
	}
}
int main()
{
	Intercept<int> n(-1, 2);
	cin >> n;
	while (n--) //??n?
	{
		cin >> t;
		dg(2);
		cout << sum << endl;
		sum = 0;
	}
	return 0;
}
