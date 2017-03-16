#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(n);i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define SIZE(x) (int)(x).size()

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int MAXN = 1e5;

int a[MAXN];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int Calc(int R, int C, int N, int flag) {
    CLEAR(a);
    REP(i, R) REP(j, C) {
        if ((i + j) % 2 == flag) {
            a[i * C + j] = 1;
            --N;
        }
    }
    if (N <= 0) return 0;
    int cnt[5], ret = 0;
    CLEAR(cnt);
    REP(i, R) REP(j, C) {
        if (a[i * C + j] == 0) {
            int tot = 0;
            REP(k, 4) {
                int ii = i + dx[k], jj = j + dy[k];
                if (ii >= 0 && ii < R && jj >= 0 && jj < C) {
                    ++tot;
                }
            }
            ++cnt[tot];
        }
    }
    REP(i, 5) {
        if (N > cnt[i]) {
            ret += i * cnt[i];
            N -= cnt[i];
        } else {
            ret += i * N;
            break;
        }
    }
    return ret;
}

void Solve() {
    int R, C, N;
    cin >> R >> C >> N;
    int ans = R * C * 4;
    REP(i, 2) ans = min(ans, Calc(R, C, N, i));
    cout << ans << endl;
}

int main() {
//	freopen("B.in","r",stdin);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d: ", T);
        Solve();
        cerr << "Case #" << T << ": done!" << endl;
    }
    return 0;
}

