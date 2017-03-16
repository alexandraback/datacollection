#include<iostream>
using namespace std;
int main()
{
 int t;
 cin>>t;
 for(int j=1;j<=t;j++)
  {
    int n;
    cin>>n;
    int a[n+1];
    int diff=0;
    for(int i=0;i<n;i++)
     {
      cin>>a[i];
      if(i>0)
       {
        int d=a[i-1]-a[i];
        diff=max(diff,d);
       }
     }
     
     long long int rate=diff;
     //cout<<rate<<" ";
     long long int y=0,z=0;
     for(int i=1;i<n;i++)
      {
        if(a[i]<a[i-1])
         y+=a[i-1]-a[i];
      }
    for(int i=0;i<n-1;i++)
     {
       if(rate>a[i])
        z+=a[i];
       else z+=rate;
     }
    cout<<"Case #"<<j<<": "<<y<<" "<<z<<"\n";
  }
  
}

