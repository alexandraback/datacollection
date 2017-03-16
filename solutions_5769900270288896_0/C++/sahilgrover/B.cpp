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

int ar[17][17];

int main(){
  int t;
  scanf("%d",&t);
  for(int i=1;i<=t;i++){
    int r,c,n,minI=1000000;
    scanf("%d %d %d",&r,&c,&n);
    int k=r*c;
    int m=1<<k;m--;
  //  printf("%d\n",m);
   for(int j=0;j<=m;j++){

      int s=0,a=j,cc=0;
      int ans=0;
      memset(ar,0,sizeof(ar));
      while(a>0){
        if(a%2==1){
          ar[s%r][s/r]=1;
          cc++;
        }
        a/=2;
        s++;
      }
      if(cc>n || cc<n)  continue;
      for(int aa=0;aa<r;aa++){
        for(int bb=0;bb<c-1;bb++){
          if(ar[aa][bb]==1 && ar[aa][bb+1]==1)  ans++;
        }
      }
//      printf("%d\n",ans);
      for(int aa=0;aa<c;aa++){
        for(int bb=0;bb<r-1;bb++){
          if(ar[bb][aa]==1 && ar[bb+1][aa]==1)  ans++;
        }
      }
      minI=min(minI,ans);
    }
    printf("Case #%d: %d\n",i,minI);
  }

  return 0;
}
