#include <algorithm>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end() 
#define MAXN 50
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int A[MAXN];
void solve() {

	int N,i,s(0);
	N = read();
	FOR(i,1,N)
		s += A[i] = read();

	while(s) {

		int k = 1;
		FOR(i,2,N)
			if( A[i] > A[k] )
				k = i;

		A[k]--;
		s--;
		printf("%c" , k + 'A' - 1 );

		k = 1;
		FOR(i,2,N)
			if( A[i] > A[k] )
				k = i;

		if( A[k] > s / 2 ) {
			A[k]--;
			printf("%c" , k + 'A' - 1 );
			s--;
		}

		printf(" ");
	}

	printf("\n");


}
int main()
{
	freopen( "input.txt" , "r" , stdin );
	freopen( "output.txt" , "w" , stdout );
	int T = read(),i;
	FOR(i,1,T) {
		printf("Case #%d: " , i );
		solve();
	}
	return 0;
}
