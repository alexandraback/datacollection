#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

set<int> getRow(int r) {
    set<int> ret;

    REP (i, 4) REP (j, 4) {
        int x;
        cin >> x;
        if (i+1 == r)
            ret.insert(x);
    }

    return ret;
}

void solve() {
    int x, y;

    cin >> x;
    set<int> s = getRow(x);

    cin >> y;
    set<int> t = getRow(y);

    set<int> v;
    set_intersection(ALL(s), ALL(t), inserter(v, v.begin()));

    if (v.size() == 0)
        cout << "Volunteer cheated!" << endl;
    else if (v.size() == 1)
        cout << *v.begin() << endl;
    else
        cout << "Bad magician!" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    int T;
    cin >> T;

    REP (i, T) {
        cout << "Case #" << (i+1) << ": "; 
        cerr << "Case #" << (i+1) << ": "; 
        solve();
    }

    return 0;
}
