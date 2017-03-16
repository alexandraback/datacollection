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
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

const int INF = 1e8;
int N;
string A[100];
vector<int> B[100];

void solve() {
    cin >> N;
    REP (i, N) cin >> A[i];

    set<string> s;
    REP (i, N) {
        string tmp;
        REP (j, A[i].length()) {
            if (j == 0 || A[i][j] != A[i][j-1])
                tmp += A[i][j];
        }
        s.insert(tmp);
    }

    if (s.size() != 1) {
        cout << "Fegla Won" << endl;
        return;
    }

    REP (i, N) {
        B[i].clear();

        int cnt = 0;
        REP (j, A[i].length()) {
            if (j == 0 || A[i][j] == A[i][j-1])
                ++cnt;
            else {
                B[i].push_back(cnt);
                cnt = 1;
            }
        }
        B[i].push_back(cnt);
    }

    REP (i, N)
        assert(B[i].size() == B[0].size());
    
    vector<int> vs(N);
    int ret = 0;

    REP (k, B[0].size()) {
        REP (i, N)
            vs[i] = B[i][k];

        sort(vs.begin(), vs.end());
        int mid = vs[vs.size()/2];

        REP (i, N)
            ret += abs(vs[i] - mid);
    }

    cout << ret << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    REP (i, T) {
        cerr << "Case #" << i+1 << ": " << endl;
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
