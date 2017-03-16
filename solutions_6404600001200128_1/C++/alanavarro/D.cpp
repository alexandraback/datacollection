#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define se second
#define fi first

using namespace std;
typedef long long ll;
typedef pair < int, int > pii;
const int MAX = 5000;

int h[MAX];

int main(){
	
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	int t;
	cin >> t;
	int ntc = 1;
	int n, cur;
	while( t-- ){
		cin >> n;
		for( int i = 0 ; i < n ;i++ ){
			cin >> h[i];
		}
		int fi = 0;
		int se = 0;
		cur = 0;
		for( int i = 0 ;i < n-1; i++ ){
			if( h[i] > h[i+1] ){
				fi += h[i] - h[i+1];
				cur = max( cur, h[i] - h[i+1] );
			}
		}
		
		for( int i = 0 ; i < n-1; i++ ){
			se += min( max( h[i] , h[i] - h[i+1] ), cur );
		}
		
		//se -= h[n-1];
		printf("Case #%d: %d %d\n", ntc, fi, se );
		ntc ++;
	}

	return 0;
}
