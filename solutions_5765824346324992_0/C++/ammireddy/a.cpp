#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b,n;
ll ar[1005][4];

int gcd(int a,int b)
{
    if(b>a)
    return gcd(b,a);
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    int k=gcd(a,b);
    a/=k;
    return a*b;
}



ll mini()
{
ll min=INT_MAX,ind=0;
  for(ll i=1;i<=b;i++)
  {
      if(ar[i][3]<min)
      {
          min=ar[i][3];
          ind=i;
      }
  }
  return ind;
}

void rev(ll m)
{
    for(ll i=1;i<=b;i++)
    {
        ar[i][3]-=m;
    }
}


int main()
{
/*	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);*/

    int t;
    cin >> t;
    for(int tt=0;tt<t;tt++)
    {
        cout << "Case #" << (tt+1) << ": ";
        cin>>b>>n;
        for(ll i=1;i<=b;i++)
        {
            for(ll j=1;j<=3;j++)
            {
                ar[i][j]=0;
            }
        }
        for(ll i=1;i<=b;i++)    cin>>ar[i][1];
        ll ind=0,max=INT_MIN;
        /*for(ll i=1;i<=b;i++)
        {
            if(a[i][1]>max)
                max=a[i][1];
        }*/
        ll k=ar[1][1];
        ll temp=b;
        while(temp>=1)
        {
            k=lcm(k,ar[temp--][1]);
        }
        max=k;
        ll aux=0;
        for(ll i=1;i<=b;i++)
        {
            aux+=(ceil((max/ar[i][1])));
        }
       // cout<<aux<<endl;
        if(n%aux==0)    n=aux;
        else    n=n%aux;
        for(ll i=1;i<=n;i++)
        {
            ind=mini();
            //cout<<ind<<endl;
            ar[ind][2]=i;
            rev(ar[ind][3]);
            ar[ind][3]=ar[ind][1];
        }
        cout<<ind<<endl;
    }
    return 0;
}
