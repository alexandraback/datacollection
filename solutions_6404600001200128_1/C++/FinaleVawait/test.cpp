/*
 * Author:  vawait
 * Created Time:  2015/4/18 9:38:15
 * Problem: test.cpp
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x) * (x))
typedef long long lint;
int n , a[1100];

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
}

void work()
{
    int sum = 0 , mx = 0 , sum2 = 0;
    rep(i,2,n) if ( a[i] < a[i-1] ) {
        mx = max( a[i-1] - a[i] , mx );
        sum += a[i-1] - a[i];
    }
    rep(i,1,n-1) sum2 += min( mx  , a[i] );
    printf("%d %d\n",sum,sum2);
}

int main()
{
    freopen("1.out","w",stdout);
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case #%d: ",i);
        init();
        work();
    }
    return 0;
}
