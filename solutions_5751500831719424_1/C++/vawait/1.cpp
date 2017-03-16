/*
 * Author:  vawait
 * Created Time:  2014年05月03日 星期六 23时59分30秒
 * File Name: 1.cpp
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
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
typedef long long lint;
int n , len[110] , p[110] , s[110];
char a[110][110];

void init()
{
	scanf("%d",&n);
	rep(i,1,n) scanf("%s",a[i]+1) , len[i] = strlen( a[i] + 1 );
	rep(i,1,n) p[i] = 1;
}

void work()
{
	int ans = 0;
	while ( p[1] <= len[1] ) {
		clr( s , 0 );
		rep(i,1,n) if ( p[i] > len[i] ) {
			puts("Fegla Won");
			return;
		}
		rep(i,2,n) if ( a[i][p[i]] != a[i-1][p[i-1]] ) {
			puts("Fegla Won");
			return;
		}
		rep(i,1,n) {
			int x = 1;
			while ( p[i] < len[i] && a[i][p[i]] == a[i][p[i]+1] ) p[i] ++ , x ++;
			s[x] ++;
		}
		int y = 10000000;
		rep(i,1,100) {
			int x = 0;
			rep(j,1,100) x += abs( i - j ) * s[j];
			y = min( y , x );
		}
		ans += y;
		rep(i,1,n) p[i] ++;
	}
	rep(i,1,n) if ( p[i] <= len[i] ) {
		puts("Fegla Won");
		return;
	}
	printf("%d\n",ans);
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
