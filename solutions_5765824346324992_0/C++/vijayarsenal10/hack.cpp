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
typedef long long int LL;

#ifdef _WIN32
#define gx getchar
#define px putchar
#define ps putchar(' ')
#define pn putchar('\n')
#else
#define gx getchar_unlocked
#define px putchar_unlocked
#define ps putchar_unlocked(' ')
#define pn putchar_unlocked('\n')
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
void lscan(LL &n)
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
    while( c >= '0' && c <= '9' ) n = (n<<3) + (n<<1) + c - '0', c = gx();  n = n * (LL)(sign);
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
void lprint(LL n)
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


typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

const LL MOD = 1000000007LL;
const int SIZ = 1000001;

LL po(LL a, LL b)
{
	LL x=1,y=a;
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y);
		}
		y = (y*y);
		b /= 2;
	}
	return x;
}

int primes[10] = {2,3,5,7,11,13,17,19,23};
vector<int> v;

void fact(int n)
{
    int i,ct,j;
    for(int i=0;i<9;i++)
    {
        ct = 0;
        if( (n%primes[i]) == 0 )
        {
            while((n%primes[i]) == 0 )
            {
                ct++;
                n /= primes[i];
            }
        }
        v[i] = max(v[i],ct);
    }
}

int lcm()
{
    int ans = 1;
    for(int i=0;i<9;i++)
    {
        //cout << primes[i] << " " << v[i] << endl;
        ans *= po(primes[i],v[i]);
    }
    return ans;
}

int main()
{
    LL t,n,b,a[100],i,j,cur,next,cut,left[100],ans,l,tot;
    lscan(t);
    for(i=0;i<200;i++) v.push_back(0);
    for(LL xx=1;xx<=t;xx++)
    {
        for(i=0;i<200;i++) v[i] = 0;
        lscan(b);
        lscan(n);
        for(i=0;i<b;i++)
        {
            lscan(a[i]);
            fact(a[i]);
            left[i] = 0;
        }
        l = lcm();
        tot = 0;
        for(i=0;i<b;i++) tot += l/a[i];
        n %= tot;
        if(n==0) n = tot;
        cut = 1;
        cur = 0;
        while(cut <= n)
        {
            next = INT_MAX;
            for(i=0;i<b;i++)
            {
                left[i] -= cur;
                if(left[i]==0)
                {
                    left[i] = a[i];
                    if(cut==n) ans = i+1;
                    cut++;
                }
                next = min(next,left[i]);
            }
            cur = next;
        }
        printf("Case #%d: ",xx);
        cout << ans << endl;
    }
    return 0;
}
