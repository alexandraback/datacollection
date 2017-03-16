#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <time.h>
#define maxn 10007
#define grantN 1000007
#define modp 1000000007
#define eps (5E-1)
#define minf2 (1E-10)
#define lim1 30
#define lim2 300

using namespace std;

typedef long long LL;
const double PI=4*atan(1);
const double PI2=PI*2;
int n,m,tot;
LL gg,jj;

typedef struct sege
{
    int b,e;
    //struct sege *nxt;
    friend int operator<(struct sege x, struct sege y)
    {
        return x.b<y.b;
    }
}E,*Ptr;

LL qpow(int x, LL y, int p)
{
    LL res=1,b=x;
    while (y)
    {
        if (y&1) res=res*b%p;
        b=b*b%p;
        y>>=1;
    }
    return res;
}

void extgcd(int a, int b, int &x, int &y)
{
    if (b != 0) {
        extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else {
        x = 1;
        y = 0;
    }
}

int mod_inv(int a, int p)
{
    int x, y;
    extgcd(a, p, x, y);
    return (p + x % p) % p;
}

int invm(int x, int p)
{
    x%=p;
    if (x==0) return 0;
    else return mod_inv(x,p);
}

int crt(int x, int m1, int y, int m2)
{
    if (y>x) return ((y-x)%m2*invm(m1,m2)%m2*m1%m2+x)%m2;
    else return ((x-y)%m1*invm(m2,m1)%m1*m2%m1+y)%m1;
}

int q[30];
priority_queue<E> h;

int main()
{
    int T;
    LL N;
    //freopen("in.txt","r",stdin);
    //freopen("out1.txt","w",stdout);
    scanf("%d",&T);
    //T=1;
    //while (scanf(" %s %s",s,t)!=EOF)
    srand(time(0));
    //printf("%d\n",strcmp("aaa","aaa"));
    //while (T--)
    for (int ci=1;ci<=T;++ci)
    {
        //scanf("%d",&n);
        scanf("%d",&n);
        printf("Case #%d:",ci);
        for (int i=0;i<n;++i)
        {
            scanf("%d",q+i);
            E tmp;
            tmp.b=q[i];
            tmp.e=i;
            h.push(tmp);
        }
        while (!h.empty())
        {
            int k;
            printf(" ");
            E tmp=h.top();
            h.pop();
            printf("%c",tmp.e+'A');
            k=tmp.b;
            --tmp.b;
            if (tmp.b>0)
            {
                h.push(tmp);
            }
            else {
                if (h.size()==2) continue;
            }
            if (!h.empty())
            {
                tmp=h.top();
                if (tmp.b==k)
                {
                    printf("%c",tmp.e+'A');
                    h.pop();
                    --tmp.b;
                    if (tmp.b>0) h.push(tmp);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
