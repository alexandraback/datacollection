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

void test()
{
    int n;
    cin>>n;
    char str[101][101];
    char New[101][101];
    rep(i,0,n)
        scanf("%s",str[i]);
    rep(i,0,n)
    {
        int was = strlen(str[i]);
        strcpy(New[i], str[i]);
        int len = unique(New[i], New[i] + was) - New[i];
        New[i][len] = 0;
        if (strcmp(New[i], New[0]) != 0)
        {
            puts("Fegla Won");
            return;
        }
    }
    int cnt = strlen(New[0]);
    int pos[101] = {0};
    int res = 0;
    rep(i, 0, cnt)
    {
        int Cnt[101] = {0};
        rep(j,0,n)
        {
            while (str[j][pos[j]] == New[0][i])
            {
                ++pos[j];
                ++Cnt[j];
            }
        }
        int add = 1e9;
        rep(j,0,n)
        {
            int here = 0;
            rep(k,0,n)
                here += abs(Cnt[j] - Cnt[k]);
            add = min(add, here);
        }
        res += add;
    }
    printf("%d\n",res);
}

void run()
{
    int t;
    cin>>t;
    rep(i,0,t)
    {
        printf("Case #%d: ",i+1);
        test();
    }
}


#define prob "A-small-attempt0(1)"


int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#else
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#endif
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
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
