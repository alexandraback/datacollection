#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int Tc;
int n,t[MAX];
int ans,ans2;

void solve(){
  ans=ans2=0;
  int maxm=0;
  for(int i=1;i<n;i++){
    if(t[i-1]>t[i]){
      ans+=(t[i-1]-t[i]);
      maxm=max(maxm,t[i-1]-t[i]);
    }
  }
  for(int i=0;i<n-1;i++){
    ans2+=min(maxm,t[i]);
  }
}

int main(){
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    cin>>n;
    for(int i=0;i<n;i++)cin>>t[i];
    solve();
    cout<<"Case #"<<tc<<": "<<ans<<' '<<ans2<<endl;
  }
  return 0;
}
