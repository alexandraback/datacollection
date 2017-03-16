#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define REPP(i,s,e) for(int i=s; i<=e; i++)
#define PB(a) push_back(a)
#define MP(i,s) make_pair(i,s)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()
#define PRT(a) cerr << #a << " = " << (a) << endl
#define PRT2(a,b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << endl
#define PRT3(a,b,c) cerr << (a) << ", " << (b) << ", " << (c) << endl

typedef long long lint;
typedef pair<lint,lint> pll;

const string bad = "Bad magician!";
const string cheat = "Volunteer cheated!";

int r1, r2;
int d1[4][4];
int d2[4][4];

void solve() {
    set<int> s;
    REP(j,4) {
        s.insert(d1[r1][j]);
    }

    int ans = -1;
    int cnt = 0;
    REP(j,4) {
        if(s.find(d2[r2][j]) != s.end()) {
            ans = d2[r2][j];
            cnt++;
        }
    }

    if(cnt == 0) {
        cout << cheat << endl;
    }
    else if(cnt == 1) {
        cout << ans << endl;
    } else {
        cout << bad << endl;
    }
}

void coding() {
    int T;
    while(cin>>T) {
        REP(t,T) {
            printf("Case #%d: ", t+1);
            
            cin>>r1; r1--;
            REP(i,4) REP(j,4) cin>>d1[i][j];
            cin>>r2; r2--;
            REP(i,4) REP(j,4) cin>>d2[i][j];

            solve();
        }
    }
}

// #define _LOCAL_TEST

int main() {
#ifdef _LOCAL_TEST
	clock_t startTime = clock();
	freopen("a.in", "r", stdin);
#endif

	coding();

#ifdef _LOCAL_TEST
	clock_t elapsedTime = clock() - startTime;
	cout << endl;
	cout << (elapsedTime / 1000.0) << " sec elapsed." << endl;
	cout << "This is local test" << endl;
	cout << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif
}
