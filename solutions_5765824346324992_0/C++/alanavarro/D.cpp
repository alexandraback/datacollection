#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define se second
#define fi first

using namespace std;
typedef long long ll;
typedef pair < ll, int > pii;
const int MAX = 5000;

int h[MAX];

int main(){
	
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	int t;
	cin >> t;
	int ntc = 1;
	
	int n , m;
	int A, B;
	while( t-- ){
		
		cin >> n >> m;
		
		priority_queue < pii > q; 
		cin >> h[0];
		
		A = h[0];
		B = h[0];
		q.push( mp(0,0) );
		for( int i = 1 ; i < n ;i++){
			cin >> h[i];
			q.push( mp(0,-1*i) );
			A = __gcd( A, h[i] );
			B *= h[i];
			B /= A;
		}
		//B /= A;
		
		pii cur;
		vector < int > all;
		int cant = 0;
		
		for( int i = 0 ; i < n ;i++ )
			cant += B/h[i];
		
		//cout << cant << endl;
		
		while( all.size() !=  cant ){
			cur = q.top();
			q.pop();
			all.pb( -1 * cur.se );
		//	cout << -1*cur.se << endl;
			q.push( mp( -1 * (-1*cur.fi + h[-1*cur.se]) , cur.se ) );
		}
		m--;
		printf("Case #%d: %d\n", ntc, all[m%cant]+1 );
		ntc ++;
	}

	return 0;
}
