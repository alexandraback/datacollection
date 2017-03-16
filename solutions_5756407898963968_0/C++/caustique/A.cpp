#pragma comment(linker,"/stack:256000000")

#include <cmath> 
#include <ctime> 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <set> 
#include <map> 
#include <cstring> 
#include <cstdlib> 
#include <queue> 
#include <cstdio> 
#include <cfloat>

using namespace std; 

#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++) 
#define sz(v) (int)(v).size() 
#define all(v) (v).begin(), (v).end()

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	REP(_, T) {
		cout << "Case #" << _ + 1 << ": ";
		int a[17] = {0};
		REP(i, 2) {
			int n;
			cin >> n;
			--n;
			int M[4][4];
			REP(j, 4) REP(k, 4) cin >> M[j][k];
			REP(j, 4) a[M[n][j]]++;
		}
		int cnt = 0;
		REP(i, 17) if (a[i] == 2) ++cnt;
		if (cnt == 0) {
			cout << "Volunteer cheated!" << endl;
		} else if (cnt > 1) {
			cout << "Bad magician!" << endl;
		} else {
			REP(i, 17) if (a[i] == 2) cout << i << endl;
		}
	}
	return 0;
}