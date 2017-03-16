#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>		//UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>		//do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;

#define MR 1010

int t[MR];

int main()
{
	int T;
	scanf("%d", &T);
	REP(c,T)
	{
		int N;
		scanf("%d", &N);
		REP(i,N) scanf("%d", &t[i]);
		int x = 0, y = 0, maxszam = 0;
		REP(i,N-1) if(t[i]-t[i+1] > 0)
		{
			x += t[i]-t[i+1];
			maxszam = max(maxszam, t[i]-t[i+1]);
		}
		REP(i,N-1) y += min(t[i], maxszam);
		printf("Case #%d: ", c+1);
		printf("%d %d\n", x, y);
	}
	return 0;
}