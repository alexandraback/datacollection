#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 
#include <fstream>
using namespace std;
const double eps=1e-8;
const int maxn=100005;
typedef long long ll;
typedef pair<int,int> pii;

int g[20][20];
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};

int cnt;

int main() {
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int t;
	int r,c,n;
	int kase=1;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d",&r,&c,&n);
		int tot=r*c;
		int comb=(1<<n)-1;
		int ans=10000;
		if(n!=0) {
		while(comb<1<<tot) {
			memset(g,0,sizeof(g));
			for(int i=0;i<20;i++) {
				if(comb>>i&1) {
					int x=i/c+1;
					int y=i%c+1;
					g[x][y]=1;
				}
			}
			cnt=0;
			for(int i=1;i<=r;i++) {
				for(int j=1;j<=c;j++) {
					if(g[i][j]==1) {
						for(int k=0;k<4;k++) {
							int nx=i+dx[k],ny=j+dy[k];
							if(g[nx][ny]) cnt++;
						}
					}
				}
			}
			cnt/=2;
			ans=min(ans,cnt);
			int x=comb&-comb,y=comb+x;
			comb=((comb&~y)/x>>1)|y;
		}
		}
		else ans=0;
		//cout<<"!!!"<<r<<' '<<c<<' '<<n<<endl;
		printf("Case #%d: %d\n",kase++,ans);
	}


	return 0;
}
