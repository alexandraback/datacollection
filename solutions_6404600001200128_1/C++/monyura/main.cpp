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
    int n;
    cin>>n;
    int A[1001];
    rep(i,0,n)
        scanf("%d",A+i);
    int x = 0;
    int mx = 0;
    rep(i,1,n)
    if (A[i] < A[i-1])
    {
        int v = A[i-1] - A[i];
        x += v;
        mx = max(mx, v);
    }
    int z = 0;
    rep(i,0,n-1)
    {
        int a = A[i];
        z += min(a, mx);
    }
    cout<<x<<' '<<z<<endl;
    
    
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

#define prob "A-large(3).in"



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