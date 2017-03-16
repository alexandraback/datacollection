#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define N 102
string a[N];
int b[N][N];
int t,tt,n;

int main(){
  int i,j,k;
  freopen("1.txt","r",stdin);
  freopen("2.txt","w",stdout);
  scanf("%d",&t);
  for (tt=1;tt<=t;++tt){
    scanf("%d",&n);
    memset(b,0,sizeof(b));
    for (i=0;i<n;++i){
      cin>>a[i];
      k=0;
      for (j=1;j<a[i].length();++j)
        if (a[i][j]==a[i][j-1]){
          a[i]=a[i].erase(j,1);
          --j;
          ++b[k][i];
        }
        else ++k;
    }
    printf("Case #%d: ",tt);
    for (i=1;i<n;++i)
      if (a[i]!=a[0]) break;
    if (i<n) puts("Fegla Won");
    else {
      k=a[0].length();
      for (i=0;i<k;++i)
        sort(b[i],b[i]+n);
      int s=0;
      if (n&1){
        for (i=0;i<k;++i){
          for (j=0;j<n/2;++j) s+=b[i][n/2]-b[i][j];
          for (;j<n;++j) s+=b[i][j]-b[i][n/2];
        }
      }
      else {
        for (i=0;i<k;++i){
          int temp=(b[i][n/2]+b[i][n/2-1])/2;
          for (j=0;j<n/2;++j) s+=temp-b[i][j];
          for (;j<n;++j) s+=b[i][j]-temp;
        }
      }
      printf("%d\n",s);
    }
  }
  return 0;
}