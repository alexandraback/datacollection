#define NDEBUG
#include<bits/stdc++.h>
using namespace std;

#define SZ(X) ((int)X.size())
#define CLR(X) memset(X,0,sizeof(X))
#define MAX(A,B) ({__typeof__(A)_x=(A);__typeof__(B)_y=(B);_x>_y?_x:_y;})
#define MIN(A,B) ({__typeof__(A)_x=(A);__typeof__(B)_y=(B);_x<_y?_x:_y;})
#define MOD(A,B) (((A)%(B)+(B))%(B))
#define MP make_pair
#define FI first
#define SE second
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define RFOREACH(I,C) for(VAR(I,(C).rbegin());I!=(C).rend();I++)
#define ALL(X) (X).begin(),(X).end()
#define SRT(X) sort((X).begin(),(X).end())
#define PB push_back

template<class T> inline void wypisz(const T& x){FOREACH(I,x)cout<<*I<<" ";cout<<endl;}
template<class T> inline string stringify(T x,int p=9){ostringstream o;o.precision(p);o<<x;o.flush();return o.str();}

typedef vector<string> VS;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef set<PII> SETII;

inline VS parse(string s,char ch=' '){string a;VS wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(a);a="";} if(!a.empty()) wyn.PB(a);return wyn;}
inline VI parsei(string s,char ch=' '){string a="";VI wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(atoi(a.c_str()));a="";} if(!a.empty()) wyn.PB(atoi(a.c_str()));return wyn;}

int tmp[26];
int sum;
int N;

inline bool test(int x){
  tmp[x]--;
  bool ok=true;
  sum--;
  REP(i,N){
    if((double)(tmp[i])/sum>0.5) {
      ok=false;
      break;
    }
  }
  sum++;
  tmp[x]++;
  return ok;
}

int main(){
  ios_base::sync_with_stdio(0);
  int T;
  cin>>T;
  FOR(tt,1,T){
    cin>>N;
    REP(i,26) tmp[i]=0;
    REP(i,N) cin>>tmp[i];
    string ret="";
    while(1){
      SETII s;
      s.clear();
      sum=0;
      REP(i,N) {
        sum+=tmp[i];
        if(tmp[i]>0) s.insert(MP(tmp[i],i));
      }
      if(SZ(s)==0) break;
      bool ok=false;
      FOREACH(I,s){
        if(test(I->SE)){
          ok=true;
          ret+=string(1,'A'+I->SE)+" ";
          tmp[I->SE]--;
          sum--;
        }
      }
      if(!ok){
        PII x=*(s.begin());
        auto ys=s.begin();
        ys++;
        PII y=*(ys);
        ret+=string(1,'A'+x.SE)+string(1,'A'+y.SE)+" ";
        tmp[x.SE]--;
        tmp[y.SE]--;
        sum--;
      }
    }
    cout<<"Case #"<<stringify(tt)<<": "<<ret<<"\n";
  }

  return 0;
}
