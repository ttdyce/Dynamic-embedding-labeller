#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum = 0;
void f(Intercept<int> a,Intercept<int> s)
{
	Intercept<int> i;
	if(a == 1)
		sum++;
	else
	{

		for(i = s; i <= a; i++)
		{
			if(a % i == 0)
				f((a / i),i);
		}
	}
	return;
}


int main()
{
	Intercept<int> n, num, j;
	cin >> n;
	for (j = 1; j <= n; j++)
	{
		cin >> num;
		f(num,2);
		printf("%d\n",sum);
		sum = 0;
	
	}
	return 0;
}
