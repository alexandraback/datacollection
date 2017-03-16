
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

void calc(){
	int R;
	cin >> R;
	set<int> s1, s2;
	FOR(i,1,5){
		FOR(j,0,4){
			int tmp;
			cin >> tmp;
			if(i == R)s1.insert(tmp);
		}
	}
	cin >> R;
	FOR(i,1,5){
		FOR(j,0,4){
			int tmp;
			cin >> tmp;
			if(i == R)s2.insert(tmp);
		}
	}
	set<int> s3;
	FORIT(it, s1){
		if(s2.find(*it) != s2.end())s3.insert(*it);
	}
	if(sz(s3) == 0) cout << "Volunteer cheated!\n";
	else if(sz(s3) == 1)cout << (*s3.begin()) << endl;
	else cout << "Bad magician!\n";
}

int main() {
	int TC;
	cin >> TC;
	FOR(T,1,TC+1){
		cout << "Case #" << T << ": ";
		calc();
	}
	return 0;
}
