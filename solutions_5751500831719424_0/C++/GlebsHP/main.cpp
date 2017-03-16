#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 1000;

string str[size];
int tc, n;
vector <pair <int, int> > types[size];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cin >> n;
    	for (int i = 0; i < n; i++) {
    		types[i].clear();
    		cin >> str[i];
	    	int m = str[i].size();
    		int p = 0, q = 0;
    		while (p < m) {
    			while (q < m && str[i][q] == str[i][p])
    				q++;
    	   	    types[i].pb(mp(str[i][p] - 'a', q - p));
    	   	    p = q;
    		}
   		}
 		bool flag = true;
   	 	for (int i = 1; i < n; i++) {
   	   		if (types[0].size() != types[i].size())
   	   			flag = false;
   	   		if (flag)
   	   			for (int j = 0; j < (int) types[0].size(); j++)
   	   				flag = flag && (types[0][j].fs == types[i][j].fs);
   	   	}
   	   	if (!flag)
   	   		cout << "Case #" << tnum + 1 << ": Fegla Won" << endl;
   	   	else {
   	   		int ans = 0;
   	   		for (int i = 0; i < (int) types[0].size(); i++) {
   	   			vector <int> h;
   	   			for (int j = 0; j < n; j++)
   	   				h.pb(types[j][i].sc);
   	   			sort(h.begin(), h.end());
   	   			for (int j = 0; j < n; j++)
   	   				ans += abs(h[j] - h[n / 2]);
   	   		}
   	   		cout << "Case #" << tnum + 1 << ": " << ans << endl;
   	   	}
    }

    return 0;
}