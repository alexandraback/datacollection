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

#define N 3009
#define dbg 0
//(piv == 4)

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0): x(x), y(y) {}
    ll operator*(pt p2) { return x*p2.x + y*p2.y; }
    ll operator%(const pt &p2) const { return x*p2.y - y*p2.x; }
    pt operator+(pt p2) { return pt(x+p2.x, y+p2.y); }
    pt operator-(pt p2) { return pt(x-p2.x, y-p2.y); }
    ll norma() { return hypot(x, y); }
} p[N], p2[N], pivo;

struct event{
	pt p;
	int id;
	event() {}
	event(int i, pt _p) {
		id = i;
		p = _p;
		if (p.y < 0 ||
			(p.y == 0 && p.x < 0)) {
			p.x = -p.x;
			p.y = -p.y;
		}
	}
	bool operator<(const event &e2) const {
		return p%(e2.p) > 0ll;
	}
} ev[N];

int mark[N], cnt[5];
int n, ec;

void update(int i) {
	cnt[mark[i]]--;
	mark[i] = (mark[i]+3)%4;
	cnt[mark[i]]++;
}

int proc(int piv) {
	pivo = p[piv];
	int ans = n-1;
	cl(cnt, 0);
	ec = 0;
	rp(i, n) if (i != piv) {
		pt dif = p[i]-pivo;
		mark[i] = (dif.y < 0)? 2:
				(dif.y > 0)? 0:
				(dif.x < 0)? 1: 3;
		cnt[mark[i]]++;
		ev[ec++] = event(i, dif);
	}
	sort(ev, ev+n-1);
	
	if (dbg) dbs(cnt[0] _ cnt[1] _ cnt[2] _ cnt[3]);
	ans = min(ans, min(cnt[0], cnt[2]));
	
	int q = 0, r = 0;
		
	if (cnt[1]+cnt[3] > 0) {
		while (r < n-1 && ev[r].p%ev[q].p == 0ll) r++;
		q = r;
	}
	
	while (q < n-1) {
		rp(i, n) {
			if (i != piv && (mark[i]%2) == 1) {
				if (dbg) db("u" _ i);
				update(i);
			}
		}
		if (dbg) dbs(cnt[0] _ cnt[1] _ cnt[2] _ cnt[3]);
		ans = min(ans, min(cnt[0], cnt[2]));
	
		r = q;
		while (r < n-1 && ev[r].p%ev[q].p == 0ll) r++;
		for(; q < r; q++) {
			int id = ev[q].id;
			if (dbg) db("u2" _ id);
			update(id);
		}
		if (dbg) dbs(cnt[0] _ cnt[1] _ cnt[2] _ cnt[3]);
		ans = min(ans, min(cnt[0], cnt[2]));
	}
	
	rp(i, n) {
		if (i != piv && (mark[i]%2) == 1) {
			if (dbg) db("u" _ i);
			update(i);
		}
	}
	if (dbg) dbs(cnt[0] _ cnt[1] _ cnt[2] _ cnt[3]);
	ans = min(ans, min(cnt[0], cnt[2]));
	
	return ans;
}

int main() {
	int cn = 1, t;
	sc(t); while (t--) {
		sc(n);
		rp(i, n) {
			int a, b;
			sc2(a, b);
			p[i] = pt(a, b);
		}
		printf("Case #%d:\n", cn++);
		rp(i, n) pri(proc(i));
	}
	return 0;
}

