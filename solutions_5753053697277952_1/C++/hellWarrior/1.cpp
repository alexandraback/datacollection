#include <bits/stdc++.h>

#define set(p) memset(p,-1,sizeof(p))
#define clr(p) memset(p,0,sizeof(p))
#define ll long long int
#define llu unsigned long long int
#define si(a) scanf("%lld",&a)
#define rep(i,a,n) for(i=(a);i<(n);i++)
#define pii pair<int,int>
#define pb(x) push_back(x)
#define v(x) vector<x>

using namespace std;

int gcd(int a,int b)
{
 int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}


long long int power(long long int x,long long int y,ll mod)
{
    long long int vari,ty,my;

    if( y == 0)
        return 1;
    vari = power(x, y/2,mod);
    ty=(vari%mod)*(vari%mod);
    if (y%2 == 0)
        {

                return ty%mod;
        }
    else
        {
                my=(x%mod)*(ty%mod);
                return my%mod;
        }
}



long long int maxxi(long long int a,long long int b)
{
        return a>b?a:b;
}

long long int mini(long long int a,long long int b)
{
        return a<b?a:b;
}




struct abhi
{
       ll val;
       ll arr1;
};

struct abhi brr[100010];

bool cmp(struct abhi x,struct abhi y)
{
        return x.arr1<y.arr1;
}


ll arr[1000];

int main()
{
    freopen("C:\\Users\\abhishek.gu\\Desktop\\b.in","r",stdin);
    freopen("C:\\Users\\abhishek.gu\\Desktop\\b1.out","w",stdout);

    ll t,n,k,vari,check1,i,tot,soln,j;
    si(t);

    ll tt=t;
    while(t--)
    {
        si(n);
        ll cnt = 0;
        rep(j,0,n)
            {
                si(arr[j]);
                cnt =cnt + arr[j];
            }

            cout<<"Case #"<<tt-t<<": ";
        while(cnt>0)
        {
            ll diff=0;
            rep(i,0,n)
            {
                if(arr[i]>0)
                    diff++;
            }
            if(cnt==3 && diff==3)
            {
                rep(j,0,n)
                {
                    if(arr[j]>0)
                    {
                        char a1 = 'A' +  j;
                        cout<<a1<<" ";
                        arr[j]--;
                        break;
                    }
                }
                rep(j,0,n)
                {
                    if(arr[j]>0)
                    {
                        char a1 = 'A' +  j;
                        cout<<a1;
                        arr[j]--;
                    }
                }

                cnt=cnt-3;
            }
            else
            {
                ll maxin = 0;
                ll maxx=0;
                rep(j,0,n)
                {
                    if(arr[j]>maxx)
                    {
                        maxx=arr[j];
                        maxin = j;
                    }
                }

                ll maxin2=0;
                ll maxx2=0;

                rep(j,0,n)
                {
                    if(j!=maxin && arr[j]>maxx2)
                    {
                        maxx2=arr[j];
                        maxin2 = j;
                    }
                }

                char a1='A' + maxin;
                char a2 = 'A' + maxin2;
                cout<<a1<<a2<<" ";
                arr[maxin]--;
                arr[maxin2]--;
                cnt=cnt-2;

            }

        }

        cout<<"\n";


		//if(check1==1)
			//cout<<"Case #"<<tt-t<<": "<<n*(k+1)<<"\n";
		//else
			//cout<<"Case #"<<tt-t<<": INSOMNIA\n";
    }

    return 0;
}
