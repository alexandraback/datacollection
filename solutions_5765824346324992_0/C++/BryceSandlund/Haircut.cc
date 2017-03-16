#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

#define INF 10000000000000000LL

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

int main() {
    ll T;
    cin >> T;

    for (ll cs = 1; cs <= T; ++cs) {
        ll B, N;
        cin >> B >> N;

        vi M(B);
        for (ll i = 0; i < B; ++i) {
            cin >> M[i];
        }

        ll lo = 0, hi = INF;
        ll ans;
        while (true) {
            ll mid = (hi+lo)/2;

            ll count = 0;
            vi spot(B);
            for (ll i = 0; i < B; ++i) {
                ll times = mid / M[i];
                count += times;
                spot[i] = times*M[i];
            }

            if (count + B >= N && count < N) {
                //cerr << "Mid: " << mid << " Count: " << count << endl;
                while (true) {
                    vi::iterator it = min_element(spot.begin(), spot.end());
                    if (count+1 == N) {
                        ans = it-spot.begin();
                        break;
                    }
                    else {
                    //    cerr << "added: " << (it-spot.begin()) << endl;
                        *it += M[it-spot.begin()];
                        ++count;
                    }
                }
                
                break;
            }
            else if (count < N) lo = mid;
            else hi = mid;
        }
        
        printf("Case #%lld: %lld\n", cs, ans+1);
    }

    return 0;
}
