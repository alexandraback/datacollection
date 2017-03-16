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

int a[MAXN];
int B,n;

bool ok(ll tim)
{
	ll num=0;
	fru(i,B)num+=(tim/a[i])+1;
	return num>=n;
}
void solve() {
	scanf("%d%d",&B,&n);
	fru(i,B)scanf("%d",&a[i]);
	ll pocz=0,kon=1000000000LL*1000000;
	if(ok(pocz))
	{
		printf("%d\n",n);
		return ;
	}
	while(pocz+1<kon)
	{
		ll med=(pocz+kon)/2;
	//	printf("sprawdez %lld\n",med);
		if(ok(med))kon=med;
		else pocz=med;
	}
	ll time=kon;
//	printf("moj czas %lld\n",time);
	vi P;
	fru(i,B)
	{
		n-=((time-1)/a[i])+1;
		if(time%a[i]==0)P.pb(i+1);
	}
//	printf("%d\n",n);
	printf("%d\n",P[n-1]);
}

int main(){
	int t=1;scanf("%d",&t);
	fru(i,t)
	{
		printf("Case #%d: ",i+1);
		solve();
	}
	return 0;
}

