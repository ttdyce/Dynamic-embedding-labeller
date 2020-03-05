#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

//********************************
//*???1.cpp   **
//*?????? 1200012768 **
//*???2012.11.28  **
//*???????  **
//********************************
Intercept<int> fun(Intercept<int> n, Intercept<int> m);
int main()
{
	Intercept<int> n, num;
	cin >> n;
	for (Intercept<int> i = 0; i < n; i++)
	{
		cin >> num;
		cout << fun(num, 2) << endl;
	}
	return 0;
}
Intercept<int> fun(Intercept<int> n, Intercept<int> m)
{
	Intercept<int> sum = 1;					//n?????????? 
	double t = sqrt(n);
	for (Intercept<int> i = m; i <= t; i++)	//???????????????t 
		if (n % i == 0)				//???i?n??????????? 
			sum += fun(n /i, i);
	return sum;
}
