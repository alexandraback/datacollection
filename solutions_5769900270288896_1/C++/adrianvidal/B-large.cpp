#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int f(int n, int r, int c){
   int grid[r][c];
   for(int i=0; i<c; i++) grid[0][i] = i%2;
   for(int i=1; i<r; i++){
      for(int j=0; j<c; j++) grid[i][j] = !grid[i-1][j];
   }
   int ctr=0;
   for(int i=0; i<r; i++){
      for(int j=0; j<c; j++) ctr += grid[i][j];
   }
   
   if (n<=ctr) return 0;
   n-=ctr;
   int deg1=0,deg2=0,deg3=0,deg4=0;
   
   for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
         if (grid[i][j]) continue;
         int neighbor=0;
         for(int k=0; k<4; k++){
            pii nxt(i+dx[k],j+dy[k]);
            if (nxt.first<0 || nxt.second<0 || nxt.first>=r || nxt.second>=c) continue;
            neighbor += grid[nxt.first][nxt.second];
         }
         if (neighbor==1) deg1++;
         else if (neighbor==2) deg2++;
         else if (neighbor==3) deg3++;
         else if (neighbor==4) deg4++;
      }
   }
   if (n<=deg1) return n;
   n-=deg1;
   if (n<=deg2) return deg1 + 2*n;
   n-=deg2;
   if (n<=deg3) return deg1 + 2*deg2 + 3*n;
   n-=deg3;
   return deg1 + 2*deg2 + 3*deg3 + 4*n;
}

int g(int n, int r, int c){
   int grid[r][c];
   for(int i=0; i<c; i++) grid[0][i] = 1-(i%2);
   for(int i=1; i<r; i++){
      for(int j=0; j<c; j++) grid[i][j] = !grid[i-1][j];
   }
   int ctr=0;
   for(int i=0; i<r; i++){
      for(int j=0; j<c; j++) ctr += grid[i][j];
   }
   
   if (n<=ctr) return 0;
   n-=ctr;
   int deg1=0,deg2=0,deg3=0,deg4=0;
   
   for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
         if (grid[i][j]) continue;
         int neighbor=0;
         for(int k=0; k<4; k++){
            pii nxt(i+dx[k],j+dy[k]);
            if (nxt.first<0 || nxt.second<0 || nxt.first>=r || nxt.second>=c) continue;
            neighbor += grid[nxt.first][nxt.second];
         }
         if (neighbor==1) deg1++;
         else if (neighbor==2) deg2++;
         else if (neighbor==3) deg3++;
         else if (neighbor==4) deg4++;
      }
   }
   if (n<=deg1) return n;
   n-=deg1;
   if (n<=deg2) return deg1 + 2*n;
   n-=deg2;
   if (n<=deg3) return deg1 + 2*deg2 + 3*n;
   n-=deg3;
   return deg1 + 2*deg2 + 3*deg3 + 4*n;
}
int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int r,c,n; scanf("%d%d%d",&r,&c,&n);
      if (r > c) swap(r,c);
      
      printf("Case #%d: %d\n",cs+1,min(f(n,r,c),g(n,r,c)));
   }
}