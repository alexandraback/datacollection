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
struct pt;
vector<pt> vp;
#define base vp[0]
const in lef=-1;
const in rig=1;
const in str=0;
in tria(const pt& a, const pt& b, const pt& c);
struct pt{
  in x,y;
  pt(in a=0, in b=0){x=a;y=b;}
  pt operator-(const pt& cp)const{
    return pt(x-cp.x,y-cp.y);
  }
  pt operator+(const pt& cp)const{
    return pt(x+cp.x,y+cp.y);
  }
  in operator^(const pt& cp)const{
    return x*cp.y-y*cp.x;
  }
  bool operator<(const pt cp)const{
    in cr=tria(base,base+pt(1,0),*this);
    in cpr=tria(base,base+pt(1,0),cp);
    if((cr==rig)!=(cpr==rig))
      return cpr==rig;
    if(cr==str && x<base.x)return (cpr==str && cp.x<x);
    if(cr==str && x>base.x)return !(cpr==str && cp.x>x);
    if(cpr==str && cp.x<base.x)return 1;
    if(cpr==str)return 0;
    cr=tria(base,*this,cp);
    if(cr==str)return y<cp.y;
    return cr==lef;
  }
};
in tria(const pt& a, const pt& b, const pt& c){
  in cc=(b-a)^(c-a);
  if(cc==0)return str;
  if(cc>0)return lef;
  return rig;
}
vector<pt> spts;
vector<pt> mpts;
in mrm(in i){
  spts.clear();
  forv(j,mpts){
    if(j==i)base=mpts[j];
    else spts.PB(mpts[j]);
  }
  sort(all(spts));
  in bsf=0;
  in p2=0;
  in cp;
  in n=sz(mpts);
  forv(p1,spts){
    if(p1==p2){p2++;p2%=n-1;}
    while(p2!=p1 && tria(base,spts[p1],spts[p2])!=rig){
      p2++;p2%=n-1;
    }
    cp=(p2-p1+n-1)%(n-1);
    if(p2==p1)cp=n-1;
    bsf=max(bsf,cp);
  }
  return n-1-bsf;
}
void docase(){
  vp.resize(1);
  cout<<endl;
  in n;cin>>n;
  mpts.resize(n);
  forn(i,n){
    cin>>mpts[i].x>>mpts[i].y;
  }
  forn(i,n){
    cout<<mrm(i)<<endl;
  }
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
