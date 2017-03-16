#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define mp(a,b) make_pair((a),(b))
#define ff first
#define ss second

using namespace std;

int unhappy(int r, int s, vector<int> &occ){
  vector<vector<int> > rooms;
  int i,j,u,k;
  
  rooms.resize(r);
  
  k=0;
  
  for(i=0;i<r;i++){
    rooms[i].resize(s);
    for(j=0;j<s;j++){
      rooms[i][j] = occ[k];
      k++;
    }
  }
  
  u=0;
  
  for(i=0;i<r;i++){
    for(j=0;j<s;j++){
      if(rooms[i][j]){
        if(i>0){
          u+=rooms[i-1][j];
        }
        if(j>0){
          u+=rooms[i][j-1];
        }
      }
    }
  }
  
  /*for(i=0;i<r;i++){
    for(j=0;j<s;j++){
      printf("%d",rooms[i][j]);
    }putchar('\n');
  }putchar('\n');*/
  
  return u;
}

int main(){
  int i,m,n,r,s,t,T;
  vector<int> occ;
  
  scanf("%d",&T);
  
  for(t=0;t<T;t++){
    scanf("%d",&r);
    scanf("%d",&s);
    scanf("%d",&n);
    
    occ.resize(r*s);
    for(i=0;i<r*s;i++){
      occ[i]=0;
    }
    for(i=r*s-1;i>=r*s-n;i--){
      occ[i]=1;
    }
    
    m=123456789;
    
    do{
      if(unhappy(r,s,occ)<m){
        m=unhappy(r,s,occ);
      }
      //for(i=0;i<r*s;i++){printf("%d",occ[i]);}putchar('\n');
    }while(next_permutation(occ.begin(),occ.end()));
    
    printf("Case #%d: %d\n",t+1,m);
    
  }
  
  return 0;
}