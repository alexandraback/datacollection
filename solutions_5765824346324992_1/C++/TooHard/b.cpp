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
typedef pair<LL, int> PII; typedef pair<PII, int> PII2;

#define MAXN (1005)

LL M[MAXN];
int B;
LL N;

void solve() {
    cin >> B >> N;
    REP(i, B) cin >> M[i];
            
    LL left = 0, right = 100000000000000LL;
    while (left <= right) {
        LL num_finished = 0;
        LL mid = (left + right) / 2;
        LL start_time = mid;
        REP(i, B) {
            num_finished += (start_time - 1) / M[i] + 1;
        }
        REP(i, B) {
            if (start_time % M[i] == 0) {
                num_finished++;
            }
        }
        if (num_finished < N) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    //    cout << left << endl;
    LL start_time = left;
    LL cur = 0;
    REP(j, B) {
        cur += (start_time - 1) / M[j] + 1;
    }
    REP(j, B) {
        if (start_time % M[j] == 0) {
            cur++;
            if (cur == N) {
                cout << j + 1 << endl;
                return ;
            }
        }
    }
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
