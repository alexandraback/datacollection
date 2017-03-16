#include <bits/stdc++.h>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a,b) fr(a,0,b)
#define fre(a,b) for(int a = adj[b]; ~a; a = ant[a])
#define cl(a,b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define scs(s) scanf("%s", s)
#define pri(x) printf("%d\n", x)

#define iter(a) __typeof((a).begin())
#define fore(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)

#define st first
#define nd second
#define mp make_pair
#define pb push_back

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

const int oo = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< vi > vii;

#define N 10009

int n, a[N];

int main() {
	int cn = 1, t;
	sc(t); while (t--) {
		sc(n);
		rp(i, n) sc(a[i]);
		int dif = 0;
		int a1 = 0, a2 = 0;
		fr(i, 1, n) {
			if (a[i-1] > a[i]) 
			{
				a1 += a[i-1] - a[i];
				dif = max(dif, a[i-1] - a[i]);
			}
		}
		rp(i, n-1) {
			a2 += min(a[i], dif);
		}
		printf("Case #%d: %d %d\n", cn++, a1, a2);
	}
	return 0;
}

