#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;


Intercept<int> devide(Intercept<int> n,Intercept<int> m)
{
	if(n<m)
		m=n;
	if(n==1)//?????1?,??1
		return 1;
	Intercept<int> sum=0;
	for(Intercept<int> i=m;i>=2;i--)
	{
		if(n%i==0)
		{
			sum=sum+devide(n/i,i);
		}
		
	}
	return sum;
}

int main()
{
	Intercept<int> n,i,m;
	cin>>n;
	i=0;
	while ( i<n )
	{
		cin>>m;
		cout<<devide (m,m)<<endl;//???????
		i++;
	}
	return 0;

}
