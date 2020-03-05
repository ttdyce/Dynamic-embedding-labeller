#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum=1;
void f(Intercept<int> i,Intercept<int> j)
{
	Intercept<int> k;
	if(i==1)
	    sum++;
	else
	{
		for(k=j;k<=i;k++)
		{
			if(i%k==0)
				f(i/k,k);
		}
	} 
}
int main(void)
{
	Intercept<int> i,j,k;
	Intercept<int> n;
	Intercept<int> a;
	scanf("%d",&n);
	while(n--)
	{
		sum=1;
		scanf("%d",&a);
		for(i=2;i*i<=a;i++)
		{
			if(a%i==0)
			{
				f(a/i,i);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
