#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define X first
#define Y second
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define SP system("pause")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( decltype(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	vector<int> a(4), b(4);
	int t, r1, r2, k;
	cin >> t;
	F(z, t) {
		cin >> r1;
		F(i, 4) 
			F(j, 4) {
				if (i == r1 - 1) cin >> a[j];
				else cin >> k;
			}

		cin >> r2;
		F(i, 4) 
			F(j, 4) {
				if (i == r2 - 1) cin >> b[j];
				else cin >> k;
			}

		vi sol;
		F(i, 4)
			F(j, 4) if (a[i] == b[j]) sol.push_back(a[i]);


		printf("Case #%d: ", z + 1);
		if (sol.size() > 1) printf("Bad magician!\n");
		else if(sol.size() == 0) printf("Volunteer cheated!\n");
		else printf("%d\n", sol[0]);
	}
	return 0;
}