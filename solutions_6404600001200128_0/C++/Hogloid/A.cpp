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

int n;
int ar[1005];
int main(){
  int t;cin>>t;
  REP(setn,t){

    cin>>n;
    REP(i,n) cin>>ar[i];

    int res1=0,res2=0;
    int difmax=0;
    REP(i,n-1){
      res1+=max(0,ar[i]-ar[i+1]);
      chmax(difmax,max(0,ar[i]-ar[i+1]));
    }

    REP(i,n-1){
      res2+=min(difmax,ar[i]);
    }
    printf("Case #%d: %d %d\n",setn+1,res1,res2);
  }
  return 0;

}



