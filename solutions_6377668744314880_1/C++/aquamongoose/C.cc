#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll, ll> pii;
typedef vector<ll> vi;
#define A first
#define B second
#define MP make_pair
#define PB push_back

const ll MAXN = 3333;
ll N;
pii P[MAXN], Q[MAXN];

bool mycmp(const pii &a, const pii &b) {
    return atan2(a.B-P[0].B, a.A-P[0].A) <
           atan2(b.B-P[0].B, b.A-P[0].A);
}

// computes (a-c) x (b-c)
ll cross(const pii &a, const pii &b, const pii &c) {
    return (a.A - c.A) * (b.B - c.B) - (b.A - c.A) * (a.B - c.B);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T; cin >> T;
    for (ll kase=1; kase<=T; kase++) {
        cout << "Case #" << kase << ":\n";
        cin >> N;
        for (ll i=0; i<N; i++) {
            cin >> Q[i].A >> Q[i].B;
        }
        for (ll i=0; i<N; i++) {
            ll ans = 0x3f3f3f3f;
            for (ll j=0; j<N; j++)
                P[j] = Q[j];
            swap(P[i], P[0]);
            sort(P+1, P+N, mycmp);
            ll k = 1;
            for (ll j=1; j<N; j++) {
                if (k == j) k++;
                while (k == N || cross(P[j], P[k%N], P[0]) > 0) k++;
                ans = min(ans, k-j-1 - (k >= N));
            }
            if (N <= 2) ans = 0;
            cout << ans << '\n';
        }
    }
    return 0;
}
