#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum=0; //??????sum????????
Intercept<int> yueshu[100]={0}; 
Intercept<int> s=0;

void number(Intercept<int> num,Intercept<int> s)
{
	Intercept<int> i;
	for(i=s;i>=0;i--)
	{
		if(num<yueshu[i])
			continue;
		if(num==yueshu[i])
			sum++;
		else if(num>yueshu[i]&&num%yueshu[i]==0)
			number(num/yueshu[i],i);
	}
}

int main()
{
	Intercept<int> n=0;
	cin>>n;
	Intercept<int> num=0;
	while(cin>>num)
	{
		Intercept<int> i=0,j=0;
		for(i=2;i<=num;i++)
			if(num%i==0)
			{
				yueshu[j]=i;
				j++;
			}
		s=j-1;
		number(num,s);
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
