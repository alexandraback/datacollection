#include<bits/stdc++.h>
using namespace std;
int H,W,N;
int ans;
int t[100][100];

void solve(int y,int x,int cnt,int sum){
  if(y==H&&x==0){
    if(cnt==N)ans=min(ans,sum);
    return;
  }
  if(x==W){
    solve(y+1,0,cnt,sum);
    return;
  }

  solve(y,x+1,cnt,sum);
  if(cnt<N){
    t[y][x]=1;
    int d=0;
    if(y&&t[y-1][x]==1)d++;
    if(x&&t[y][x-1]==1)d++;
    solve(y,x+1,cnt+1,sum+d);
    t[y][x]=0;
  }
}

int main(){
  int T;
  cin>>T;
  for(int tc=1;tc<=T;tc++){
    for(int i=0;i<100;i++)
      for(int j=0;j<100;j++)
        t[i][j]=0;
    cin>>H>>W>>N;
    ans=1e9;
    solve(0,0,0,0);
    cout<<"Case #"<<tc<<": "<<ans<<endl;
  }
  return 0;
}
