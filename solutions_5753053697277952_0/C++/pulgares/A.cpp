#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <set>
#include <limits>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d %d", &x, &y)
#define SYNC ios_base::sync_with_stdio(false)

typedef long long ll;

int cnt[30], N;

int main(){
	int TC; ri(TC);
	FOR(tc,1,TC+1){
		int sum = 0;
		priority_queue<pair<int, int> > pq;
		ri(N);
		FOR(i,0,N){
			ri(cnt[i]);
			sum+=cnt[i];
			pq.push({cnt[i], i});
		}
		printf("Case #%d:",tc);
		while(sum>2){
			if(N == 2 && cnt[0] == cnt[1]){
				int x1=pq.top().first, c1 = pq.top().second; pq.pop();
				int x2=pq.top().first, c2 = pq.top().second; pq.pop();
				x1--; x2--;
				cnt[c1]--; cnt[c2]--;
				sum-=2;
				printf(" %c%c",c1+'A',c2+'A');
				if(x1 > 0)
					pq.push({x1,c1});
				if(x2 > 0)
					pq.push({x2,c2});
				continue;
			}
			int x = pq.top().first, c = pq.top().second; pq.pop();
			printf(" %c",c+'A');
			x--;
			cnt[c]--;
			sum--;
			if(x > 0)
				pq.push({x,c});
		}
		int x1=pq.top().first, c1 = pq.top().second; pq.pop();
		int x2=pq.top().first, c2 = pq.top().second; pq.pop();
		printf(" %c%c\n",c1+'A',c2+'A');

	}
	
}

