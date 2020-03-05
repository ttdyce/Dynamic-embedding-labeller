#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

/* ????.cpp
 *  Created on: 2012-11-21
 *   Author: ??
 */
Intercept<int> ans(Intercept<int> a, Intercept<int> i) {//??????
	Intercept<int> sum = 0;//??
	for (Intercept<int> j = i; j <= sqrt(a); j++) {//?i???a??
		if (a % j != 0)
			continue;//??????
		sum++;//??????1
		if (a >= j * j)
			sum += ans(a / j, j);//????????????????????
	}
	return sum;
}
int main() {
	Intercept<int> n, a;//???????
	cin >> n;
	for (Intercept<int> i = 0; i < n; i++) {
		cin >> a;
		cout << ans(a, 2) + 1 << endl;
	}
	return 0;
}
