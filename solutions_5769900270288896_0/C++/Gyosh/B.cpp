#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>

#define REP(a,b) for (int a = 0; a < b; a++)
#define FOR(a,b,c) for (int a = b; a <= c; a++)
#define RESET(a,b) memset(a,b,sizeof a)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PII pair<int,int>
#define INF 2123123123

#define MAXN 1000005
#define LL long long
using namespace std;

int T,N,R,C;
int perm[20];
bool place[20][20];

int cost(){
	REP(i,R){
		REP(j,C){
			place[i][j] = (perm[C*i + j] == 1);
		}
	}

	int ret = 0;
	REP(i,R){
		REP(j,C){
			if ((j+1 < C) && place[i][j] && place[i][j+1]) ret++;
			if ((i+1 < R) && place[i][j] && place[i+1][j]) ret++;
		}
	}

	return ret;
}

int main(){		
	scanf("%d", &T);
	REP(jt,T){
		scanf("%d%d%d", &R, &C, &N);

		REP(i,R*C){
			perm[i] = 0;
		}
		REP(i,N){
			perm[i] = 1;
		}
		sort(perm, perm + R*C);

		int ans = INF;
		do{
			ans = min(ans, cost());
		}while (next_permutation(perm, perm + R*C));

		printf("Case #%d: %d\n", 1+jt, ans);
	}

	return 0;
}
