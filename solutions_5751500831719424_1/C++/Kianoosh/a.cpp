// In the Name Of God

#include <iostream>
#include <fstream>

#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <istream>
#include <queue>
#include <stack>

#define inf (int)(~0u/2)
#define ll_inf (long long)1ll << 62
#define int long long
#define float long double
#define eps (1e-8)
#define for2(i, a, b) for ( int (i) = (a); (i)<(b); (i)++ )
#define mp make_pair
#define f1 first
#define f2 second
#define pb push_back
#define pii pair<int,int>
#define vpii vector <pii>
#define vi vector<int>
#define sz(a) (int) a.size( )
#define fillArr(n, a) for2(i, 0, n) cin >> a[i];
#define print(a) cout << #a << endl;
#define umax(a,b) a = max ( a, b )
#define umin(a,b) a = min ( a, b )
#define all(k) k.begin ( ), k.end( )
#define rall(k) k.rbegin ( ), k.rend( )
#define clean(k) memset( k, 0, sizeof(k) )
using namespace std;

vector <int> num[200], v[200];


main ( ){
	int TT;
	cin >> TT;
	for2 ( LLL, 0, TT ){
		for2 ( i, 0, 200 ){
			num[i].clear ( );
			v[i].clear ( );
		}
		cout << "Case #" << LLL+1 <<": ";
		int n;
		cin >> n;
		for2 ( i, 0, n ){
			string s;
			cin >> s;
			int h = 0;
			for2 ( j, 0, sz(s) ){
				if ( j == sz(s) -1 || s[j] != s[j+1] ){
					v[i].push_back ( s[j] );
					num[i].push_back ( ++h );
					h = 0;
				}
				else
					++h;
			}
		}
		bool g = 0;
		for2 ( i, 0, n-1 ){
			if ( v[i] != v[i+1] ){
				cout << "Fegla Won" << endl;
				g = 1;
				break;
			}
		}
		if ( g ) continue;
		int num2 = 0;
		for2 ( i, 0, sz(v[0]) ){
			int minE = 1000000;
			for2 ( j, 0, n ){
				int sum = 0;
				for2 ( k, 0, n ){
					sum += abs ( num[k][i] - num[j][i] );
				}
				umin ( minE, sum );
			}
			num2 += minE;
		}	
		cout << num2 << endl;
	}


}
