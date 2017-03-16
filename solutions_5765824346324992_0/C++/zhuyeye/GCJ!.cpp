#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<fstream>

using namespace std;
int peo[1001],sum[1001];

int gcd (int a,int b)
 {

     return b==0?a:gcd(b,a%b);
 }

long long lcm(int a,int b)
 {
     return ((long long)((a*b)/gcd(a,b)));

 }

int main()
{
fstream cin("B-small-attempt1 (2).in",ios::in);
fstream cout("B-small-attempt1 (2).out",ios::out);
int t;
cin>>t;int q=1;
while(t--)
{
    int  n,b;
 cin>>b>>n;
 cin>>peo[1];
 long long x=peo[1];
 for (int i=2;i<=b;i++)
   {
      cin>>peo[i];
      x=lcm(x,peo[i]);
   }
   long long cycle=0;
 for (int i=1;i<=b;i++)
 {
    cycle+=x/peo[i];

 }
 long long order=n%cycle;
 if (order==0) order=cycle;
 int cnt=0;
 int ans=0;
 memset(sum,0,sizeof sum);
 for (int t=1;t<=x;t++)
 {
     for (int i=1;i<=b;i++)
         if (sum[i]*peo[i]<t)
         {
             sum[i]++;
             cnt++;
             if (cnt==order)
                ans=i;
         }
     if (cnt>order) break;
 }

  cout<<"Case #"<<q++<<": "<<ans<<endl;
}
return 0;
}
