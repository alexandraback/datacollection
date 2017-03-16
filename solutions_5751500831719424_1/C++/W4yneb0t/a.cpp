#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
vector<string> vs;
vector<vector<char> > vc;
vector<vector<in> > vi;
int main(){
  in tt;
  cin>>tt;
  for(in zz=1;zz<=tt;zz++){
    cout<<"Case #"<<zz<<": ";
    in n;
    cin>>n;
    vs.clear();
    vs.resize(n,"");
    vi.clear();
    vi.resize(n,vector<in>(0));
    vc.clear();
    vc.resize(n,vector<char>(0));
    forn(i,n){
      cin>>vs[i];
      forv(j,vs[i]){
	if(j==0 || vs[i][j]!=vs[i][j-1]){
	  vc[i].PB(vs[i][j]);
	  vi[i].PB(1);
	}
	else{
	  vi[i][sz(vi[i])-1]++;
	}
      }
    }
    bool ok=1;
    for(in i=1;ok && i<n;i++){
      if(sz(vc[i])!=sz(vc[0])){
	ok=0;
	break;
      }
      forv(j,vc[i]){
	if(vc[i][j]!=vc[0][j]){
	  ok=0;
	  break;
	}
      }
    }
    if(!ok){
      cout<<"Fegla won"<<endl;
      continue;
    }
    in mv=0;
    vector<in> cc;
    forv(i,vi[0]){
      cc.clear();
      forn(j,n)
	cc.PB(vi[j][i]);
      sort(cc.begin(),cc.end());
      in md=n/2;
      forn(j,md)
	mv+=cc[md]-cc[j];
      for(in j=md+1;j<n;j++)
	mv+=cc[j]-cc[md];
    }
    cout<<mv<<endl;
  }
  return 0;
}

