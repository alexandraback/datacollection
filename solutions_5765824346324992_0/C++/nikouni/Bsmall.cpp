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

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef set<int> se;
typedef pair<int,int> pii;
typedef long long int tint;

#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define rall(c) (c).rbegin(), (c).rend()
#define all(c) (c).begin(), (c).end()
#define D(a) << #a << "=" << a << " "


#define si(a) int((a).size())
#define pb push_back
#define mp make_pair

int gcd(int a, int b) { return b != 0 ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a!=0 || b!=0 ? a / gcd(a,b) * b : 0; }


int main () {
	freopen("B-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
    
	ios_base::sync_with_stdio(false);
	
	int T; cin >> T;
	
	forsn(caso,1,T+1) {
		cerr << caso << endl;
		int n,b; cin >> b >> n;
		vi M(b); forn(i,b) cin >> M[i];	
		
		int mcm = M[0];
		forsn(i,1,b) mcm = lcm(mcm,M[i]);
		
		int done = 0;
		forn(i,b) done += mcm / M[i];
		
		n = done + n % done;
	
		priority_queue<pii,vector<pii>,greater<pii> > Q;
		forn(i,b) Q.push(pii(0,i));
		
		int res = 1;
		
		forn(i,n) {
			pii aux = Q.top(); Q.pop();
			aux.first += M[aux.second];
			Q.push(aux);
			res = aux.second +1;						
		}
		
		
		cout << "Case #" << caso << ": " << res << endl;	
		
	}

  return 0;

}


