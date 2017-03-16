#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
#include <bitset>
#include <cstring>
using namespace std;


#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair


typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tint> vt;
typedef vector<vt> vvt;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;


int main() {
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);

        int ncas; cin >> ncas;
        forn(cas, ncas) {
        	cout << "Case #" << cas+1 << ": ";
        	int row[4];
        	int r1; cin >> r1; r1--;        	
        	forn(i,4) forn(j,4) {
        		int x; cin >> x;
        		if (i == r1) row[j] = x;
        	}

        	vi res;
        	int r2; cin >> r2; r2--;
        	forn(i,4) forn(j,4) {
        		int x; cin >> x;
        		if (i == r2) forn(k,4) if (x == row[k]) res.pb(x);
        	}

        	if (si(res) == 1) cout << res[0] << endl;
        	else if (si(res) == 0) cout << "Volunteer cheated!" << endl;
        	else cout << "Bad magician!" << endl;


        	
        }


        return 0;
}
