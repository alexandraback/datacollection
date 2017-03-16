#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
int N,R,C;
int arr[17][17];

int count(){
  int c=0;
  int b=0;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(arr[i][j]==1){
	c++;
	if(arr[i+1][j]==1)
	  b++;
	if(arr[i][j+1]==1)
	  b++;
      }
    }
  }
  if(c==N)
    return b;
  else 
    return 10000;
}

int ric(int x,int y){
  if(x==0 && y==C){
    return count();
  }else{
    //    cout<<x<<" "<<y<<endl;
    int nx = (x+1)%R;
    int ny = (x==R-1) ? y+1: y;
    arr[x][y]=0;
    int ans= ric(nx,ny);
    arr[x][y]=1;
    ans = min(ans,ric(nx,ny));
    return ans;
  }
}

int solve(){
  cin>>R>>C>>N;
  assert(R*C<=16);
  for(int i=0;i<17;i++){
    arr[R][i]=0;
    arr[i][C]=0;
  }
    
  return ric(0,0);
}

int main(){
  int cases;
  cin>>cases;
  for(int i=0;i<cases;i++){
    cout<<"Case #"<<i+1<<": "<<solve()<<endl;
  }
  return 0;
}
