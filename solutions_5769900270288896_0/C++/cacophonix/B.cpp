#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define inf 1061109567
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define mem(x,a) memset(x,a,sizeof(x))
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define repi(i,a,b) for(int i(a),_b(b);i<=_b;++i)
#define repr(i,a,b) for(int i(a),_b(b);i>=_b;--i)
#define repe(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define len(x) ((int)(x.size()))
#define DEBUG 1 
#if DEBUG && !ONLINE_JUDGE 
	#define debug(args...) (Debugger()) , args
	class Debugger { public: Debugger(const std::string& _separator = ", ") : first(true), separator(_separator){} template<typename ObjectType> Debugger& operator , (const ObjectType& v) { if(!first) std::cerr << separator; std::cerr << v; first = false; return *this; } ~Debugger() { std::cerr << endl;} private: bool first; std::string separator; }; template <typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) { return os << "(" << p.first << ", " << p.second << ")"; } template<typename T> inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v) { bool first = true; os << "["; for(unsigned int i = 0; i < v.size(); i++) { if(!first) os << ", "; os << v[i]; first = false; } return os << "]"; } template<typename T> inline std::ostream &operator << (std::ostream & os,const std::set<T>& v) { bool first = true; os << "["; for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) { if(!first) os << ", "; os << *ii; first = false; } return os << "]"; } template<typename T1, typename T2> inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v) { bool first = true; os << "["; for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii) { if(!first) os << ", "; os << *ii ; first = false; } return os << "]"; } 
#else 
		#define debug(args...) 
#endif


#define chk(a,k) ((bool)(a&(1LL<<(k))))
#define off(a,k) (a&(~(1LL<<(k))))
#define on(a,k) (a|(1LL<<(k)))
inline int clz(int x){return __builtin_clz(x);}
inline int clz(ll x){return __builtin_clzll(x);}
inline int ctz(int x){return __builtin_ctz(x);}
inline int ctz(ll x){return __builtin_ctzll(x);}
inline int lg2(int x){return !x ? -1 : 31 - clz(x);}
inline int lg2(ll x){return !x ? -1 : 63 - clz(x);}
inline int low_idx(int x){return !x ? -1 : ctz(x);}
inline int low_idx(ll x){return !x ? -1 : ctz(x);}
inline int high_idx(int x){return lg2(x);}
inline int high_idx(ll x){return lg2(x);}
inline int count_bits(int x){if(!x) return 0;return __builtin_popcount(x);}
inline int count_bits(ll x){if(!x)return 0;return __builtin_popcountll(x);}



int r,c,n;

int dp[22][1<<18];

int fun(int pos,int mask){
	
	//~ debug(pos,mask);
	
	if(pos==r*c){
		
		if(count_bits(mask)==n)return 0;
		else return inf;
		
	}
	
	int &ret=dp[pos][mask];
	if(ret!=-1)return ret;
	
	
	ret=fun(pos+1,mask);
	int last=17,up=17;
	
	//first row
	if(pos<c){
		
		if(pos)last=pos-1;
		ret=min(ret,fun(pos+1,on(mask,pos))+chk(mask,last));
		
	}
	else {
		
		if(pos%c)last=pos-1;
		up=pos-c;
		ret=min(ret,fun(pos+1,on(mask,pos))+chk(mask,last)+chk(mask,up));
	}
	
	//~ debug(pos,mask,ret);
	
	return ret;
	
}



int main(){
	ios_base::sync_with_stdio(0);
	
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	
	
	int tests;
	cin>>tests;
	for(int t=1;t<=tests;t++){
		cout<<"Case #"<<t<<": ";
		cin>>r>>c>>n;
		mem(dp,-1);
		cout<<fun(0,0)<<endl;
		
	}
	
	
	
}








