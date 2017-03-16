#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define INF (0x3f3f3f3f)

#define SZ(x) ((int)((x).size()))
#define PB(x) push_back(x)
#define MEMSET(x,v) memset(x,v,sizeof(x))
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))

typedef long long LL;
typedef pair<int, int> PII; typedef pair<PII, int> PII2;

#define MAXN (1005)

int in[MAXN];
int N;

int solve1() {
    int ret = 0;
    for (int i = 0; i < N - 1; i++) {
        if (in[i + 1] < in[i]) {
            ret += in[i] - in[i + 1];
        }
    }
    return ret;
}

int solve2() {
    int ret = 0;
    bool eat = false;
    for (int i = 0; i < N - 1; i++) {
        if (in[i + 1] < in[i]) {
            eat = true;
            break;
        }
    }

    if (eat) {
        int maxv = 0;
        for (int i = 0; i < N - 1; i++) {
            if (in[i + 1] < in[i]) {
                int diff = in[i] - in[i + 1];
                maxv = max(maxv, diff);
            }
        }
        for (int i = 0; i < N - 1; i++) {
            //            if (in[i + 1] < in[i]) {
            ret += min(in[i], maxv);
            //            }
        }
    }

    return ret;
}

void solve() {

    cin >> N;
    REP(i, N) cin >> in[i];
    int ans1 = solve1();
    int ans2 = solve2();
    cout << ans1 << " " << ans2 << endl;
}

int main() {
    int test;
    cin >> test;
    REP(t, test) {
        printf("Case #%d: ", t + 1);
        solve();

    }
    
    return 0;
}
