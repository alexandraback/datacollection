// A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAXL 110
#define MAXN 100

int n, m;
int mid[ MAXN ], c[ MAXL ][ MAXN ];
char str[ MAXL ], b[ MAXN ][ MAXL ];

void init(){
	int i, j, l, k;
	cin >> n;
	m = 0;
	memset( c, 0, sizeof(c)) ;
	for ( i = 1; i <= n; i ++ ){
		scanf( "%s", str );
		l = strlen( str );
		k = 1;
		b[i][k] = str[0];
		for ( j = 1; j < l; j ++ )
			if ( str[j] == str[j-1] )
				c[k][i] ++;
			else{
				k++;
				b[i][k] = str[j];
				if ( i > 1 && b[i][k] != b[i-1][k] ){
					cout << "Fegla Won" << endl;
					return;
				}
			}
		if ( m == 0 )
			m = k;
		else
			if ( m != k ){
					cout << "Fegla Won" << endl;
					return;
				}
	}

	int ans = 0;
	for ( i = 1; i <= m; i ++ ){
		for ( j = 1; j <= n; j ++ )
			mid[j] = c[i][j];
		sort( mid+1, mid+n+1 );
		for ( j = 1; j <= n; j ++ )
			ans += abs( mid[(n+1)/2] - mid[j] );
	}
	cout << ans << endl;


}

void cal(){

}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen( "A-small-attempt0.in", "r", stdin );
	freopen( "out.txt", "w", stdout );
	int t, i;
	scanf( "%d\n", &t );
	for ( i = 1; i <= t; i ++ ){
		cout << "Case #" << i << ": ";
		init();
		cal();
	}
	return 0;
}

