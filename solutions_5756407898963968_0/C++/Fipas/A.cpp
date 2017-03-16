#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef long long               ll;
typedef long double             ld;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          pii;
typedef vector<pii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

#define VAR(a,b)        __typeof(b) a=(b)
#define REP(i,n)        for(int i=0;i<(n);++i)     // 0 to n
#define FOR(i,a,b)      for(VAR(i,a);i<=(b);++i)  // a to b, a < b
#define FORD(i,a,b)     for(VAR(i,a);i>=(b);--i)  // a to b, a > b
#define FORE(a,b)       for(VAR(a,(b).begin());a!=(b).end();++a) // for each, e.g. FORE(iter, vect) cout << *iter << endl;
#define SIZE(a)         ((int)((a).size())) // e.g. for (int i = 0; i < SIZE(vect); ++i)
#define ALL(x)          (x).begin(),(x).end() // e.g. sort(ALL(vect))
#define FILL(x,a)       memset(x,a,sizeof(x))
#define CLR(x)          memset(x,0,sizeof(x))
#define VE              vector<int>
#define SZ              size()
#define PB              push_back
#define MP              make_pair
#define FI              first
#define SE              second

// Numeric functions
bool isPowOf2(int i){return (i & i-1) == 0;} //NOTES: isPowOf2

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		int row;
		int mat[4][4];
		int occ[17];
		vector<int> v;

		CLR(occ);

		cin >> row;
		row--;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> mat[i][j];
			}
		}

		for (int j = 0; j < 4; j++)
			occ[mat[row][j]]++;

		cin >> row;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> mat[i][j];
			}
		}

		row--;

		for (int j = 0; j < 4; j++) {
			occ[mat[row][j]]++;
			if (occ[mat[row][j]] == 2)
				v.PB(mat[row][j]);

		}

		cout << "Case #" << i << ": ";
		if (v.size() > 1)
			cout << "Bad magician!\n";
		else if (v.size() == 1)
			cout << v[0] << "\n";
		else
			cout << "Volunteer cheated!\n";

	}

   	return 0;
}
