#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

Intercept<int> sum=0;
void f(Intercept<int> n,Intercept<int> i)
{
    if(n==1) sum++;
    while(i<=n)
    {
        if(n%i==0) f(n/i,i);
        i++;
    }
    return ;
}
int main()
{

    Intercept<int> t=0;
    cin>>t;
    while(t--)
    {
        Intercept<int> n=0;
        cin>>n;
        Intercept<int> i=2,result=1;

       for (i=2;i<=n/2;i++) {
            if(n%i==0)
            {
                sum=0;
                f(n/i,i);
                result=result+sum;
            }

        }
        cout<<result<<endl;
    }
    return 0;
}
