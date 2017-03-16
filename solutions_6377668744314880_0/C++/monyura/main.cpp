#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>
#include <cassert>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;

struct point
{
    ll x, y;
    point()
    {
        x = y = 0;
    }
    point(ll a ,ll b)
    {
        x = a;
        y = b;
    }
    point operator+(const point &other) const
    {
        return point(x + other.x, y + other.y);
    }
    point operator-(const point &other) const
    {
        return point(x - other.x, y - other.y);
    }
    ll operator*(const point &other) const
    {
        return x * x + y * y;
    }
    ll operator^(const point &other) const
    {
        return x * other.y - y * other.x;
    }
    bool operator<(const point &other) const
    {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

bool cmp(const point &a, const point &b)
{
    ll pr = a ^ b;
    if (pr == 0)
        return a*a < b*b;
    return pr > 0;
}

map<point, int> mp;
int Ans[30];


vector<point> vec;
void build(point *P, int n, int val)
{
    sort(P, P+n);
    point st = P[0];
    for (int i = n-1;i>=0;i--)
        P[i] = P[i] - P[0];
    sort(P+1,P+n, cmp);
    P[n] = P[0];
    vec.clear();
    vec.push_back(P[0]);
    vec.push_back(P[1]);
    rep(i,2,n+1)
    {
        while (vec.size() > 2 && ((P[i] - vec.back()) ^ (vec.back() - vec[vec.size()-2])) > 0)
            vec.pop_back();
        vec.push_back(P[i]);
    }
    vec.pop_back();
    rep(i,1,n)
    {
        if (((P[i] - P[0]) ^ (vec.back() - P[0])) ==0)
        {
            int ind = mp[P[i] + st];
            Ans[ind] = min(Ans[ind], val);
        }
    }
    rep(i,0,vec.size())
    {
        int ind = mp[vec[i] + st];
        Ans[ind] = min(Ans[ind], val);
    }
    
//    puts("======");
//    rep(i,0,vec.size())
//        cout<<vec[i].x<<' '<<vec[i].y<<endl;
}

void test()
{
    int n;
    cin>>n;
    point P[30];
    mp.clear();
    rep(i,0,n)
    {
        scanf("%lld%lld",&P[i].x, &P[i].y);
        mp[P[i]] = i;
    }
//    build(P,n, 0);
//    return;
    rep(i,0,n)
        Ans[i] = n -1;
    point A[30];
    rep(i,1,1<<n)
    {
        int m = 0;
        rep(j,0,n)
            if ((i>>j)&1)
                A[m++] = P[j];
        build(A, m, n - m);
    }
    puts("");
    rep(i,0,n)
        cout<<Ans[i]<<endl;
}

void run()
{
    int t;
    cin>>t;
    rep(i,0,t)
    {
        printf("Case #%d: ", i+1);
        test();
    }
}

#define prob "C-small-attempt0(3).in"



int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen("../" prob,"r",stdin);
    freopen("../" prob ".out","w",stdout);
#else
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    time_t st=clock();
#endif
#else
#endif
    run();
#ifdef _MONYURA_
#ifndef prob
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
#endif
    
    return 0;
}