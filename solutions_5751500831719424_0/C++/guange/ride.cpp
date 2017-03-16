#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <set>
#include <stack>

using namespace std;
#define ll long long 
#define eps 1e-8
#define inf 0x3f3f3f3f
#define N 105
#define M 2000
#define mod 1000000007
#define MP make_pair

char str[110][110];
char s[110][110];
int a[110][110];
int b[110];
void gao( char *s1, char *s2, int *a )
{
	int k = 0, i = 0, j = 0;
	int n = strlen( s1 );
	while( i < n ){
		j = i;
		while( j < n && s1[j] == s1[i] ) ++j;
		s2[k] = s1[i];
		a[k] = j - i;
		b[k] = max( b[k], a[k] );
		++k;
		i = j;
	}
	s2[k] = '\0';
}
int n;

int solve()
{
	for( int i = 0; i < n; ++i )
		for( int j = i + 1; j < n; ++j ) if( strcmp( s[i], s[j] ) ) return -1;
	int ans = 0, tmp;
	int m = strlen( s[0] );
	for( int i = 0; i < m; ++i ){
		for( int j = 0; j < n; ++j ) b[j] = a[j][i];
		sort( b, b + n );
		for( int j = 0; j < n; ++j )
			ans += abs( b[j] - b[n/2] );
	}
	return ans;
}
int main()
{
	freopen( "a.in", "r", stdin );
	freopen( "a.out", "w", stdout );
	int T, cas = 0;
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d", &n );
		memset( b, 0, sizeof(b) );
		for( int i = 0; i < n; ++i ){
			scanf( "%s", str[i] );
			gao( str[i], s[i], a[i] );
		}
		int ans = solve();
		printf( "Case #%d: ", ++cas );
		if( ans < 0 ) puts( "Fegla Won" );
		else printf( "%d\n", ans );
	}
}
/*
int vv[M], nxt[M], h[N], e;
int a[N], ans[N], tmp[N];
int n, vis[N];
int num;
void dfs( int u, int d )
{
	if( d >= n ){
		if( !num ) for( int i = 0; i < n; ++i ) ans[i] = tmp[i];
		else{
			int i = 0;
			while( i < n && a[tmp[i]] == a[ans[i]] ) ++i;
			if( i < n && a[ans[i]] > a[tmp[i]] )
				for( int j = 0; j < n; ++j ) ans[j] = tmp[j];
		}
		++num;
		return;
	}
	int v;
	if( d ){
		for( int i = h[u]; i+1; i = nxt[i] ){
			v = vv[i];
			if( !vis[v] ){
				vis[v] = 1;
				tmp[d] = v;
				dfs( v, d + 1 );
				vis[v] = 0;
			}
		}
	}
	else{
		for( int i = 1; i <= n; ++i ){
			vis[i] = 1;
			tmp[d] = i;
			dfs( i, d + 1 );
			vis[i] = 0;
		}
	}
}
int main()
{
	//freopen( "a.in", "r", stdin );
	//freopen( "a.out", "w", stdout );
	int T, cas = 0;
	int m, u, v;
	scanf( "%d", &T );
	while( T-- ){
		scanf( "%d%d", &n, &m );
		memset( h, -1, sizeof(h) ), e = 0;
		memset( vis, 0, sizeof(vis) );
		for( int i = 1; i <= n; ++i ) scanf( "%d", a+i );
		for( int i = 0; i < m; ++i ){
			scanf( "%d%d", &u, &v );
			vv[e] = v, nxt[e] = h[u], h[u] = e++;
			vv[e] = u, nxt[e] = h[v], h[v] = e++;
		}
		num = 0;
		dfs( 0, 0 );
		printf( "Case #%d: ", ++cas );
		for( int i = 0; i < n; ++i ){
			printf( "%05d", a[ans[i]] );
		}
		puts( "" );
	}
}
*/