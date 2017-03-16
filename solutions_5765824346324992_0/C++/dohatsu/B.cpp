#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

#define MAX 1005
ll B,N;
ll t[MAX];
ll u[MAX];

ll check(ll x){
  if(x==0)return 0;
  ll sum=0;
  for(int i=0;i<B;i++){
    sum+=(x/t[i]);
  }
  return sum;
}

ll solve(){
  ll target=N-B;
  ll L=0,R=10000000000000000LL,M,m;

  while(L<R){

    M=(L+R)/2LL;
    m=check(M);

    if(m<target){
      L=M+1;
    }else if(m>=target){
      R=M;
    }
  }

 

  ll id=check(L)+B;
  for(int i=0;i<B;i++)if(L%t[i]==0)id--;

  while(1){
    for(int i=0;i<B;i++){
      u[i]=L%t[i];
    }
    for(int i=0;i<B;i++){
      if(u[i]==0){
	id++;
	if(N==id)return i+1;
      }
    }
    L++;
  }
  
  /*
  for(int i=0;i<B;i++){
    u[i]=P(L%t[i],i+1);
  
  }
  
  sort(u,u+B);
  
  if(N-id-1<0){
    assert(false);
    
  }
  if(u[(N-id-1LL)%B].first!=0){
    cout<<B<<' '<<N<<endl;
    for(int i=0;i<B;i++)cout<<t[i]<<' ';
    cout<<endl;
    cout<<L<<' '<<target<<' '<<id<<endl;
    for(int i=0;i<B;i++){
      u[i]=P(L%t[i],i+1);
      cout<<u[i].first<<' '<<u[i].second<<endl;
    }
    assert(false);
  }
  return u[(N-id-1LL)%B].second;
  */
}

int main(){
  int Tc;
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    cin>>B>>N;
    for(int i=0;i<B;i++)cin>>t[i];
    
    cout<<"Case #"<<tc<<": "<<solve()<<endl;
  }
  return 0;
}
