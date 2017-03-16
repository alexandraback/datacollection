//Bismillahir Rahmanir Rahmeem

#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<string.h>
#include <stdlib.h>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<stdlib.h>
#include<string>
#include<set>
#include<iomanip>
#define INF 1e9
#define lld long long int
#define CLR(a) memset(a,0,sizeof(a))
#define RESET(a) memset(a,-1,sizeof(a))
#define act(a) memset(a,1,sizeof(a))
#define setinf(a) memset(a,0b01111111,sizeof(a));
#define FRO freopen("input.txt","r",stdin);
#define FROut freopen("output.txt","w",stdout);
#define ui unsigned int
#define came "came"
#define pii pair<int,int>
#define plii pair<long long int, int>
#define pll pair<long long,long long>
#define pic pair<int,char>
#define ninf (-1e9)-2
#define inf (1e9)+2
#include<fstream>
#include <assert.h>
#include <bitset>

#define foreach(x) for(__typeof(x.begin()) it=x.begin(); it!=x.end();it++)

using namespace std;
#define pid pair<int,double>
#define pdi pair<double,int>

#define PB push_back
#define MP make_pair
#define pri(x) printf("%d\n",x)
#define pi 3.14159265359
#define X first
#define Y second
#define vit vector<int>::iterator


struct mathv{
    int x,y;
    mathv()
    {
        x=y=0;
    }
    mathv(int a, int b)
    {
        x=a;
        y=b;
    }
    void eq(int a, int b)
    {
        x=a,y=b;
    }
    mathv operator +(mathv &p)
    {
        return mathv(x+p.x,y+p.y);
    }
    mathv operator -(mathv &p)
    {
        return mathv(x-p.x,y-p.y);
    }
};

bool cmp(const mathv & a, const mathv &b)
{
    if(a.y!=b.y)
    {
        return a.y<b.y;
    }
    else
    {
        return a.x<b.x;
    }
}

int cross2D(mathv v1, mathv v2)
{
    return v1.x*v2.y-v1.y*v2.x;
}

int convexHull(mathv points[],mathv convexPoints[], int n)
{
    int i,j,t;
    sort(points, points+n, cmp);
    int m=0;
    for(i=0;i<n;i++)
    {
        while(m>=2 && cross2D(convexPoints[m-2]-convexPoints[m-1],convexPoints[m-2]-points[i])<0)
        {
            m--;
        }
        convexPoints[m++]=points[i];
    }
    for(i=n-2,t=m+1;i>=0;i--)
    {
        while(m>=t && cross2D(convexPoints[m-2]-convexPoints[m-1],convexPoints[m-2]-points[i])<0)
        {
            m--;
        }
        convexPoints[m++]=points[i];
    }
    return m-1;
}

int n,m;

mathv vec[105];
mathv param[105];
mathv ret[105];

int tree[20];

int main()
{
    FRO
    FROut
    int t,ca;
    scanf("%d",&t);
    for(ca=1;ca<=t;ca++)
    {
        scanf("%d",&n);
        int i,j;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&vec[i].x,&vec[i].y);
        }
        for(i=0;i<n;i++)
        {
            tree[i]=n;
        }
        for(i=0;i<n;i++)
        {
            param[i]=vec[i];
        }
        int val=convexHull(param,ret,n);
        for(i=0;i<val;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ret[i].x==vec[j].x && ret[i].y==vec[j].y)
                {
                    tree[j]=0;
                }
            }
        }
        int mx=1<<n;
        for(i=1;i<mx;i++)
        {
            int x=__builtin_popcount(i);
            if(x>=3)
            {
                int sz=0;
                for(j=0;j<n;j++)
                {
                    if(i & 1<<j)
                    {
                        //true
                        param[sz].x=vec[j].x;
                        param[sz].y=vec[j].y;
                        sz++;
                    }
                }
                if(sz==convexHull(param,ret,sz))
                {
                    //comvesx hull
                    for(j=0;j<n;j++)
                    {
                        if(i & 1<<j)
                        {
                            tree[j]=min(tree[j],n-sz);
                        }
                    }
                }

            }
            else
            {
                for(j=0;j<n;j++)
                {
                    if(i & 1<<j)
                    {
                        tree[j]=min(tree[j],n-x);
                    }
                }
            }
        }
        printf("Case #%d:\n",ca);
        for(i=0;i<n;i++)
        {
            printf("%d\n",tree[i]);
        }

    }
}
