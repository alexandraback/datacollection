#include<cstdio>
#include<cassert>
#include<cstring>
#include<map>
#include<set>
#include<time.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include <limits>
   
using namespace std;
  
long long gcd( long long b, long long s ){
    return (s!=0) ? gcd( s, b%s ) : b;
}
  
long long Pow( long long a, long long b, long long c ){
    if( b == 0 ) return 1%c;
    else if( b == 1 ) return a%c;
    else{
        long long A = Pow( a, b/2, c );
        A = (A*A) % c;
        if( b & 1 ) A = (A*a) % c;
        return A;
    }
}

const long long INF = 1e9 + 7;
const long long INF9 = 1e9 + 9;
typedef pair <int, int> ii;

int a[20][20];
int dx[]= { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void solve(){
	int r, c, n;
	scanf("%d %d %d", &r, &c, &n);

	int rc = r*c;
	int re = 1e9 + 7;
	for(int i=0; i<(1<<(rc)); i++){
		
		int cc = 0;
		for(int j=0; j<rc; j++)
			if( i & (1<<j) ){
				++cc;
			}
		if( cc != n ) continue;
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				a[i][j] = 0;
		for(int j=0; j<rc; j++)
			if( i & (1<<j) )
				a[j/c][j%c] = 1;
		int no = 0;
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++) if( a[i][j] )
				for(int k=0; k<4; k++){
					int cx = i + dx[k];
					int cy = j + dy[k];
					if( 0 <= cx && cx < r && 0 <= cy && cy < c && a[cx][cy] ) {
						++no;
					}
				}
		re = min( re, no/2 );
	}
	printf("%d\n", re);
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++){
		printf("Case #%d: ", R);
		solve();
	}
}