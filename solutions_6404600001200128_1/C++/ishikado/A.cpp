#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int N;
int M[1010];
int main(){
  fastStream();
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    cout<<"Case #"<<t<<": ";
    cin>>N;
    for(int i=0;i<N;i++)cin>>M[i];
    ll ans1 = 0;
    for(int i=1;i<N;i++){
      ans1 += max(0, M[i-1] - M[i]);
    }
    ll ans2 = 1LL<<60;
    for(int i=0;i<=10000;i++){
      ll tmp=0;
      bool ok=true;
      for(int j=0;j<N-1;j++){
        tmp+=min(i, M[j]);
        ll left = M[j] - min(i, M[j]);
        if(j+1<N&&left>M[j+1]){
          ok=false;
          break;
        }
      }
      if(ok){
        ans2=min(ans2,tmp);
      }
    }
    cout<<ans1<<" "<<ans2<<endl;
  }
  
  return 0;
}
