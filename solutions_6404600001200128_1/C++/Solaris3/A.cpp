#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int MAXN = 1000006;//10^6

int t[MAXN];
void solve() {
	int n,sum1=0,maxi1=0;
	scanf("%d",&n);
	fru(i,n)scanf("%d",&t[i]);
	fru(i,n)if(i)
	{
		sum1+=max(0,t[i-1]-t[i]);
		maxi1=max(maxi1,t[i-1]-t[i]);
	}
	int sum2=0;
	fru(i,n)if(i)
	{
		sum2+=min(t[i-1],maxi1);
	}
	printf("%d %d\n",sum1,sum2);
}

int main(){
	int te=1;scanf("%d",&te);
	fru(i,te)
	{
		printf("Case #%d: ",i+1);
		solve();
	}
	return 0;
}

