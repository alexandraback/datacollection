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

#define MR 30

int t[MR];

void go(int N, set<pair<int, int > > &S)
{
	int sum = 0;
	REP(i, N) sum += t[i];
	while (!S.empty())
	{
		auto it = S.end(); it--;
		auto p = *it; S.erase(it);
		printf("%c", p.second + 'A');
		p.first--;
		sum--;
		if (p.first) S.insert(p);
		if (S.empty()) break;
		it = S.end(); it--;
		p = *it;
		if (p.first <= sum / 2) printf(" ");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	REP(c, T)
	{
		int N;
		scanf("%d", &N);
		set<pair<int, int > > S;
		REP(i, N)
		{
			scanf("%d", &t[i]);
			S.insert(MP(t[i], i));
		}
		printf("Case #%d: ", c + 1); go(N, S); printf("\n");
	}
	return 0;
}