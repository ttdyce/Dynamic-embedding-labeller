#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> f(Intercept<int> num,Intercept<int> i)
{
	Intercept<int> sum;
	sum=0;
	Intercept<int> j;
		for(j=i;j<=num/2;j++)
		{
			if(num%j==0)
			{
				if(num/j<j)
				{
					sum=sum;
				}else{
					sum=1+sum+f(num/j,j);
				}
			}
		}
	return sum;
}
int main()
{
	Intercept<int> n,num,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		Intercept<int> j,sum;
		sum=0;
		j=2;
	        	sum+=f(num,j);
		printf("%d\n",sum+1);
	}
	return 0;
}
