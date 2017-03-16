#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

#define D(x...) fprintf(stderr,x)
#define D(x...)

typedef long long ll;

const ll INF = (1ll << 60ll);
const int MAX_N = 1005;

int N;
ll tim[MAX_N];

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        ll me;
        scanf("%d %lld",&N,&me);

        for(int i=0;i<N;i++) {
            scanf("%lld",&tim[i]);
        }

        ll lo = 0ll;
        ll hi = INF;
        ll best = INF;

        while(lo <= hi) {
            ll mid = (lo + hi)/2ll;
            ll tot = 0ll;
            for(int i=0;i<N;i++) {
                tot += (mid/tim[i])+1ll;
            }

            D("mid = %lld, tot = %lld\n",mid,tot);

            if(tot >= me) {
                best = mid;
                hi = mid-1ll;
            } else {
                lo = mid+1ll;
            }
        }

        D("best = %lld\n",best);

        ll cover = 0ll;
        for(int i=0;i<N;i++) {
            cover += (best/tim[i])+1ll;
            if(best % tim[i] == 0ll) {
                cover--;
            }
        }
        D("cover = %lld\n",cover);

        int ans = -MAX_N;
        for(int i=0;i<N;i++) {
            if(best % tim[i] == 0ll) {
                cover++;
                if(cover >= me) {
                    ans = i;
                    break;
                }
            }
        }
        D("cover = %lld, me = %lld\n",cover,me);
//        assert(ans >= 0);

        printf("Case #%d: %d\n",z,ans+1);
    }

    return 0;
}
