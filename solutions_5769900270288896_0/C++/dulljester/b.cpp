/*
 */
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#define N 17
#define M 17
using namespace std;
#define oo 0xfffffffful

int m,n,K;
char bts[1<<16],t[1<<16];
unsigned int ***z,**w;

int main() {
	int i,j,k,ts,cs = 0;
	unsigned int u,v,ans;
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
	for ( u = 0; u < (1 << 16); ++u ) {
		bts[u] = bts[u>>1]+(u&1);
		for ( v = u, i = 0; i < 15; ++i )
			if ( ((v>>i)&1) && ((v>>(i+1))&1) )
				++t[u];
	}
	for ( scanf("%d",&ts); ts--; ) {
		scanf("%d %d %d",&m,&n,&K);
		if ( n > m ) swap(m,n);
		assert( m >= n );
		printf("Case #%d: ",++cs);
		z = (unsigned int ***)malloc((m+1)*sizeof *z);
		for ( i = 0; i <= m; ++i ) {
			z[i] = (unsigned int **)malloc((K+1)*sizeof *z[i]);
			for ( j = 0; j <= K; ++j ) {
				z[i][j] = (unsigned int *)malloc((1 << n)*sizeof *z[i][j]);
				for ( int l = 0; l < (1 << n); ++l )
					z[i][j][l] = +oo;
			}
		}
		w = (unsigned int **)malloc((1 << n)*sizeof *w);
		for ( u = 0; u < (1 << n); ++u )
			w[u] = (unsigned int *)calloc((1 << n),sizeof *w[u]);
		for ( u = 0; u < (1 << n); ++u )
			for ( v = 0; v < (1 << n); ++v )
				for ( i = 0; i < n; ++i )
					if ( ((u>>i)&1) & ((v>>i)&1) )
						++w[u][v];
		for ( u = 0; u < (1 << n); ++u )
			if ( bts[u] <= K )
				z[1][bts[u]][u] = t[u];
		for ( i = 2; i <= m; ++i ) 
			for ( u = 0; u < (1 << n); ++u )
				for ( k = 0; k <= K; ++k )
					if ( z[i-1][k][u] < +oo )
						for ( v = 0; v < (1 << n); ++v )
							if ( bts[v]+k <= K )
								if ( z[i-1][k][u]+t[v]+w[u][v] < z[i][k+bts[v]][v] )
									z[i][k+bts[v]][v] = z[i-1][k][u]+t[v]+w[u][v];
		for ( ans = +oo, u = 0; u < (1<<n); ++u )
			ans = min(ans,z[m][K][u]);
		printf("%u\n",ans);
	}
    return 0;
}

