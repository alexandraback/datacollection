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


main ( ){
	int TT;
	cin >> TT;
	for2 ( LLL, 0, TT ){
		cout << "Case #" << LLL+1 <<": ";
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		vector <int> num1, num2, v1, v2;
		int h = 0;
		for2 ( i, 0, sz(s) ){
			if ( i == sz(s) - 1 || s[i] != s[i+1] ){
				num1.pb ( ++h );
				v1.pb ( s[i] );
				h = 0;
			}
			else
				++h;
		}
		h = 0;
		for2 ( i, 0, sz(t) ){
			if ( i == sz(t) - 1 || t[i] != t[i+1] ){
				num2.pb ( ++h );
				h = 0;
				v2.pb ( t[i] );
			}
			else
				++h;
		}
		if ( v1 != v2 )
			cout << "Fegla Won" << endl;
		else{
			int num = 0;
			for2 ( i, 0, sz(v1) )
				num += abs ( num1[i] - num2[i] );
			cout << num << endl;
		}
	}


}
