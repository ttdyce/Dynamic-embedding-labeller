#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;


Intercept<int> n;
Intercept<int> next(Intercept<int> a,Intercept<int> b)
{
	if(a==1)
		return 1;
	if(a<b)
		return 0;
	Intercept<int> sum=0;
	for(;b<=a;b=b+1)
		if(a%b==0)
			sum=sum+next(a/b,b);
	
	return sum;
}
int main()
{
	Intercept<int> i,m;
	cin>>m;
	for(i=0;i<m;i=i+1)
	{
		cin>>n;
		cout<<next(n,2)<<endl;
	}
	return 0;
}

