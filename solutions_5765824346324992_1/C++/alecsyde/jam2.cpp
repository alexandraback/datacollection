#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const int mod = 1e9+7;

int arr[10005],n;
ll calc(ll x){
  ll ans=0;
  REP(i,n){
    ans+=x/arr[i]+1;
  }
  return ans;
}
int main(){
  int t;
  scanf("%d",&t);
  REPP(m,1,t+1){
    ll N;
    scanf("%d %lld",&n,&N);
    REP(i,n) scanf("%d",&arr[i]);
    printf("Case #%d: ",m);
    if(N<=n) {
      printf("%lld\n",N);
      continue;
    }
    ll l=0,r=1e18,p;
    while(l<r){
      p=(l+r)/2;
      if(calc(p)>=N) r=p;
      else l=p+1;
    }
    p=(l+r)/2;
    N-=calc(p-1);
    //debug(p);
    //debug(calc(p-1));
    REP(i,n){
      if(p%arr[i]==0){
        N--;
      }
      if(N==0){
        printf("%d\n",i+1);
        break;
      }
    }
  }

  return 0;
}
