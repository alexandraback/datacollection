#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

ll gcd(ll a,ll b){
  if(b==0)return a;
  return gcd(b,a%b);
}

ll lcm(ll a,ll b){
  return (ll)a*b/gcd(a,b);
}


int B,N;
int M[1010];
int main(){
  fastStream();
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    cout<<"Case #"<<t<<": ";
    cin>>B>>N;
    for(int i=0;i<B;i++)cin>>M[i];
    ll l=1;
    for(int i=0;i<B;i++)l=lcm(l,M[i]);
    ll proc=0;
    for(int i=0;i<B;i++)proc+=l/M[i];
    N = N % proc;
    if(N==0) N += proc;
    int ans = -1;
    for(int t = 0 ;; t++){
      for(int i=0;i<B;i++){
        if(t % M[i] == 0){
          N--;
        }
        if(N==0){
          ans = i+1;
          break;
        }
      }
      if(ans!=-1)break;
    }
    cout<<ans<<endl;
  }
  
  return 0;
}
