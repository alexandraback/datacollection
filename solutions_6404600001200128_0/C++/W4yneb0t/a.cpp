#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VI m;
void docase(){
  in n;
  cin>>n;
  m.resize(n);
  forn(i,n)
    cin>>m[i];
  in mn=0;
  in mxd=0;
  for(in i=1;i<n;i++){
    if(m[i-1]>m[i]){
      mn+=m[i-1]-m[i];
      mxd=max(mxd,m[i-1]-m[i]);
    }
  }
  cout<<mn<<" ";
  mn=0;
  for(in i=0;i<n-1;i++){
    mn+=min(mxd,m[i]);
  }
  cout<<mn<<endl;
}
int main(){
  in T;
  cin>>T;
  for(in zz=1;zz<=T;zz++){
    cout<<"Case #"<<zz<<": ";
    docase();
  }
  return 0;
}
