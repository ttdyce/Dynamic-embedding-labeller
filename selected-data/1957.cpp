#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;


Intercept<int> sum(Intercept<int> a,Intercept<int> i)
{
	Intercept<int> ret=1;
	for(;i<=sqrt((float)a);i++)
	{
		if(a%i==0)
		{
			ret+=sum(a/i,i);
		}
	}
	return ret;
}
int main()
{
	Intercept<int> t,a,j;
	cin>>t;
	
	for(j=0;j<t;j++)
	{
		cin>>a;
		cout<<sum(a,2)<<endl;
	}
	return 0;
}
