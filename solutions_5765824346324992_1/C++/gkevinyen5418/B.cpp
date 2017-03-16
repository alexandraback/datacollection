#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll T;
ll B, N;
ll M[200000];

ll cal(ll p)
{
    if( p < 0 ) return 0;
    ll cnt = 0;

    for(ll Bi = 0; Bi < B; Bi++)
        cnt += p/M[Bi]+1;

    return cnt;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    scanf("%lld", &T);

    for(ll Ti = 1; Ti <= T; Ti++)
    {
        scanf("%lld %lld", &B, &N);

        for(ll Bi = 0; Bi < B; Bi++)
            scanf("%lld", &M[Bi]);

        ll l = -1, r = 1e15;

        while( l+1 != r )
        {
            ll mid = (l+r)/2;

            if( cal(mid) >= N ) r = mid;
            else l = mid;
        }

        ll d = N-cal(l);
        ll di = 0;

        printf("Case #%lld: ", Ti);

        for(ll Bi = 0; Bi < B; Bi++)
        {
            if( r%M[Bi] == 0 )
                if( ++di == d ) printf(" %lld\n", Bi+1);
        }
    }
}
