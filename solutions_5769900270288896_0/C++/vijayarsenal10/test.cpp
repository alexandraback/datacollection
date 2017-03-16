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

LL po(LL a, LL b, LL m)
{
	LL x=1,y=a;
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

int reverse(int a)
{
    int b = 0;
    while(a != 0)
    {
        b *= 10;
        b += a%10;
        a /= 10;
    }
    return b;
}

int ans;
int r,c;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int a[20][20];

void solve(int p, int q, int left)
{
    if(left==0)
    {
        int i,j,k,temp=0,tx,ty;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(a[i][j]==0) continue;
                for(k=0;k<4;k++)
                {
                    tx = dx[k] + i;
                    ty = dy[k] + j;
                    if(tx<0 || ty<0 || tx>=r || ty>=c) continue;
                    if(a[tx][ty]) temp++;
                }
            }
        }
        temp /= 2;
        if(temp < ans)
        {
            /*for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    cout << a[i][j] << " ";
                }
                pn;
            }
            pn;*/
            ans = temp;
        }
        return;
    }
    if(p >= r || q>=c) return;
    int i,j;
    int tp = p, tq = q;
    a[p][q] = 1;
    /*for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cout << a[i][j] << " ";
        }
        pn;
    }
    pn;*/
    tq++;
    if(tq >=c )
    {
        tq = 0;
        tp++;
    }
    if(tp <= r)
    {
        solve(tp,tq,left-1);
    }
    a[p][q] = 0;
    tp = p;
    tq = q;
    tq++;
    if(tq >=c )
    {
        tq = 0;
        tp++;
    }
    if(tp <= r) solve(tp,tq,left);
}

int main()
{
    int t,n,i,j;
    scan(t);
    for(int xx=1;xx<=t;xx++)
    {
        scan(r);
        scan(c);
        scan(n);
        
        ans = INT_MAX;
        for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        a[i][j] = 0;
        
        solve(0,0,n);
        
        printf("Case #%d: ",xx);
        cout << ans << endl;
    }
    return 0;
}
