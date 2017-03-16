//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x; }
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

using namespace std;

char s[105][105];
string ret[105];
vector<int> v[105];

int main(void){
#ifndef ONLINE_JUDGE
	freopen("/Users/mac/Desktop/A.in","r",stdin);
	freopen("/Users/mac/Desktop/a.out","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		static int ca = 1;
		printf("Case #%d: ",ca++);
		for(int i = 0;i<n;i++) v[i].clear();
		for(int i = 0;i<n;i++){
			scanf("%s",s[i]);
			ret[i] = "";
			int last = -1;
			for(int j = 0;s[i][j];j++){
				if(j&&s[i][j]==s[i][j-1]){
					continue;
				}
				ret[i]+=s[i][j];
				if(last!=-1)
					v[i].PB(j-last);
				last = j;
			}
			int l = strlen(s[i]);
			v[i].PB(l-last);
		}
		bool flag = false;
		for(int i = 1;i<n;i++){
			if(ret[i]!=ret[i-1]){
				puts("Fegla Won");
				flag = true;
			}
		}
		if(flag) continue;
		int sz = v[0].size();
		int ans = 0;
		for(int i = 0;i<sz;i++){
			vector<int> tmp;
			for(int j = 0;j<n;j++){
				tmp.PB(v[j][i]);
			}	
			sort(tmp.begin(),tmp.end());
			for(int j = 0;j<n;j++){
				ans+=abs(tmp[n/2]-tmp[j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

