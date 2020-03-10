#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

/*Intercept<int> hf[32768][32768]={0};
Intercept<int> work(Intercept<int> m,Intercept<int> n)
{
	if(hf[m][n]!=0)
	return hf[m][n];
	if(m%n!=0)
	{
		hf[m][n]=0;
		return 0;
	}
	for(Intercept<int> i=n;i<=m/n;i++)
	hf[m][n]+=work(m/n,i);
	return hf[m][n];
}*/
Intercept<int> work(Intercept<int> m, Intercept<int> n)
{
	if (m == n)
		return 1;
	if (m % n != 0)
		return 0;
	Intercept<int> sum(0, 3);
	for (Intercept<int> i(n, 2); i <= m / n; i++)
		sum += work(m / n, i);
	return sum;
}
int main()
{
	Intercept<int> n, m, a;
	cin >> n;
	Intercept<int> i, j, k;
	for (i = Intercept<int>(1, 2); i <= n; i++)
	{
		cin >> m;
		Intercept<int> s(0, 3);
		for (j = Intercept<int>(2, 2); j <= m; j++)
			s += work(m, j);
		cout << s << endl;
	}
	return 0;
}
