#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

/*
 *?????
 *???2010 - 12 - 07
 *?????????  ????
 */
Intercept<int> num(int,int,int);
Intercept<int> qufen(int);
Intercept<int> power(int,int);
int main()
{
	Intercept<int> t;
	cin >> t;
	while(t >= 1)
	{
		Intercept<int> n,i,x,sum = 1;
		cin >> n;
		x = qufen(n);                  //qufen????????????????????
		for(i = 2; i <= x; i++)
			sum = sum + num(n,i,2);      //num?????????????i????????
		cout << sum << endl;
		t--;
	}
	return 0;
}
Intercept<int> qufen(Intercept<int> n)
{
	Intercept<int> j;
	for(j = 1; ; j++)
	{
		if(power(2,j) > n)
		{
			return j - 1;
			break;
		}
	}
}
Intercept<int> power(Intercept<int> a,Intercept<int> b)
{
	Intercept<int> sum = 1,k;
	for(k = 1; k <= b; k++)             //?????????
		sum = sum * a;
	return sum;
}
Intercept<int> num(Intercept<int> n,Intercept<int> g,Intercept<int> h)
{
	if((g == 1)&&(n >= h))          //???????
		return 1;
	Intercept<int> i,j = 0,count = 0,a[20000];  
	for(i = h; i < n; i++)                 //???????????? n ?? i ?? g ??????n / i????? g - 1?
	{                                      //?n = i * ��?g?? ???? n / i = h * ��(g - 1 ???h??????i???
		if(n % i == 0)
		{
			a[j] = i;
			j++;
		}
	}
	if(j == 0)                     //j == 0?????????????????
		return 0;
	else
	{
		for(i = 0; i < j; i++)
			count = count + num(n / a[i],g - 1,a[i]);
		return count;
	}
}
