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

int t[MR], N, B;

bool ok(LL tm)
{
	LL ile = 0;
	REP(i,B) ile += tm/t[i] + (tm%t[i] ? 1 : 0);
	return ile >= N;
}

int find(LL tm)
{
	LL ile = 0;
	REP(i,B) ile += tm/t[i] + (tm%t[i] ? 1 : 0);
	vector < pair < LL, int > > V;
	REP(i,B) 
		if(tm%t[i] == 0) V.PB(MP((tm/t[i]-1)*(LL)t[i]+1,i));
		else V.PB(MP(tm/t[i]*(LL)t[i]+1,i));
	sort(V.begin(), V.end());
	while(ile > N)
	{
		V.pop_back();
		ile--;
	}
	return V.back().ND;
}

LL BS(LL p, LL k)
{
	while(p < k)
	{
		LL s = (p+k)/2;
		if(ok(s)) k = s;
		else p = s+1;
	}
	return k;
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c,T)
	{
		scanf("%d%d", &B, &N);
		REP(i,B) scanf("%d", &t[i]);
		LL tm = BS(0LL, 100000000000000LL);
		int res = find(tm);
		printf("Case #%d: ", c+1);
		printf("%d\n", res+1);
	}
	return 0;
}