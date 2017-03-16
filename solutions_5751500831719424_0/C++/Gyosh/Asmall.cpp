#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>

#define REP(a,b) for (int a = 0; a < b; a++)
#define FOR(a,b,c) for (int a = b; a <= c; a++)
#define RESET(a,b) memset(a,b,sizeof a)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PII pair<int,int>
#define INF 2123123123

#define LL long long
using namespace std;

int N,T,le;
char sc[105][105], ta[105];
int cnt[105][105];
int dp[105];

void extract(char s[], char t[]){
	int l = strlen(s);

	int p = 1;
	t[0] = s[0];
	FOR(i,1,l-1){
		if (t[p-1] != s[i]){
			t[p++] = s[i]; 
		}
	}
	t[p] = 0;
}

bool oke(){
	bool ya = 1;
	char tb[105];

	extract(sc[0], ta);
	FOR(i,1,N-1){
		extract(sc[i], tb);

		if (strcmp(ta, tb) != 0){
			ya = 0;
			break;
		}
	}

	return ya;
}

int rek(int pos){
	if (pos >= le){
		return 0;
	}else if (dp[pos] != -1){
		return dp[pos];
	}else{
		dp[pos] = INF;

		// mau berapa?
		FOR(i,1,100){
			int cost = 0;

			REP(j,N){
				cost += abs(i - cnt[j][pos]);
			}

			dp[pos] = min(dp[pos], cost + rek(pos+1));
		}

		return dp[pos];
	}
}

int build(){
	REP(i,N){
		int p = 0;
		REP(j,le){
			cnt[i][j] = 0;
			while (sc[i][p] == ta[j]){
				p++;
				cnt[i][j]++;
			}

//			printf("%d %d = %d\n", i,j, cnt[i][j]);
		}
	}
}

int main(){		
	scanf("%d", &T);
	REP(jt,T){
		scanf("%d", &N);
		REP(i,N){
			scanf("%s", sc[i]);
		}

		printf("Case #%d: ", jt+1);
		if (oke()){
			RESET(dp,-1);
			le = strlen(ta);
			build();
			printf("%d\n", rek(0));
		}else{
			printf("Fegla Won\n");
		}

	}
	return 0;
}
