#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../StateIntercept.cpp"
#include <string.h>
using namespace std;

/*
 *?????
 *???2010 - 12 - 07
 *?????????  ????
 */
Intercept<int> num(Intercept<int>, Intercept<int>, Intercept<int>);
Intercept<int> qufen(Intercept<int>);
Intercept<int> power(Intercept<int>, Intercept<int>);
int main()
{
	Intercept<int> t(-1, 2);
	cin >> t;
	while (t >= 1)
	{
		Intercept<int> n, i(-1, 2), x, sum(1, 3);
		cin >> n;
		x = qufen(n); //qufen????????????????????
		for (i = 2; i <= x; i++)
			sum = sum + num(n, i, 2); //num?????????????i????????
		cout << sum << endl;
		t--;
	}
	return 0;
}
Intercept<int> qufen(Intercept<int> n)
{
	Intercept<int> j;
	for (j = Intercept<int>(1, 2);; j++)
	{
		if (power(2, j) > n)
		{
			return j - 1;
			break;
		}
	}
}
Intercept<int> power(Intercept<int> a, Intercept<int> b)
{
	Intercept<int> sum(1, 3), k(-1, 2);
	for (k = 1; k <= b; k++) //?????????
		sum = sum * a;
	return sum;
}
Intercept<int> num(Intercept<int> n, Intercept<int> g, Intercept<int> h)
{
	if ((g == 1) && (n >= h)) //???????
		return 1;
	Intercept<int> i(-1, 2), j = 0, count(0, 3), a[20000];
	for (i = h; i < n; i++) //???????????? n ?? i ?? g ??????n / i????? g - 1?
	{						//?n = i * ……?g?? ???? n / i = h * ……(g - 1 ???h??????i???
		if (n % i == 0)
		{
			a[j] = i;
			j++;
		}
	}
	if (j == 0) //j == 0?????????????????
		return 0;
	else
	{
		for (i = 0; i < j; i++)
			count = count + num(n / a[i], g - 1, a[i]);
		return count;
	}
}
