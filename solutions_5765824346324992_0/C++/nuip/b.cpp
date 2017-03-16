#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  int i,j,k,T;
  cin>>T;
  rep(Case,T){
    int n,pos;
    cin>>n>>pos;
    vector<ll> v(n);
    rep(i,n)
      cin>>v[i];
    
    ll l=0,r=v[0]*pos,m,sum;
    while(r-l>1){
      m=(l+r)/2;
      sum=0;
      rep(i,n)
	sum+=m/v[i]+1;
      if(sum>=pos)
	r=m;
      else
	l=m;
    }
    
    ll re;
    sum=pos;
    rep(i,n)
      sum-=l/v[i]+1;
    //cout<<r<<","<<sum<<endl;
    rep(i,n)if(r%v[i]==0){
      if(sum>1){
	--sum;
      }else{
	re=i+1;
	break;
      }
    }
    if(pos<=n)re=pos;
    cout<<"Case #"<<Case+1<<": "<<re<<endl;
  }
  return 0;
}
