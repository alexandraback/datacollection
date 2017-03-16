#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int grid[20][20];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int r,c,n; scanf("%d%d%d",&r,&c,&n);
      int rc = r*c;
      int minsad = INT_MAX;
      for(int S=0; S<(1<<rc); S++){
         int ctr=0;
         for(int i=0; i<rc; i++){
            if (S&(1<<i)){
               ctr++;
               grid[i/c][i%c]=1;
            }
            else{
               grid[i/c][i%c]=0;
            }
         }
         if (ctr != n) continue;
         
         int sad=0;
         for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
               if (!grid[i][j]) continue;
               for(int k=0; k<4; k++){
                  pii nxt(i+dx[k],j+dy[k]);
                  if (nxt.first<0 || nxt.second<0 || nxt.first>=r || nxt.second>=c) continue;
                  if (grid[nxt.first][nxt.second]) sad++;
               }
            }
         }
         minsad = min(minsad,sad);
      }
      printf("Case #%d: %d\n",cs+1,minsad/2);
   }
}