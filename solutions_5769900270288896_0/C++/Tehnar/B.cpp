#define FNAME ""

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define fornr(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = a; i < (int) b; i++)
#define gcd __gcd
 
#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;
typedef vector <int> vi;

template <class T> T sqr(const T &a) {return a * a;}

const int turn[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n, m, k, T;

int main()
{
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME"1.out", "w", stdout);

    scanf("%d", &T);
    forn(q, T)
    {
        scanf("%d%d%d", &n, &m, &k);
        int ans = 1e9;
        forn(mask, 1<<(n*m))
        {
            int cnt = 0;
            forn(i, (n*m))
                if (mask & (1<<i))
                    cnt++;
            if (cnt != k)
                continue;
            cnt = 0;
            forn(x, n)
                forn(y, m)
                {
                    forn(dir, 4)
                    {
                        int dx = x + turn[dir][0], dy = y + turn[dir][1];
                        if (dx >=0  && dx < n && dy >= 0 && dy < m && mask & (1<<(m*x + y)) && mask & (1<<(m*dx + dy)))
                            cnt++; 
                    }
                }
            ans = min(ans, cnt);
        }
        printf("Case #%d: %d\n", q + 1, ans / 2);
    }
}


