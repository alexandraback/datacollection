#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<math.h>
#include<map>
#include<algorithm>
#include<queue>
#include<string>
#include<climits>
#include<bitset>
#include<set>
#include<functional>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

#ifdef _WIN32
    #define gx getchar
    #define px putchar
    #define ps putchar(' ')
    #define pn putchar('\n')
    #define DEBUG 1
#else
    #define gx getchar_unlocked
    #define px putchar_unlocked
    #define ps putchar_unlocked(' ')
    #define pn putchar_unlocked('\n')
    #define DEBUG 0
#endif

//input
void scan(int &n)
{
    int sign = 1;
    n = 0;
    char c = gx();
    while( c < '0' || c > '9' )
    {
        if( c == '-' ) sign = -1;
        c = gx();
    }
    while( c >= '0' && c <= '9' ) n = (n<<3) + (n<<1) + c - '0', c = gx();  n = n * sign;
}
void lscan(ll &n)
{
    int sign = 1;
    n = 0;
    char c = gx();
    while( c < '0' || c > '9' )
    {
        if( c == '-' )
        sign = -1;
        c = gx();
    }
    while( c >= '0' && c <= '9' ) n = (n<<3) + (n<<1) + c - '0', c = gx();  n = n * (ll)(sign);
}
int sscan(char a[])
{
    char c = gx();
    while(c==' ' || c=='\n') c=gx();
    int i=0;
    while(c!='\n')a[i++] = c,c=gx();
    a[i]=0;
    return i;
}
int wscan(char a[])
{
    char c = gx();
    while(c==' ' || c=='\n') c=gx();
    int i=0;
    while(c!='\n' && c!=' ')a[i++] = c,c=gx();
    a[i]=0;
    return i;
}

//output
void print(int n)
{
    if(n<0)
    {
        n=-n;
        px('-');
    }
    int i=10;
    char o[10];
    do{o[--i] = (n%10) + '0'; n/=10;}while(n);
    do{px(o[i]);}while(++i<10);
}
void lprint(ll n)
{
    if(n<0LL)
    {
        n=-n;
        px('-');
    }
    int i=21;
    char o[21];
    do{o[--i] = (n%10LL) + '0'; n/=10LL;}while(n);
    do{px(o[i]);}while(++i<21);
}
void sprint(const char a[])
{
    const char *p=a;
    while(*p)px(*p++);
}


ll po(ll a, ll b, ll m)
{
	ll x=1,y=a;
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
			if(x>m) x%=m;
		}
		y = (y*y);
		if(y>m) y%=m;
		b /= 2;
	}
	return x;
}

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    int xx,t;
    int i,j,k,sum,p[50],n,m,x,y;
    cin >> t;
    for(xx=1;xx<=t;xx++)
    {
        printf("Case #%d: ",xx);
        cin >> n;
        sum = 0;
        for(i=0;i<n;i++)
        {
            cin >> p[i];
            sum += p[i];
        }
        while(1)
        {
            if(!sum) break;
            m = 0;
            for(i=0;i<n;i++) m = max(m,p[i]);
            x = 0;
            for(i=0;i<n;i++) if(m==p[i]) x++;
            if(x==1)
            {
                for(i=0;i<n;i++)
                {
                    if(m==p[i])
                    {
                        cout << char(i+'A') << " ";
                        p[i]--;
                        break;
                    }
                }
                sum--;
                continue;
            }
            if(x==2)
            {
                j = k = -1;
                for(i=0;i<n;i++)
                {
                    if(p[i]==m)
                    {
                        if(j!=-1) k = i;
                        else j = i;
                    }
                }
                cout << char(j+'A') << char(k+'A') << " ";
                p[j]--;
                p[k]--;
                sum-=2;
                continue;
            }
            for(i=0;i<n;i++)
            {
                if(p[i]==m) break;
            }
            cout << char(i+'A') << " ";
            p[i]--;
            sum--;
        }
        cout << endl;
    }
    return 0;
}
