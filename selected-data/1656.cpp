#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> meide(Intercept<int> x,Intercept<int> y)
{
	Intercept<int> sum=1,count=0,i;
	for(i=y;i<=sqrt(x);i++)
	{
		if(x%i==0)
		{
			sum=sum+meide(x/i,i);
		}
	}
	return sum;
}
int main()
{
	Intercept<int> k,n,m;
	scanf("%d",&k);
	for(m=0;m<k;m++)
	{
		scanf("%d",&n);
		if(n>=3)
		{
		    printf("%d\n",meide(n,2));
		}
	    else
		{
		    printf("1\n");
		}
	}
	return 0;
}


