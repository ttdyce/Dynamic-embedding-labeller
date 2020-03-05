#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum=0;

void f(Intercept<int> x, Intercept<int> i)
{
	double m=sqrt(x);
	if(i<m)
	{
	if(x%i==0)
	{
		sum++;
		f(x/i,i);
	}
	f(x,i+1);
	}

	if(fabs(i-m)<0.00000001)
		sum++;



}


int main()
{
	Intercept<int> x,i,n;
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{scanf("%d",&x);
	sum=0;
	f(x,2);

	printf("%d\n",sum+1);
	}
	return 0;

}
