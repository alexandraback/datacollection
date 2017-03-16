#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;


int main() {
    ll T;
    cin >> T;

    for (ll cs = 1; cs <= T; ++cs) {
        ll N;
        cin >> N;

        vi M(N);
        for (ll i = 0; i < N; ++i) {
            cin >> M[i];
        }

        ll aMin = 0;
        ll maxDiff = 0;
        for (ll i = 1; i < N; ++i) {
            if (M[i] < M[i-1]) {
                aMin += M[i-1]-M[i];

                maxDiff = max(maxDiff, M[i-1]-M[i]);
            }
        }

        ll constantR = 0;
        for (ll i = 0; i < N-1; ++i) {
            constantR += min(M[i], maxDiff);
        }
        
        printf("Case #%lld: %lld %lld\n", cs, aMin, constantR);
    }

    return 0;
}
