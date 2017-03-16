#include<unordered_set>
#include<unordered_map>
#include<functional>
#include<algorithm>
//#include<iostream>
#include<numeric>
#include<cassert>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
//#include<cmath>
#include<set>
#include<map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b);i>=(e);--i)
#define FOReach(it,V) for(__typeof((V).begin()) it=(V).begin();it!=(V).end();++it)

#define PB push_back
#define ALL(V) (V).begin(),(V).end()
#define SIZE(V) ((int)(V).size())

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int __stmp;
#define scanf __stmp=scanf


const int INF = 1000000001;
const int MAX = 100000;

int main(int argc, char *argv[]) {
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d: ", z);
		int n1, n2;
		scanf("%d", &n1);
		VVI arr1(4, VI(4));
		REP(i,4) REP(j,4) scanf("%d", &arr1[i][j]);
		scanf("%d", &n2);
		VVI arr2(4, VI(4));
		REP(i,4) REP(j,4) scanf("%d", &arr2[i][j]);
		VI r;
		for(int i : arr1[n1-1]) if(find(ALL(arr2[n2-1]), i) != arr2[n2-1].end()) r.PB(i);
		if(r.empty()) printf("Volunteer cheated!\n");
		else if(SIZE(r) == 1) printf("%d\n", r[0]);
		else printf("Bad magician!\n");
	}
	return 0;
}

