#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;

int cnt[17];
int main(){
	int cs,k,x;
	cin >> cs;
	REP(csn,1,cs+1){
		FILL(cnt, 0);
		REP(t,0,2){
			cin >> k;
			REP(i,0,4) REP(j,0,4){
				scanf("%d", &x);
				if(i+1==k) cnt[x]++;
			}
		}
		int ans = 0, id;
		REP(i,1,17){
			if(cnt[i]==2) {
				ans++;
				id = i;
			}
		}
		printf("Case #%d: ", csn);
		if(ans==1) printf("%d\n", id);
		else if(ans>1) puts("Bad magician!");
		else if(ans==0) puts("Volunteer cheated!");
	}
	return 0;
}