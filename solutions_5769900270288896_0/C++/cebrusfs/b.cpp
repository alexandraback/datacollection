// @author cebrusfs
// headers {{{
#include<bits/stdc++.h>
using namespace std;
// }}}
// macros {{{
#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(x) (sort(ALL(x)), ((x).erase(unique(ALL(x)), (x).end())))
#define MS(x, v) std::fill(ALL(x), (v));


#define IOS ios_base::sync_with_stdio(false)

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)

#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)

#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
#define MP make_pair
#define F first
#define S second

typedef vector<int> VI;
#define PB push_back
#define PF push_front

#define PPB pop_back
#define PPF pop_front


// C++11
#if __cplusplus >= 201103L
#define MT make_tuple
typedef tuple<int, int> TII;
#endif

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;
// }}}

#define MAX 17

bool ary[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve(int id)
{
    fprintf(stderr, "case %d\n", id);
    int n, r, c;
    scanf("%d %d %d", &r, &c, &n);

    int N = r * c;
    int SN = 1 << N;

    int ans = N * N;
    for (int i = 0; i < SN; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < N; ++j)
            if (i & (1 << j))
            {
                cnt++;
            }

        if (cnt != n) continue;
        //printf("mask %d\n", i);

        memset(ary, 0, sizeof(ary));
        for (int j = 0; j < N; ++j)
            if (i & (1 << j))
            {
                int x = j / c;
                int y = j % c;
                ary[x][y] = 1;
            }

        cnt = 0;
        for (int x = 0; x < r; ++x)
        {
            for (int y = 0; y < c; ++y)
            {
                if (ary[x][y])
                {
                    for (int d = 0; d < 4; ++d)
                    {
                        int tx = x + dx[d];
                        int ty = y + dy[d];
                        if (0 <= tx and tx < r and 0 <= ty and ty < c and ary[tx][ty])
                        {
                            cnt++;
                        }
                    }
                }
            }
        }
        ans = min(cnt / 2, ans);
    }
    printf("Case #%d: %d\n", id, ans);
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i)
        solve(i);
}

