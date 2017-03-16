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
    // binary search
    ll ub = 1000000000LL * 1000000;
    ll lb = -1;
    while(ub-lb>1){
      ll mid = (ub + lb) / 2;
      // N番目に達するところで二分探索
      ll proc_num = 0;
      for(int i=0;i<B;i++)proc_num += mid / M[i] + 1;
      if(proc_num>=N)ub=mid;
      else lb=mid;
    }
    ll proc_num = 0;
    for(int i=0;i<B;i++)proc_num += ub / M[i] + 1;
    ll diff = proc_num - N;
    int cnt = 0;

    for(int i=B-1;i>=0;i--){
      if(ub % M[i] == 0){
        if(cnt==diff){
          cout<<i+1<<endl;
          break;
        }
        cnt++;
      }
    }
    
  }
  
  return 0;
}
