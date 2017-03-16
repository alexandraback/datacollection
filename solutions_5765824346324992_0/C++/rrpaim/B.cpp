#include <iostream>
#include <utility>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

const int MAXS = 2000;
const ll INF = 1LL<<50;

ll B, N;
ll speed[MAXS];

ll sum( ll t )
{
    ll ret = 0;
    ll curr;

    for ( int i = 0; i < B; i++ )
    {
        curr = (t-1)/speed[i];
        ret += curr;
    }
    return ret;
}

ll newAt( ll t )
{
    ll ret = 0;
    for ( int i = 0; i < B; i++ )
    {
        if ( t % speed[i] == 0 )
            ret++;
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    for ( int t = 1; t <= T; t++ )
    {
        ll curr = 0;
        cin >> B >> N;
        for ( int i = 0; i < B; i++ )
        {
            cin >> speed[i];
            curr += speed[i];
        }
        if ( N <= B ) cout << "Case #" << t << ": " << N << endl;
        else
        {
            N -= B;
            ll lo = 1, hi = INF, mid;
            while ( lo < hi )
            {
                mid = ( lo + hi )/2;
                ll S = sum(mid);
                ll na = newAt(mid);
                //cout << lo << " " << mid << " " << hi << " " << S << " " << na << endl;
                if ( S > N ) hi = mid;
                else
                    if ( S + na < N ) lo = mid+1;
                    else hi = mid;
            }
            if ( sum(mid) + newAt(mid) < N ) mid++;
            int ans = -1;
            N -= sum(mid);
            //cout << N << " " << mid << endl;
            for ( int i = 0; i < B; i++ )
                if ( mid % speed[i] == 0 )
                {
                    ans = i+1;
                    if ( --N == 0 )
                        break;
                }
            cout << "Case #" << t << ": " << ans << endl;
        }
    }
    return 0;
}
