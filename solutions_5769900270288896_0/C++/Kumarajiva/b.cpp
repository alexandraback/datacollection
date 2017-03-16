#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;


int a[20][20];
int n,m,k,ca,cas,x,i,j,ans,t,xx;

int Check(int x){

int c;

  c=0;
  while (x){
    if (x % 2) c++;
    x>>=1;
  }

  return c;

}



int main(){


  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&cas);
  for (ca=1;ca<=cas;ca++){
    scanf("%d%d%d",&n,&m,&k);
    ans=999999;
    for (x=0;x<(1<<(n*m));x++)
      if (Check(x)==k){
       // printf("!");
        memset(a,0,sizeof(a));
        xx=x;
        for (i=1;i<=n;i++)
          for (j=1;j<=m;j++){
            if (xx % 2) a[i][j]=1;
            xx>>=1;
          }
        t=0;
        for (i=1;i<=n;i++)
          for (j=1;j<=m;j++)
            if (a[i][j]){
              if (a[i-1][j]) t++;
              if (a[i+1][j]) t++;
              if (a[i][j-1]) t++;
              if (a[i][j+1]) t++;
            }
        ans=min(ans,t);
      }
    printf("Case #%d: %d\n",ca,ans/2);



  }

  return 0;


}

