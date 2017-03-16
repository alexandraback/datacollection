
// default code for competitive programming
// c2251393 ver 3.141 {{{

// Includes
#include <bits/stdc++.h>

// Defines
#define NAME(x) #x
#define SZ(c) (int)(c).size()
#define ALL(c) (c).begin(), (c).end()
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define REP(i, s, e) for(int i = (s); i <= (e); i++)
#define REPD(i, s, e) for(int i = (s); i >= (e); i--)
#define DEBUG 1
#define fst first
#define snd second
 
using namespace std;

// Typedefs
typedef double real;
typedef long long ll;
typedef pair<ll, int> pli;
typedef pair<int, int> pii;
typedef unsigned long long ull;

// Some common const.
const double EPS = -1e8;
const double Pi = acos(-1);
 
// Equal for double
bool inline equ(double a, double b)
{return fabs(a - b) < EPS;}

// }}}
// start ~~QAQ~~

int in[2][7][7];
int cnt[20];

int main()
{
	int t;
	scanf("%d", &t);
	REP(__, 1, t)
	{
		int r1;
		scanf("%d", &r1);
		fill(cnt, cnt+20, 0);
		REP(i, 1, 4) REP(j, 1, 4)
			scanf("%d", &in[0][i][j]);
		REP(j, 1, 4) cnt[in[0][r1][j]]++;
		int r2;
		scanf("%d", &r2);
		REP(i, 1, 4) REP(j, 1, 4)
			scanf("%d", &in[1][i][j]);
		REP(j, 1, 4) cnt[in[1][r2][j]]++;

		int flag = 0, ans = -1;
		REP(i, 1, 16) if(cnt[i] == 2)
		{
			flag++;
			ans = i;
		}
		printf("Case #%d: ", __);
		if(flag == 0) printf("Volunteer cheated!\n");
		else if(flag == 1) printf("%d\n", ans);
		else if(flag > 1) printf("Bad magician!\n");
	}
}
