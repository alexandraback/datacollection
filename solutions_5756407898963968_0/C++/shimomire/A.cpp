#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
using namespace std;


//common
using i32=int;using i64=long long;using ll =i64;
using uint=unsigned int;using ull=unsigned long long;
template<typename T> using matrix=vector<vector<T> >;

#define BR "\n"
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,l,r) for(int i=(int)l;i<(int)(r);++i)
#define EACH(it,o) for(auto it = (o).begin(); it != (o).end(); ++it)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))

//config
//#define NDEBUG

//debug
#ifdef NDEBUG
#define DUMP(x)
#define DUMPLN(x)
#define DEBUG(x)
#define DEBUGLN(x)
#define LINE()
#define LINELN()
#define CHECK(exp,act)
#define STOP(e)
#else
#define DUMP(x)  cerr << #x << " = " << (x)
#define DUMPLN(x)  DUMP(x) <<endl
#define DEBUG(x) DUMP(x) << LINE() << " " << __FILE__
#define DEBUGLN(x) DEBUG(x)<<endl
#define LINE()    cerr<< " (L" << __LINE__ << ")"
#define LINELN()    LINE()<<endl
#define CHECK(exp,act)  if(exp!=act){DUMPLN(exp);DEBUGLN(act);}
#define STOP(e)  CHECK(e,true);if(!(e)) exit(1);
#endif

template<class T> inline string toString(const vector<T>& x) {
	stringstream ss;
	REP(i,x.size()){
		if(i!=0)ss<<" ";
		ss<< x[i];
	}
	return ss.str();
}

template<class T> inline string toString(const vector<vector<T> >& map) {
	stringstream ss;
	REP(i,map.size()){
		if(i!=0)ss<<BR;
		ss<< toString(map[i]);
	}
	return ss.str();
}
template<class K,class V>  string toString(map<K,V>& x) {
	string res;stringstream ss;
	for(auto& p:x)ss<< p.first<<":" << p.second<<" ";
	return ss.str();
}

string BITtoString(int bit){
    stringstream ss;
    while(bit!=0){ss<<(bit%2);bit/=2;}
    string res=ss.str();reverse(ALL(res));
    return res;
}

template<typename T,typename V> inline T pmod(T v,V MOD){
	return (v%MOD+MOD)%MOD;
}
#define nextInt(n) scanf("%d",&n)
#define nextLong(n) scanf("%I64d",&n)
#define nextDouble(n) scanf("%lf",&n)


//#define INF 1<<30
//#define EPS 1e-8
//const ll MOD =100000007;

class Main{
public:
	void run(){
		ifstream cin("in");
		ofstream cout( "out" );

		int T;cin >> T;
		for(int tc=1;tc<=T;tc++){
			int fba;cin >> fba;fba--;
			vector<vector<int> > fb(4,vector<int>(4));
			REP(y,4)REP(x,4) cin>> fb[y][x];
			set<int> fs;REP(x,4)fs.insert(fb[fba][x]);

			int sba;cin >> sba;sba--;
			vector<vector<int> > sb(4,vector<int>(4));
			REP(y,4)REP(x,4) cin>> sb[y][x];
			set<int> ss;REP(x,4)ss.insert(sb[sba][x]);

			set<int> res;
			int rv=-1;
			for(int i=1;i<=16;i++)if(fs.count(i)>0 && ss.count(i)>0){
				res.insert(i);DUMP(i);
				rv=i;				
			}
			if(res.size()==1){
				cout <<"Case #"<<tc<<": "<<rv<<endl;
			}else if(res.size()==0){
				cout <<"Case #"<<tc<<": "<<"Volunteer cheated!"<<endl;			
			} else{
				cout <<"Case #"<<tc<<": "<<"Bad magician!"<<endl;						
			}
		}

	}
};
 int main(){
	 cout <<fixed<<setprecision(15);
	ios::sync_with_stdio(false);
 	Main().run();
 	return 0;
 }