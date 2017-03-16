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

int arr[100005];

int main(){
  int t;
  scanf("%d",&t);
  REPP(m,1,t+1){
    int n;
    scanf("%d",&n);
    int x=0,y=0,p;
    REP(i,n) {
      scanf("%d",&arr[i]);
      if(i>=1){
        if(arr[i]<arr[i-1]) {
          x+=arr[i-1]-arr[i];
          y=max(arr[i-1]-arr[i],y);
        }
      }
    }
    printf("Case #%d: %d ",m,x);
    x=0;
    REP(i,n-1){
      x+=arr[i]-max(arr[i]-y,0);
    }
    printf("%d\n",x);
  }
  return 0;
}
