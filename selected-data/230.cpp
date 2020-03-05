#include <iostream>
#include <stdio.h>
#include <math.h>
#include "../Intercept.cpp"
#include <string.h>
using namespace std;

//???? 
Intercept<int> divide(Intercept<int> n,Intercept<int> i);   //????   n???????i????????? 
int main()
{
    Intercept<int> n=0;  //????? 
    Intercept<int> t=0;  //???? 
    Intercept<int> sum;  //??????? 
    cin>>t;  
    for(Intercept<int> i=0;i<t;i++)
    {
        sum=0;
        cin>>n;
        for(Intercept<int> j=2;j<=n/2;j++)   //???????????1*n??? 
        {
            sum=sum+divide(n,j);
        }
        cout<<sum+1<<endl;
    }
    return 0;
}
Intercept<int> divide(Intercept<int> n,Intercept<int> i)   //???????????????1??? 
{
    Intercept<int> num=0;
    if(n%i==0)
    {
        if(n==i)      //?????????????????1 
        {
            return 1;
        }
        for(Intercept<int> j=2;j<=i;j++)
        {
             num=num+divide(n/i,j);   //?? 
        }
           return num;
    }
        
    else
    {
        return 0;
    }               
}
