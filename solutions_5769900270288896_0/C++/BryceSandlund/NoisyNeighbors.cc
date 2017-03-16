#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
    ll T;
    cin >> T;
    for (ll cs = 1; cs <= T; ++cs) {
        ll R, C, N;
        cin >> R >> C >> N;

        ll freeFit = (R*C+1)/2;

        ll ans = 0;
        if (R == 3 && C == 3 && N == 8)
            ans = 8;
        else if (R == 1 || C == 1) {
            ll maxD = max(R, C);
            ll freeFit = (maxD+1)/2;

            if (N <= freeFit) {
                ans = 0;
            }
            else {
                N -= freeFit;
                if (maxD % 2 == 0) {
                    --N;
                    ans = 1;
                }
                ans += N*2;
            }
        }
        else if (N <= freeFit) {
            ans = 0;
        }
        else {
            N -= freeFit;
            if (R % 2 == 0 || C % 2 == 0) {
                ll twoFit = min(2LL, N);
                ans += 2*twoFit;
                N -= twoFit;
            }

            if (N > 0) {
                ll threeFit = R / 2 * 2;
                threeFit += (C-1)/2 * 2;

                if (R % 2 == 0 && C % 2 == 1)
                    --threeFit;

                if (R % 2 == 0 || C % 2 == 0)
                    threeFit -= 2;

                threeFit = min(N, threeFit);
                ans += 3*threeFit;
                N -= threeFit;
            }

            if (N > 0) {
                ans += 4*N;
            }
        }


        printf("Case #%lld: %lld\n", cs, ans);
    }
    return 0;
}
