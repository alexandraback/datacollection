#include <list>
#include <map>
#include <set>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional> 
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <string.h>
#include <stdio.h>
#include <limits.h>
//#include <unordered_map>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UNI;
typedef unsigned char UC;

#define STR(X) #X

#define ABS(a)      ((a>0)?a:-(a))
#define MIN(a,b)    ((a<b)?(a):(b))
#define MAX(a,b)    ((a<b)?(b):(a))
#define FOR(i,a,n)    for ( int i = (a); i < (n); ++i)
#define FOR_(i,a,n)		for ( int i = (a); i >= (n); --i)
#define FORI(n)        for(int i = 0; i < n; ++i)
#define MEMS(a,b)    memset(a,b,sizeof(a))

#define MP(p1, p2)      std::make_pair(p1, p2)
#define VI              std::vector<int>
#define SI              std::set<int>
#define PI				std::pair<int, int>
#define PL				std::pair<LL, LL>
#define PUI				std::pair<UNI, UNI>
#define RNG(container)  container.begin(), container.end()
#define endl			"\n"

const int       MOD = 1000000007;
const double    EXP = 2.7182818284590452;
const double    Pi = 3.1415926535;
const long double    EPS = 1e-9;
const int		INF = 1000 * 1000 * 1001;
const long long	INFL = (LL)INF * (LL)INF;

//map< pair<LL, LL>, LL > hashgcd;

LL gcd(LL a, LL b)
{
	if (a < b) swap(a, b);

	//	if (hashgcd.find(MP(a, b)) != hashgcd.end())
	//		return hashgcd[MP(a, b)];

	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}

	//	hashgcd[MP(a, b)] = a;

	return a;
}

LL lcm(LL a, LL b)
{
	return (a / gcd(a, b)) * b;
}

LL extgcd(LL a, LL b, LL & x, LL & y)
{
	if (a == 0)
	{
		x = 0; y = 1;
		return b;
	}

	LL x11, y11;
	LL d = extgcd(b % a, a, x11, y11);
	x = y11 - (b / a) * x11;
	y = x11;
	return d;
}

ULL poww(ULL v, ULL p, ULL mod)
{
	if (p == 0) return 1;

	if (p & 1)
	{
		return (poww(v, p - 1, mod) * v) % mod;
	}
	else
	{
		ULL t = poww(v, p / 2, mod);
		return (t * t) % mod;
	}
}

const ULL L31018 = 3000000000000000000L;
const ULL L1018 = 1000000000000000000L;

//////////////////
//////////////////
#define MAXN 20

set< PI, greater< PI > > arr;

PI t1, t2;
int n, a, sum, r, t;
char c1, c2;

void accept()
{
	cin >> t;

	FOR(k,1,t+1)
	{
		scanf("%d", &n);
		sum = 0;

		FOR(i, 0, n)
		{
			scanf("%d", &a);
			sum += a;

			arr.insert(MP(a, i));
		}

		printf("Case #%d: ", k);

		while (arr.size())
		{
			r = sum - arr.begin()->first;

			if (r == arr.begin()->first)
			{
				c1 = 'A' + arr.begin()->second;
				c2 = 'A' + arr.rbegin()->second;

				t1 = *arr.begin();
				t2 = *arr.rbegin();

				arr.erase((--arr.end()));
				arr.erase(arr.begin());

				--t1.first; --t2.first;

				if (t1.first)
					arr.insert(t1);
				if (t2.first)
					arr.insert(t2);

				sum -= 2;

				printf("%c%c ", c1, c2);
			}
			else if(r > arr.begin()->first)
			{
				c1 = 'A' + arr.rbegin()->second;
				t1 = *arr.rbegin();

				arr.erase((--arr.end()));

				--t1.first;

				if (t1.first)
					arr.insert(t1);

				sum -= 1;

				printf("%c ", c1);
			}
		}

		printf("\n");
	}
}

//		||
//		||
//     \||/
//    \\||//
//   \\\\////
//    \\\///
//     \\//
//      \/


const char inputFile[] = "busy_day.in";

int main(void)
{

#if Debug
	LL startTime = clock();
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//	freopen("cinema.in", "r", stdin);
	//	freopen("cinema.out", "w", stdout);
#endif

	//	test();
	accept();

#if Debug
	printf("\n\n\t TIME: %.5lf", double((clock() - startTime)) / 1000.0f); /// CLOCKS_PER_SEC));
	int l;
	cin >> l;
	//	_getch();
#endif
	return 0;
}