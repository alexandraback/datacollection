#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

int d[4][2];

int main()
{
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-small-attempt1.out","w",stdout);
#endif
	int r,c,n;
	int t,cs=1;
	cin>>t;
	while(t--){
		cin>>r>>c>>n;
		int tn=n;
		int ans = 0, ans3 = 0;
		int cnt = 0, cnt2 = 0;
		int cc[5]={0}, cc2[5]={0};
		REP(i,r)
		REP(j,c) {
			if((i+j)%2==1) {
				cnt++;
				
				int p=0;
				if(i>0) p++;
				if(j>0) p++;
				if(i<r-1) p++;
				if(j<c-1) p++;
				cc2[p]++;
			}else{
				cnt2++;
				int p=0;
				if(i>0) p++;
				if(j>0) p++;
				if(i<r-1) p++;
				if(j<c-1) p++;
				cc[p]++;
			}
		}
		n=max(n-cnt,0);
		while(n) {
			REP(i,5) {
				if(cc[i]) {
					cc[i]--;
					n--;
					ans+=i;
					break;
				}
			}
		}
		n=tn;
		n=max(n-cnt2,0);
		while(n) {
			REP(i,5) {
				if(cc2[i]) {
					cc2[i]--;
					n--;
					ans3+=i;
					break;
				}
			}
		}
		/*
		n=tn;
		int ans2 = INF;
		REP(i,(1<<(r*c))){
			int o=i,cc=0;
			int a[32][32]={0};
			REP(j,r*c) {
				if(o&1) {
					a[j/c][j%c]=1;
					cc++;
				}
				o>>=1;
			}
			if(cc==n) {
				int x=0;
				REP(i,r)
				REP(j,c) if(a[i][j]){
					if(a[i+1][j]) x++;
					if(a[i][j+1]) x++;
				}
				ans2 = min(ans2, x);
			}
		}
		*/
		cout<<"Case #"<<cs++<<": "<<min(ans,ans3)<<endl;//<<' '<<ans2<<endl;
	}
	return 0;
}


