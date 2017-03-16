#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int a[100010];
int main(){
#ifdef QWERTIER
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    printf("Case #%d: ",kase);
    int n,ans1=0,ans2=0,v=0;
    scanf("%d",&n);
    FOR(i,n){
      scanf("%d",&a[i]);
      if(i>1 && a[i]<a[i-1]){
        ans1+=a[i-1]-a[i];
        v=max(v,a[i-1]-a[i]);
      }
    }
    FOR(i,n-1){
      ans2+=min(v,a[i]);
    }
    printf("%d %d\n",ans1,ans2);
  }
  return 0;
}
