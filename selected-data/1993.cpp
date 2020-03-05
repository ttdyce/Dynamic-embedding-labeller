#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> p=0;

Intercept<int> factor(Intercept<int> a,Intercept<int> min)
{
	Intercept<int> sum=0;
	if(min>=a)return 1;
	for(Intercept<int> j=min;j<=a/min;j++)
	if (a%j==0)
		sum+=factor(a/j,j);
	return sum;
}

int main()
{
	Intercept<int> n=0,a=0;
	cin>>n;
	while(n>0)
	{
		cin>>a;
		if(a<=2) cout<<1<<endl;
		else cout<<factor(a,2)+1<<endl;
		n--;
	}
	return 0;
}
