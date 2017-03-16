#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
#define CL(a,x) memset(x, a, sizeof(x))
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans;
char ss[1000002];

set<int> get() {
    set<int> res;
    cin >> m;
    F0(i,4) {
        F0(j,4) {
            cin >> l;
            if (i+1 == m) res.insert(l);
        }
    }
    return res;
}

int main() {
    //freopen("a.in", "r", stdin);

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

//	freopen("A-large.in", "r", stdin);
//	freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        //cerr << tt << endl;
        set<int> s1 = get(), s2 = get();
        vector<int> v;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(v));

		printf("Case #%d: ", tt);
        if (SZ(v) == 1) cout << v[0] << endl;
        else if (SZ(v) > 0) cout << "Bad magician!" << endl;
        else cout << "Volunteer cheated!" << endl;
	}
    cerr << "Press any key to continue" << endl;
    while (1);
	
	return 0;
}
