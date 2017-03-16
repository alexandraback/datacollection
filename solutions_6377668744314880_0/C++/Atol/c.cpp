#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <sstream>
using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
#define sz(A) (int)(A).size()
#define FOR(A,B) for(int A=0; A < (int) (B);A++)
#define FOREACH(I,C) for(__typeof(C.begin()) I = (C).begin(); I != (C).end(); I++)
#define pb push_back
#define all(x) x.begin() , x.end()
#define mp make_pair

// some geometry code taken from my old icpc reference found on
// https://github.com/tmadeira/icpc-reference/blob/master/src/graham.cpp

#define MAX  3005

struct point{
    int x, y, id;
    int dist(const point& p) { return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y); }
    int left(const point& p, const point& q) {
        int l = (p.x - x)*(q.y - y) - (q.x - x)*(p.y - y);
        return l < 0 ? -1 : l > 0 ? 1 : 0;
    }
} PIVO;

bool cmp(const point& i, const point& j){
    int l = PIVO.left(i, j);
    if (l > 0 || (l == 0 && PIVO.dist(i) < PIVO.dist(j))) return true;
    return false;
}

void graham(struct point* P, int N, struct point* CH, int* CH_N) {
    int pivo = 0;
    for (int i = 1; i < N; i++)
        if (P[i].y < P[pivo].y || (P[i].y == P[pivo].y && P[i].x < P[pivo].x)) pivo = i;
    swap(P[pivo], P[0]);
    PIVO = P[0];
    sort(P + 1, P + N, cmp);
    int rev = N-1;
    for (int r = N-2; r >= 1; r--)
        if (PIVO.left(P[r], P[rev]) == 0) rev = r;
        else break;
    if (rev != 1) reverse(P + rev, P + N);
    *CH_N = 0;
    for (int i = 0; i < N; i++) {
        if (i > 1) {
            /* Se mudar a comparacao para '<', incluira todos os 
               pontos colineares no convex-hull*/
            while (*CH_N >= 2 && CH[*CH_N-2].left(CH[*CH_N-1],P[i]) < 0) (*CH_N)--;
        }
        CH[(*CH_N)++] = P[i];
    }
}

point P[MAX], CH[MAX];
int CH_N, lbl[MAX];

bool pointInLine(point a, point b, point c) {
    if(b.y != c.y) return (min(b.y,c.y) <= a.y && a.y <= max(b.y, c.y));
    if(b.x != c.x) return (min(b.x,c.x) <= a.x && a.x <= max(b.x, c.x));
    return false;
}
bool cruza(point a, point b, point c, point d) {
    if (a.left(c,d) == 0 && b.left(c,d) == 0) {
        if (pointInLine(a,c,d)) return true;
        if (pointInLine(b,c,d)) return true;
        if (pointInLine(c,a,b)) return true;
        if (pointInLine(d,a,b)) return true;
        return false;
    }
    return (a.left(c,d) != b.left(c,d)) && (c.left(a,b) != d.left(a,b));
}

// end of geometry library

int N;

bool faz_parte(int id) {
	FOR(i, CH_N) {
		if (CH[i].id == id) {
			return true;
		}
	}
	return false;
}

int DEBUG = 0;

void debug(point x) {
	if (!DEBUG) return;
	cout << "(" << x.id << ": " << x.x << ", " << x.y << ")" << endl;
}

int calc_here(point p, point a, point b) {
	int ans = 0;
	if(DEBUG) cout << "FOR POINTS " << endl;
	debug(p); debug(a), debug(b);

	if (DEBUG) {
		cout << "EITA" << endl;
		cout << a.left(b, p) << endl;
	}
	if (a.left(b, p) > 0) {
		return N;
	}

	FOR(i, N) {
		if (P[i].left( a, p ) >= 0) {
//			cout << "ENTROU PARA " << endl;
//			debug(P[i]);
			if (P[i].left( p, b ) >= 0) {
				if (P[i].left( a, p ) > 0 || P[i].left( p, b ) > 0) {
					if (P[i].id == a.id || P[i].id == b.id) return N;
					// need to remove i to make the angle a => id => b good
					if (DEBUG) cout << "Remove " << endl;
					debug(P[i]);
					ans++;
				}
			}
		}
	}
	if(DEBUG) cout << "DEU " << ans << endl;
	return ans;
}

int calc(int id) {
	int ans = N;
	point p;
	FOR(i, N) {
		if (P[i].id == id) p = P[i];
	}
	for(int i = 0; i < CH_N; i++) {
		for(int j = i+1; j < CH_N; j++)  {
			if (i == j) continue;
			if (P[i].id == id || P[j].id == id) continue;

			int tmp = calc_here(p, CH[i], CH[j]);
			ans = min(tmp, ans);

			/*
			if (tmp == 2) {
				DEBUG = 1;
				calc_here(p, CH[i], CH[j]);
				DEBUG = 0;
			}
			*/
		}
	}
	
	return ans;
}

void solve() {
	cin >> N;
	for(int i = 0; i < N; i++) {
		scanf("%d %d", &P[i].x, &P[i].y);
		P[i].id = i;
	}
	graham(P, N, CH, &CH_N);
	/*
	cout << "TENHO " << CH_N << endl;
	FOR(i, CH_N) {
		point p = CH[i];
		cout << "ESTA = " << p.x << "," << p.y << endl;
	}
	*/

	FOR(i, N) {
		if (faz_parte(i)) {
			cout << 0 << endl;
		} else {
			cout << calc(i) << endl;
		}
	}

}

int main() {
  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d:\n", t);
    solve();
  }
  return 0;
}
