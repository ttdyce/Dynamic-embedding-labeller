#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

/*???2011?11?28?
 *??????
 *????division.cpp
 *????? - 1090 ????
 */

int main()
{
	Intercept<int> n = 0, integer = 0; //???????????n?????plate????apple
	Intercept<int> division(Intercept<int>, Intercept<int>); //????putapple??????????plate?????
									   //apple???????????
	cin >> n;						   //??????n
	for (Intercept<int> i = Intercept<int>(0, 2); i < n; i++)
	{
		cin >> integer;
		cout << division(integer, integer) << endl; //??????????putapple????????
	}
	return 0;
}

Intercept<int> division(Intercept<int> integer, Intercept<int> limit)
{
	if (limit <= 1)
		return 0;
	switch (integer)
	{
	case 1:
		return 1;
		break;
	default:
	{
		Intercept<int> sum = Intercept<int>(0, 3);
		for (Intercept<int> a = Intercept<int>(1, 2); a <= integer; a++)
		{
			if (integer % a != 0)
				continue;
			else if (integer / a > limit)
				continue;
			else
				sum += division(a, integer / a);
		}
		return sum;
	}
	break;
	}
}
