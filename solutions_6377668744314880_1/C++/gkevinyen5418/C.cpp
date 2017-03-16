#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pr;
#define x first
#define y second

ll T;
ll X[5000];
ll Y[5000];

pr pt[5000];

ll sx, sy;

inline bool cmp(pr a, pr b){ return atan2(a.y-sy, a.x-sx) < atan2(b.y-sy, b.x-sx); }

ll cross(ll a, ll b)
{
    return (ll)(pt[a].x-sx)*(pt[b].y-sy)-(ll)(pt[a].y-sy)*(pt[b].x-sx);
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

    scanf("%lld", &T);

    for(ll Ti = 1; Ti <= T; Ti++)
    {
        ll N;
        scanf("%lld", &N);

        for(ll Ni = 0; Ni < N; Ni++)
            scanf("%lld %lld", &X[Ni], &Y[Ni]);

        printf("Case #%lld:\n", Ti);

        if( N == 1 || N == 2 )
        {
            for(ll Ni = 0; Ni < N; Ni++) printf("0\n");
            continue;
        }

        for(ll Ni = 0; Ni < N; Ni++)
        {
            for(ll Nj = 0; Nj < N-1; Nj++)
            {
                if( Nj < Ni ) pt[Nj].x = X[Nj], pt[Nj].y = Y[Nj];
                else pt[Nj].x = X[Nj+1], pt[Nj].y = Y[Nj+1];
            }

            sx = X[Ni]; sy = Y[Ni];
            sort(pt, pt+N-1, cmp);

            ll st = 0;
            ll cnt = 1;

            ll Ans = N;

            for(ll Nj = 0; Nj < N-1; Nj++)
            {
                while( cross(Nj, st) >= 0 )
                {
                    st = (st+1)%(N-1), cnt++;
                    if( st == Nj ) break;
                }
                Ans = min(Ans, N-cnt);
                cnt--;
            }

            printf("%lld\n", Ans);
        }
    }
}
