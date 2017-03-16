
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)
#define MIN(x,y) ( ((x) < (y))? (x) : (y) )
#define MAX(x,y) ( ((x) > (y))? (x) : (y) )
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define INF 1000000001

using namespace std;

typedef pair < int , int > PII;
typedef long long int LLI;

typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < PII > VP;
typedef vector < LLI > VL;

typedef vector < VI > VVI;
typedef vector < VL > VVL;
typedef vector < VB > VVB;

int Mx[] = {-1, 0, 1, 0},
    My[] = {0, 1, 0, -1};

int solve()
{
    int r, c, n;
    cin >> r >> c >> n;

    int N = (1 << (r * c));

    int ans = INF;

    FOR(mask,0,N-1)
        if (__builtin_popcount(mask) == n)
        {
            bool tab[r][c];

            FOR(i,0,r-1) FOR(j,0,c-1)
            {
                int bit = i * c + j;

                tab[i][j] = (mask & (1 << bit));
            }

            int cnt = 0;

            FOR(i,0,r-1) FOR(j,0,c-1)
                if (tab[i][j]) FOR(mv,0,3)
                {
                    int x = i + Mx[mv],
                        y = j + My[mv];

                    if (x >= 0 && x < r && y >= 0 && y < c && tab[x][y])
                        cnt++;
                }

            cnt /= 2;
            ans = min(ans, cnt);
        }

    return ans;
}

/*************************************************************************/

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    FOR(i,1,t)
        cout << "Case #" << i << ": " << solve() << '\n';

    return 0;
}

/*************************************************************************/
