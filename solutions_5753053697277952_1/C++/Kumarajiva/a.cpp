#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

int a[30];
int i,j,k,n,m,ca,cas,d,w,t;


int main(){

  freopen("a_l.in","r",stdin);
  freopen("a_l.out","w",stdout);
  scanf("%d",&cas);
  for (ca=1;ca<=cas;ca++){
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    t=0;
    for (i=1;i<=n;i++){
      scanf("%d",&a[i]);
      t+=a[i];
    }
    printf("Case #%d: ",ca);
    if (n==2){
      for (i=1;i<=(t/2);i++){
        for (j=1;j<=26;j++)
          if (a[j]) printf("%c",'A'+j-1);
        if (i==(t/2)) printf("\n");
        else printf(" ");

      }
      continue;
    }
    for (i=1;i<=t-2;i++){
      d=0;
      for (j=1;j<=26;j++)
        if (a[j]>d){
          d=a[j];
          w=j;
        }
      a[w]--;
      printf("%c",'A'+w-1);
    //  if (i==t) printf("\n");
      printf(" ");
    }
   for (i=1;i<=26;i++)
     if (a[i]) printf("%c",'A'+i-1);
   printf("\n");

  }
  return 0;



}
