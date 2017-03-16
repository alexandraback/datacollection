
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
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <fstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
int v[100000];
int main() {
	int TC;
	cin >> TC;
	FOR(tc,1,TC+1){
		int N;
		cin >> N;
		FOR(i,0,N)cin >> v[i];
		int r1 = 0;
		FOR(i,1,N)r1 += max(v[i-1]-v[i], 0);
		int minRate = 0;
		FOR(i,1,N)minRate = max(minRate, v[i-1] - v[i]);
		int r2 = 0;
		FOR(i,1,N)r2 += min(minRate, v[i-1]);
		cout << "Case #" << tc << ": " << r1 << " " << r2 << endl;
	}
	return 0;
}
