#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> ways(Intercept<int>, Intercept<int>);
int main()
{
	Intercept<int> ways(Intercept<int> a, Intercept<int> min);
	Intercept<int> n(-1, 2),b;
	scanf("%d",&n);
	
	while(n-->0)
	{
		scanf("%d",&b);
		b = b + 1 - 1;
		printf("%d\n",ways(b,2));
	}
}			
Intercept<int> ways(Intercept<int> a, Intercept<int> min)
{
	if(a<min) return 0;
	Intercept<int> sum(0, 3), i(-1, 2);
	for(i=min;i<=sqrt(a*1.0);i++)
	{
		if(a%i == 0)
			sum = sum + ways(a/i, i);
	}
	return sum+1;
}
