#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
#define ll long long
#define pii acos(-1.0)
#define eqs 1e-10
struct node
{
        int x, y;
}fei[30];
int main()
{
  int t, i, j, k, Case=0, h, min1, ans1, ans2, n;
  double kk, bb, y;
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  scanf("%d",&t);
  while(t--){
      scanf("%d",&n);
      for(i=0;i<n;i++)
		scanf("%d%d",&fei[i].x,&fei[i].y);
      printf("Case #%d:\n",++Case);
      if(n==1){printf("0\n"); continue ;}
      for(i=0;i<n;i++){
        min1=INF;
	for(j=0;j<n;j++){
          if(i==j) continue ;
          ans1=ans2=0;
          if(fei[i].x==fei[j].x){
          for(k=0;k<n;k++){
            if(fei[k].x>fei[i].x) ans1++;
            else if(fei[k].x<fei[i].x) ans2++;
                          }
           min1=min(min1,min(ans1,ans2));
                                }
             else{
                  kk=(fei[i].y-fei[j].y)*1.0/(fei[i].x-fei[j].x);
                  bb=fei[i].y-fei[i].x*kk;
                  for(k=0;k<n;k++){
                      if(k==i||k==j) continue ;
                      y=kk*fei[k].x+bb;
                       if(fabs(fei[k].y*1.0-y)>eqs){
                         if(fei[k].y*1.0>y) ans1++;
                         else if(fei[k].y*1.0<y) ans2++;
                      }
                                  }
            min1=min(min1,min(ans1,ans2));
                            }
                 }
                 printf("%d\n",min1);
            }
  }
  return 0;
}

