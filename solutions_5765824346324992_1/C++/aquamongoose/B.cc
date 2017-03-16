#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
#define A first
#define B second
#define MP make_pair
#define PB push_back
typedef long long ll;

const int MAXB = 1010;
int B;
ll M[MAXB];
const ll INF = 0x3f3f3f3f3f3fll;

ll customer(ll t) {
    ll ret = 0;
    for (int i=0; i<B; i++) {
        ret += t/M[i] + 1;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int kase=1; kase<=T; kase++) {
        cout << "Case #" << kase << ": ";
        int N;
        cin >> B >> N;
        for (int i=0; i<B; i++) {
            cin >> M[i];
        }
        ll lo = 0, hi = INF;
        while (lo+1 < hi) {
            ll mid = (lo+hi)/2;
            if (customer(mid) >= N) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        if (customer(lo) >= N) hi = lo;
        ll ans = 0, cu = customer(hi);
        for (int i=B-1; i>=0; i--) {
            if (hi%M[i] == 0) {
                if (cu == N) {
                    ans = i+1;
                    break;
                }
                cu--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
