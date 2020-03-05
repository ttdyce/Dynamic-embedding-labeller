#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum=0;
Intercept<int> geshu(Intercept<int> a,Intercept<int> x)
{
	Intercept<int> y,z;
	z=a;
	y=(int)sqrt(a);
	while(x<=y)
	{
		if(a%x==0)
		{
			a=a/x;
			geshu(a,x);
		}
		if(a==z/x)
			a=z;
		x++;
	}
	sum++;
	return sum;
}
int main()
{
	Intercept<int> n,i,a[100],b[100],x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==2||a[i]==3)
			b[i]=1;
		else
		{
			sum=0;
			x=2;
			b[i]=geshu(a[i],x);
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",b[i]);
	}
}
