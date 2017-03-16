#define DEB

#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

//const int INF=5e8;
#include<complex>
typedef complex<lint> P;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}
lint cross(const P& a, const P& b) {
  return imag(conj(a)*b);
}
lint dot(const P& a, const P& b) {
  return real(conj(a)*b);
}
int sign(lint a){
	if(a==0) return a;
	return a/abs(a);
}

int ccw(P a, P b, P c) {
  b -= a; c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  return 0;								  
}

int n;

bool isUP(const P& a){
	if(a.imag()>0 || (a.imag()==0 && a.real()>0)) return true;
	return false;
}


bool cmp(P A,P B){
	if(isUP(A)==isUP(B)){
		return (ccw(A,P(0,0),B)==1?1:0);
	}else if(isUP(A)) return true;
	return false;
}
bool cmp2(const pair<P,int>& a,const pair<P,int>& b){
  if(a.fr!=b.fr) return cmp(a.fr,b.fr);
  return a.sc<b.sc;
}

P ps[3005];

pair<P,int> event[6005];
int main(){
  int t;cin>>t;
  REP(setn,t){
    cin>>n;
    REP(i,n){
      int x,y;cin>>x>>y;
      ps[i].real(x);
      ps[i].imag(y);
    }

    printf("Case #%d:\n",setn+1);
    REP(i,n){
      int m=0;
      REP(j,n) if(i!=j){
        int x=(ps[j]-ps[i]).real(),y=(ps[j]-ps[i]).imag();
        int g=__gcd(abs(x),abs(y));
        x/=g;y/=g;

        event[m++]=mp(P(x,y),-1);
        event[m++]=mp(P(-x,-y),1);

      }
      sort(event,event+m,cmp2);

      int cnt=0;
      REP(j,n) if(isUP(ps[j]-ps[i]) && i!=j){
        ++cnt;
      }
      int res=cnt;
      REP(j,m){
        cnt+=event[j].sc;
        chmin(res,cnt);
      }
      assert(res<=(n-2)/2);
      printf("%d\n",res);
    }
  }
  return 0;

}



