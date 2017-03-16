#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <functional>
#include <iostream>

using namespace std;

//const int INF = 5003;
const long long INF = 1000000007;
const int MAXN = 100005;
typedef pair <int, int> ii;
//typedef pair <long long, long long> ii;
long long gcd( long long b, long long s ){
    return (s!=0) ? gcd( s, b%s ) : b;
}

char s[105][105];
char p[105][105];
int l[105];
int d[105][105];

int main(){// freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int R=1; R<=T; R++){

		memset( s, 0, sizeof( s ) );
		memset( p, 0, sizeof( p ) );
		memset( d, 0, sizeof( d ) );
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%s", s[i]);
			l[i] = strlen( s[i] );
		}
		
		for(int i=0; i<n; i++){
			char cc = '-';
			int id = -1;
			for(int j=0; j<l[i]; j++){
				if( cc != s[i][j] ){
					cc = s[i][j];
					++id;
					p[i][id] = s[i][j];
					d[i][id] = 1;
				}
				else{
					++d[i][id];
				}
			}
		}

		bool can = 1;
		for(int i=0; i<n; i++){
			for(int  j=0; j<n; j++){
				if( strcmp( p[i], p[j] ) != 0 ){
					can = 0;
					break;
				}
			}
			if( !can ) break;
		}
		
		printf("Case #%d: ", R);

		if( can ) {
			int sz = strlen( p[0] );
			long long res = 0;
			for(int i=0; i<sz; i++){
				int ans = INF;
				for(int j=1; j<=200; j++){
					int tot = 0;	
					for(int k=0; k<n; k++)
						tot += abs(j-d[k][i]);
					ans = min( ans, tot );
				}
				res += ans;
			}
			printf("%lld\n", res);
		}
		else
			puts("Fegla Won");
	}
	
}