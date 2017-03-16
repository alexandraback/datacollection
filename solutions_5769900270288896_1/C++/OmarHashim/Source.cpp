//#define _CRT_SECURE_NO_WARNINGS
//#include<algorithm>
//#include<stdlib.h>
//#include<iterator>
//#include<iostream>
//#include<numeric>
//#include<sstream>
//#include<cstring>
//#include<ctype.h>
//#include<iomanip>
//#include<stdio.h>
//#include<fstream>
//#include<vector>
//#include<bitset>
//#include<string>
//#include<math.h>
//#include<queue>
//#include<stack>
//#include<cmath>
//#include<set>
//#include<map>
//
//using namespace std;
//
//#define all(v)             v.begin(),v.end()
//#define sz(v)            ((int)((v).size()))
//#define psh(x)                  push_back(x)
//#define sc(x)                 scanf("%d",&x)
//#define sc2(x,y)         scanf("%d%d",&x,&y)
//#define scl(x)              scanf("%lld",&x)
//#define lop(i,n)        for(int i=0;i<n;++i)
//#define loop(i,f,l)     for(int i=f;i<l;++i)
//#define R_(s)         freopen(s, "r", stdin)
//#define W_(s)        freopen(s, "w", stdout)
//#define R_W R_("input.txt"),W_("output.txt")
//#define PI           acos(-1)
//#define INF             1<<30
//#define DFS_GRAY           -1
//#define DFS_WHITE           0
//#define DFS_BLACK           1
//
//typedef string            ss;
//typedef long long         ll;
//typedef pair <int, int>   ii;
//typedef pair<ss, int>     si;
//typedef pair<int, ss>     is;
//typedef pair<char, int>  chi;
//typedef pair<ss, ss>     pss;
//typedef vector<ii>       vii;
//typedef vector<int>       vi;
//typedef vector<vi>       vvi;
//typedef vector<ss>        vs;
//typedef vector<ll>       vll;
//typedef vector<vll>     vvll;
//
//ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
//ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); }
//ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
//ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }
//
//bool grid[16][16] = { 0 };
//int T, n, r, c, out;
//int check()
//{
//	int ret = 0;
//	lop(i, r)
//		lop(j,  c - 1)
//			if (grid[i][j] && grid[i][j + 1])++ret;
//
//			lop(j,c)
//				lop(i,r-1)
//			if (grid[i][j] && grid[i + 1][j])++ret;
//			
//			return ret;
//}
//int main()
//{
//	R_W;
//	cin >> T;
//	loop(cs, 1, T + 1)
//	{
//		out = INF;
//		sc2(r,c);
//		sc(n);
//		for (int mask = 0; mask <= (1 << (r*c)); ++mask)
//		{
//			int cnt = 0;
//			lop(i, r*c)if (mask&(1 << i))++cnt;
//			if (cnt == n)
//			{
//				//fix grid
//				lop(i, r)lop(j, c)grid[i][j] = mask&(1 << (i*c + j));
//				///////////////////////////////////////
//				out = min(out, check());
//			}
//		}
//		printf("Case #%d: %d\n", cs,out);
//	}
//}
#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<stdlib.h>
#include<iterator>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<stdio.h>
#include<fstream>
#include<vector>
#include<bitset>
#include<string>
#include<math.h>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<map>

using namespace std;

#define all(v)             v.begin(),v.end()
#define sz(v)            ((int)((v).size()))
#define psh(x)                  push_back(x)
#define sc(x)                 scanf("%d",&x)
#define sc2(x,y)         scanf("%d%d",&x,&y)
#define scl(x)              scanf("%lld",&x)
#define lop(i,n)        for(int i=0;i<n;++i)
#define loop(i,f,l)     for(int i=f;i<l;++i)
#define R_(s)         freopen(s, "r", stdin)
#define W_(s)        freopen(s, "w", stdout)
#define R_W R_("input.txt"),W_("output.txt")
#define PI           acos(-1)
#define INF             1<<30
#define DFS_GRAY           -1
#define DFS_WHITE           0
#define DFS_BLACK           1

typedef string            ss;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<ss, int>     si;
typedef pair<int, ss>     is;
typedef pair<char, int>  chi;
typedef pair<ss, ss>     pss;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<ss>        vs;
typedef vector<ll>       vll;
typedef vector<vll>     vvll;

ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
ll gcd(ll a, ll b)  { return (b == 0 ? a : gcd(b, a % b)); }
ll sd(ll x)  { return x<10 ? x : x % 10 + sd(x / 10); }
ll lcm(ll a, ll b){ return ((a*b) / gcd(a, b)); }



int main()
{
	R_W;
	ll T, n, r, c, out,easy,sides,rest;
	cin >> T;
	loop(cs, 1, T + 1)
	{
		out = 0;
		cin >> r >> c >> n;
		easy = (r*c + 1) / 2;
		sides = 2 * ((r / 2) + (c / 2));
		rest = (r*c) - easy - sides;
		n -= easy;
		if (n > 0)
		{
			if (n < sides)
			{
				out += n * 3;
				n = 0;
			}
			else
			{
				out += sides * 3;
				n -= sides;
			}
		}
		if (n > 0)
		{
			out += 4 * n;
		}
		next:
		printf("Case #%d: %lld\n", cs, out);
	}
}