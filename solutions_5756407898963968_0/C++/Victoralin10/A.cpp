#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define fi first
#define se second
#define pii pair < int, int >
#define mp make_pair
#define pb push_back
#define scan1(_x) scanf("%d", &(_x))
#define scan2(_x,_y) scanf("%d%d", &(_x), &(_y))
#define scan3(_x,_y,_z) scanf("%d%d%d", &(_x), &(_y), &(_z))
#define FOR(_i,_a,_b) for(int (_i) = (_a); (_i) < (_b); (_i)++)
#define SETALL(_M,_v) memset((_M), (_v), sizeof (_M))
#define TEST() puts(" *** LIGERZERO *** ")
#define MAXN 100005
#define MOD 1000000007

using namespace std;

int tc, M[4][4], a;

int main(int nargs, char * args[])
{
	//int _inicio = clock();
	
	scan1(tc);
	for(int caso = 1; caso <= tc; caso++){
		set < int > A;
		scan1(a);
		FOR(i,0,4)
			FOR(j,0,4)
				scan1(M[i][j]);
		FOR(i,0,4)
			A.insert(M[a-1][i]);
		
		scan1(a);
		FOR(i,0,4)
			FOR(j,0,4)
				scan1(M[i][j]);
		
		set< int > B;
		FOR(i,0,4)
			if( A.find(M[a-1][i]) != A.end() ) B.insert(M[a-1][i]);
		
		if( B.size() == 0 ) printf("Case #%d: Volunteer cheated!\n",caso);
		else if( B.size() == 1 ) printf("Case #%d: %d\n", caso, *(B.begin()));
		else printf("Case #%d: Bad magician!\n", caso);
	}
	
	//printf("Time elapsed: %d ms", clock() - _inicio);
}
