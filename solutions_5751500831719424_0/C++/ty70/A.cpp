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
		if (word[0].size() != word[1].size() ) ok = false;
		int res = 0;
		
		rep (j, word[0].size() ){
			if (word[0][j].first == word[1][j].first ){
				res += abs (word[0][j].second - word[1][j].second );
			}else{
				ok = false;
			} // end if
		} // end rep
		output (t );
		if (ok ){
			cout << res << endl;
		}else{
			cout << "Fegla Won" << endl;
		} // end rep
	} // end for					
		
	return 0;
}
