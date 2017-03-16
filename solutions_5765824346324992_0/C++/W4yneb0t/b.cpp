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
in noct(in t, in mb){
  in sm=0;
  in lg=1000000009LL;
  forv(i,m){
    sm+=t/m[i]+1;
    if(t%m[i]==0 && i>mb)
      sm--;
    if(sm>lg)
      break;
  }
  return sm;
}
void docase(){
  in b,n;
  cin>>b>>n;
  m.resize(b);
  forn(i,b)
    cin>>m[i];
  in mnt=0;
  in mnb=0;
  in mxt=1000000000000000LL;
  in mxb=0;
  in mdt,mdb,numdt,numdb;
  while(mxt-mnt>1 || mxb-mnb>1 || (mxt==mnt+1 && !(mnb==b-1 && mxb==0))){
    mdt=(mxt+mnt)/2;
    if(mxt-mnt>1)
      mdb=0;
    if(mxt-mnt==0)
      mdb=(mxb+mnb)/2;
    if(mxt-mnt==1){
      if(mnb!=b-1)
	mdb=b-1;
      else
	mdb=0;
    }
    numdt=mdt;
    numdb=mdb;
    mdb--;
    if(mdb<0){
      mdb=b-1;
      mdt--;
    }
    if(noct(mdt,mdb)>=n){
      mxt=numdt;
      mxb=numdb;
    }
    else{
      mnt=numdt;
      mnb=numdb;
    }
  }
  cout<<mnb+1<<endl;
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
