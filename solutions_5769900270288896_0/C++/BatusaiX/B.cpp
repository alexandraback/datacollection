#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;

const int INF = 100000000;
int R, C, N;
const int MAXN = 32;
int A[MAXN][MAXN];

int count_unhappiness()
{
    int cnt = 0;
    int people = 0;
    for(int r = 0; r < R; ++r)
    {
       for(int c = 0; c < C; ++c)
       {
           if(A[r][c] == 1) people++;
           //cout << A[r][c] << " ";
           if(r - 1 >= 0 && A[r][c] == 1 && A[r-1][c] == 1) cnt++;
           if(c + 1 < C && A[r][c] == 1 && A[r][c+1] == 1) cnt++;
       }
       //cout << endl;
    }
    return people == N ? cnt: INF;
}


int main(int argc, char *argv[]) { 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int TC;
   cin >> TC;
   for(int tc = 1; tc <= TC; ++tc)
   {
       cin >> R >> C >> N;
       int NCELLS = (R*C);
       int ans = INF;
       for(int mask = 0; mask < (1 << NCELLS); ++mask)
       {
           memset(A, 0, sizeof(A));
           for(int r = 0; r < R; ++r)
           {
               for(int c = 0; c < C; ++c)
               {
                   int cell = r * C + c;
                   if(mask & (1 << cell))
                   {
                       A[r][c] = 1;
                   }
               }
           }
           ans = min(ans, count_unhappiness());
       }
       cout << "Case #" << tc << ": " << ans << endl;
   }
   
   return 0;
}
