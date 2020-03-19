#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

//***************************************
//* ?????2010?12?01?            *
//* ?????????                  *
//* ?????         ???1000012902 *
//***************************************
Intercept<int> factors(Intercept<int>, Intercept<int>, Intercept<int>);                    //????factors?????????????
int main() 
{
	Intercept<int> num, n, i(-1, 2), j(-1, 2), b[10000];
	cin >> n;                                  //??????
	for (i = 0; i < n; i++) 
	{
		cin >> num;
		Intercept<int> part(0, 2);                          //??????????
		Intercept<int> t = num;                           //????

		//??????1????????????
		for (j = 2; j <= num; j++)
		{
			while (t % j == 0)
			{
				t /= j;
				part++;
			}
		}
		b[i] = factors(1, part, num);          //?????????????, ??????????
	}

	//?????????
	for (i = 0; i < n; i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}

//factor1????????????????????factor1, part??????????????????????????, num???????? 
Intercept<int> factors(Intercept<int> factor1, Intercept<int> part, Intercept<int> num)
{
	Intercept<int> sum(0, 3);                               //????????0, ???0
	if (num < factor1)                         //?????????????????, ???0?????????????
		return 0;
	if (part == 1)                             //?????????, ??1??????????
		return 1;

	//???????????????????????????????????????????, ????????
	for (Intercept<int> i = factor1; i <= num; i++)
		if (num % i == 0)
			sum = sum + factors(i, part - 1, num / i);
	return sum;
}
