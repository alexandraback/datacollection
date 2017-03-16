#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()
#define INF 10000

using namespace std;

typedef long long ll;

typedef pair<char,int> CI;

void output (int t ){
	printf ("Case #%d: ", t );
}


int main()
{
	int T;
	scanf ("%d", &T );
	for (int t = 1; t <= T; t++ ){
		int n; scanf ("%d", &n );
		vector<string> w(n );
		rep (i, n ){
			cin >> w[i];
		} // end rep
		vector<CI> word[n]; rep (i, n ) word[i].clear();
		rep (i, n ){
			int len = w[i].length();
			word[i].push_back (CI (w[i][0], 1 ) );
			for (int j = 1; j < len; j++ ){
				if (w[i][j-1] == w[i][j] ){
					word[i][word[i].size() - 1].second++;
				}else{
					word[i].push_back (CI (w[i][j], 1 ) );
				} // end if
			} // end for
		} // end rep
		bool ok = true;
		set<int> num; num.clear();
		rep (i, n ) num.insert (word[i].size() );
		if (num.size() != 1 ) ok = false;
		int res = 0;
		if (ok ){
			rep (j, word[0].size() ){
				set<int> same; same.clear();
				rep (i, n ) same.insert (word[i][j].first );
				if (same.size() != 1 ){
					ok = false;
					break;
				} // end if
				if (!ok ) break;
				int ans = INF;
				rep (i, n ){
					int curr = 0;
					int base = word[i][j].second;
					rep (k, n ){
						if (i == k ) continue;
						curr += abs (word[k][j].second - base );
					} // end rep
					ans = min (ans, curr );
				} // end rep
				res += ans;
			} // end rep
		} // end if

		output (t );
		if (ok ){
			cout << res << endl;
		}else{
			cout << "Fegla Won" << endl;
		} // end rep
	} // end for					
		
	return 0;
}
