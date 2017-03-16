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


int n,m;
int cost[1005];

lint getseat(lint md){
  if(md==-1) return 0;
  lint seat=0;
  REP(i,n) seat+=md/cost[i]+1;
  return seat;
}

int main(){
  int t;cin>>t;
  REP(setn,t){
    cin>>n>>m;
    REP(i,n) cin>>cost[i];


    lint lb=-1,ub=1e15;
    while(ub-lb>1){
      lint md=(lb+ub)>>1;

      if(getseat(md)>=m) ub=md;
      else lb=md;
    }

    int rank=m-getseat(ub-1);

    int res=-1;
    REP(i,n) if(ub%cost[i]==0){
      if(rank==1){
        res=i;
        break;
      }
      --rank;
    }
    assert(res!=-1);

    printf("Case #%d: %d\n",setn+1,res+1);
  }
  return 0;

}



