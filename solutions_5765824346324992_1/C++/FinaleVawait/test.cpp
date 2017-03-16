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
int n , m , a[1100];
pair < lint , int > b[1100];

void init()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
}

void work()
{
    lint l = 0 , r = 1e16 , k;
    while ( l < r ) {
        k = ( l + r ) >> 1;
        lint sum = n;
        rep(i,1,n) if ( sum <= m ) sum += k / a[i];
        if ( sum >= m ) r = k; else l = k + 1;
    }
    rep(i,1,n) m -= r / a[i] , b[i] = mp( r / a[i] * a[i] , i );
    sort( b + 1 , b + n + 1 );
    printf("%d\n",b[m].y);
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
