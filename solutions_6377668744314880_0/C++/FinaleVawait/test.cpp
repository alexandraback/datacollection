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
int n , x[31000] , y[31000];
pair < double , int > a[10100];

void init()
{
    scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&x[i],&y[i]);
}

lint c(int i,int j,int k)
{
    return lint( x[j] - x[i] ) * ( y[k] - y[i] ) - lint( x[k] - x[i] ) * ( y[j] - y[i] );
}

void deal(int k)
{
    int m = 0;
    rep(i,1,n) if ( i != k ) 
        a[++m] = mp( atan2( x[i] - x[k] , y[i] - y[k] ) , i );
    sort( a + 1 , a + n );
    rep(i,1,n-1) a[n+i-1] = a[i];
    int x = 1 , y , mx = n;
    rep(i,1,n-1) {
        while ( x - i < n - 1 && c( a[x].y , a[i].y , k ) >= 0 ) x ++;
        mx = min( mx , n - 1 - ( x - i ) );
    }
    printf("%d\n",mx);
}

void work()
{
    if ( n == 1 ) {
        puts("0");
        return ;
    }
    rep(i,1,n) deal( i );
}

int main()
{
    freopen("1.out","w",stdout);
    int t;
    cin >> t;
    rep(i,1,t) {
        printf("Case #%d:\n",i);
        init();
        work();
    }
    return 0;
}
