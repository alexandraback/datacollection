
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

ll x[4000][2];
struct Point{
	ll x,y;
	int id;
	Point(ll x=0, ll y=0, int id=0):x(x), y(y), id(id){}
};

bool operator<(const Point & a, const Point & b){
	double wa = atan2(a.y, a.x);
	double wb = atan2(b.y, b.x);
	if(abs(wa-wb) > 0.1){
		return wa < wb;
	}
	return a.y * b.x < a.x * b.y;
}

pair<Point, int> dirs[8000];
int N;
int main() {
	int TC;
	cin >> TC;
	FOR(tc,1,TC+1){
		cout << "Case #" << tc << ":\n";
		cin >> N;
		FOR(i,0,N)FOR(j,0,2)cin >> x[i][j];
		FOR(c,0,N){
			FOR(i,0,N)if(i!=c)dirs[i - (i > c)] = mp(Point(x[i][0] - x[c][0], x[i][1] - x[c][1], i), 1);
			int M = N-1;
			FOR(i,0,M){
				dirs[i+M].first = Point(-dirs[i].first.x, -dirs[i].first.y, dirs[i].first.id);
				dirs[i+M].second = -1;
			}
			M *= 2;
			sort(dirs, dirs + M);
			int n = 0;
			unordered_set<int> used;
			FOR(i,0,M){
				int id = dirs[i].first.id;
				if(dirs[i].second == -1){
					if(used.find(id) == used.end())++n;
				}
				used.insert(id);
			}
			int res = n;
			FOR(i,0,M){
				n += dirs[i].second;
				res = min(res, n);
			}
			cout << res << endl;
		}
	}
	return 0;
}
