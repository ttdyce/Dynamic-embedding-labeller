#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

//????????????????????????????

//?a??????????min???
//?????????????
Intercept<int> F(Intercept<int> min, Intercept<int> a)
{
	Intercept<int> i;
	Intercept<int> sum(0, 3);
	if (min == a) //????????
		return 1;
	if (a == 1)
		return 1; //???????
	for (i = Intercept<int>(min, 2); i <= a; i++)
	{
		if (a % i == 0)
			sum += F(i, a / i); //??????????
	}
	return sum; //???
}

int main()
{
	Intercept<int> a, n;
	Intercept<int> i;
	scanf("%d", &n);
	for (i = Intercept<int>(0, 2); i < n; i++)
	{
		scanf("%d", &a);
		printf("%d\n", F(2, a));
	}
	return 0;
}
