#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) do { if(1) fprintf(stderr, __VA_ARGS__); } while(0)
#define DBGDO(X) do { if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; } while(0)

int TC;
const int maxN = 104;
int N;

string str[maxN], check[maxN];
int pos[maxN];
int val[maxN];

int main() {
	cin >> TC;
	FOR(tc,1,TC+1) {
		printf("Case #%d: ", tc);
		cin >> N;
		FOR(i,0,N) cin >> str[i];

		FOR(i,0,N) check[i] = "";
		FOR(i,0,N) {
			char prev = 0;
			for (char p : str[i]) {
				if (p != prev) check[i] += p;
				prev = p;
			}
		}
		bool ok = true;
		FOR(i,1,N) {
			if (check[i-1] != check[i]) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			printf("Fegla Won\n");
			continue;
		}

		int res = 0;
		char cur = 0;
		FOR(i,0,N) pos[i] = 0;
		while (pos[0] < sz(str[0])) {
			cur = str[0][pos[0]];
			FOR(i,0,N) {
				val[i] = 0;
				while (pos[i] < sz(str[i]) && str[i][pos[i]] == cur) {
					pos[i]++;
					val[i]++;
				}
			}
			sort(val, val + N);
			FOR(i,0,N) {
				res += abs(val[i] - val[N/2]);
			}
		}
		printf("%d\n", res);
	}
}
