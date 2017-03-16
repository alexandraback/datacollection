#include "std.h"
#define DBGLEVEL 1
#include "debug.h"

char buf[1024];
char ans[1024];
int N;

#define NP 64
#define MAXP 40
int primes[NP];

int fmodprime[12][NP];

typedef pair<int, char > P;

bool cmp(const P& p0, const P& p1) { return p0.first > p1.first; }

int main() {
    int T;
    cin >> T;
    FOR(tt, T)
    {
        int N;
        vector<pair<int, char>> v;
        cin >> N;
        v.resize(N);
        int tot = 0;
        FOR(i, N) {
            v[i].second = 'A' + i;
            cin >> v[i].first;
            tot += v[i].first;
        }
        //PRINT(V(tt)<<V(N) << V(v));
        cout << "Case #" << (tt + 1) << ":";

        while (tot > 0)
        {
            sort(v.begin(), v.end(), cmp);
            assert(v[0].first * 2 <= tot);
            //PRINT(V(tt)<<V(tot)<<V(N) << V(v));
            string r = " ";
            r += v[0].second;
            v[0].first--;
            tot--;
            if (v[1].first * 2 > tot) {
                r += v[1].second;
                v[1].first--;
                tot--;
            }
            cout << r;
        }

        cout << endl;

        next:;
        


    }
    return 0;
}
