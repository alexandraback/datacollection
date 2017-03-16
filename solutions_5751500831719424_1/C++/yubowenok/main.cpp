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
#define MAXN 105

int N;
vector< PII > s[MAXN];
char buf[MAXN];
int main(){
	int cs;
	cin >> cs;
	REP(csn,1,cs+1){
		printf("Case #%d: ", csn);
		cin >> N;
		string x;
		REP(i,0,N){
			s[i].clear();
		}
		REP(i,0,N){
			scanf("%s", buf);
			int len = strlen(buf);
			REP(j,0,len){
				int k = j;
				while(k<len && buf[k]==buf[j]) k++;
				s[i].push_back( make_pair((int)buf[j], k-j) );
				j = k-1;
			}
		}
		bool ok = 1;
		int kds = s[0].size();
		REP(i,0,N){
			if(s[i].size()!=kds) {
				ok = 0;
				break;
			}
			REP(j,0,kds){
				if(s[i][j].first!=s[0][j].first){
					ok = 0;
					break;
				}
			}
			if(!ok) break;
		}
		if(!ok){
			puts("Fegla Won");
			continue;
		}
		int ans = 0;
		REP(j,0,kds){
			int cc[MAXN];
			REP(i,0,N){
				cc[i] = s[i][j].second;
			}
			sort(cc, cc+N);
			int t = cc[N/2];
			int sol = 0;
			REP(i,0,N){
				sol += abs(cc[i]-t);
			}
			ans += sol;
		}
		printf("%d\n", ans);
	}
	return 0;
}