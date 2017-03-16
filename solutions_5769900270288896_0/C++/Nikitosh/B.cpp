#include <bits/stdc++.h> 

using namespace std;
 
#define sz(c) (int)(c).size()
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;

#ifdef WIN32
#define I64 "%I64d"
#else
#define I64 "%lld"
#endif

#define FNAME "1"

const int turn[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() 
{
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout); 
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
        int R, C, N;
        scanf("%d%d%d", &R, &C, &N);
        int k = R * C;
        int Min = 1e9;
        for (int i = 0; i < (1 << k); i++)
        {
            int cnt = 0;
            for (int j = 0; j < k; j++)
                if (i & (1 << j))
                    cnt++;
            if (cnt == N)
            {
                int ans = 0;
                for (int j = 0; j < R; j++)
                    for (int g = 0; g < C; g++)
                    {
                        int num = j * C + g;
                        if ((i & (1 << num)) == 0)
                            continue;
                        for (int go = 0; go < 4; go++)
                        {
                            int dx = j + turn[go][0], dy = g + turn[go][1];
                            if (dx >= 0 && dx < R && dy >= 0 && dy < C && (i & (1 << (dx * C + dy))))
                                ans++;
                        }
                    }
                Min = min(Min, ans);
            }
        }
        printf("Case #%d: %d\n", t + 1, Min / 2);
    } 
    return 0;
}