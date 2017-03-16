#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<fstream>

using namespace std;
int num[1001];

int main()
{
fstream cin("A-large (1).in",ios::in);
fstream cout("A-large (1).out",ios::out);
int t;
cin>>t;int q=1;
while(t--)
{
    int n;
 cin>>n;
 cin>>num[1];
 int maxx=0;
 int ans=0;
 for (int i=2;i<=n;i++)
   {
      cin>>num[i];
      if ((num[i-1]-num[i])>maxx)  maxx=num[i-1]-num[i];
      ans=ans+((num[i-1]-num[i])>0?num[i-1]-num[i]:0);
   }
 int ans1=0;
 int t=maxx;
 for (int i=1;i<n;i++)
 {
     ans1=ans1+((t<num[i])?t:num[i]);

 }

  cout<<"Case #"<<q++<<": "<<ans<<" "<<ans1<<endl;
}
return 0;
}
