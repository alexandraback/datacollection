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

void test()
{
    int b,n;
    cin>>b>>n;
    int A[1001];
    rep(i,0,b)
        scanf("%d",A+i);
    ll l = 0, r = 1e15;
    ll res = r;
    while (l<=r)
    {
        ll t = (l+r)/2;
        ll cnt = 0;
        rep(i,0,b)
            cnt += t / A[i] + 1;
        if (cnt >= n)
        {
            res = t;
            r = t - 1;
        }
        else
            l = t + 1;
    }
    ll before = 0;
    if (res > 0)
        rep(i,0,b)
            before += (res - 1)/A[i] + 1;
    rep(i,0,b)
    {
        before += res % A[i] == 0;
        if (before == n)
        {
            cout<<i+1<<endl;
             return;
        }
       
    }
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

#define prob "B-small-attempt0(4).in"



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