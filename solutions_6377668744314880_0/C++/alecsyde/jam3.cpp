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

pair<ll,ll> arr[10005];

ll gcd(ll a,ll b){
  if(a<0) a=-a;
  if(b<0) b=-b;
  if(a==0&&b==0) return 1;
  ll c;
  while(b!=0){
    c=b;
    b=a%b;
    a=c;
  }
  return a;
}
int main(){
  int t,n;
  scanf("%d",&t);
  pair<ll,ll> p;
  ll q;
  REPP(m,1,t+1){
    scanf("%d",&n);
    REP(i,n) scanf("%lld %lld",&arr[i].X,&arr[i].Y);
    printf("Case #%d:\n",m);
    if(n==1){
      printf("0\n");
      continue;
    }
    REP(i,n){
      int l=1e9;
     REP(j,n){
      if(j!=i){
      int a=0,b=0;
      REP(k,n){
        p=mp((arr[j].Y-arr[i].Y)*(arr[k].X-arr[i].X),arr[j].X-arr[i].X);
        q=arr[k].Y-arr[i].Y;

        if(p.X<q*p.Y) a++;
        else if(p.X>q*p.Y) b++;
      }
    //  if(i==4) printf("%d %d %d",&j,&)
      l=min(l,a);
      l=min(l,b);
      }
      }
    printf("%d\n",l);
    }
  }
  return 0;
}
