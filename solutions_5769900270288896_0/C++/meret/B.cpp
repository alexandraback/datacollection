
#include <bits/stdc++.h>
#include <sys/time.h>

using namespace std;

#define FI first
#define SE second
#define X first
#define Y second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))

double getTime() {
	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec * 1e-6;
}

bool t[10][10];

int r, c, n;

int score() {
    int result = 0;
    REP (i, r) {
        REP (j, c) {
            if (!t[i][j]) {
                continue;
            }
            if (i > 0 && t[i - 1][j]) {
                ++result;
            }
            if (j > 0 && t[i][j - 1]) {
                ++result;
            }
        }
    }
    return result;
}

int alg() {
    cin >> r >> c >> n;
    int result = (int) 1e9;
    REP (mask, 1 << (r * c)) {
        if (__builtin_popcount(mask) != n) {
            continue;
        }
        REP (i, r) {
            REP (j, c) {
                t[i][j] = (mask >> (i * c + j)) & 1;
            }
        }
        result = min(result, score());
    }
    return result;
}

int main() {
    int d;
    cin >> d;
    FOR (i, 1, d + 1) {
        cout << "Case #" << i << ": " << alg() << endl;
    }
}
