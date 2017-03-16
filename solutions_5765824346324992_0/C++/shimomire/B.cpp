#include <cassert>// c
#include <iostream>// io
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>// container
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <algorithm>// other
#include <complex>
#include <numeric>
#include <functional>
#include <random>
#include <regex>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define ALL(c) (begin(c)),(end(c))
#define REP(i,n) FOR(i,0,n)
#define REPr(i,n) FORr(i,0,n)
#define FOR(i,l,r) for(int i=(int)(l);i<(int)(r);++i)
#define FORr(i,l,r) for(int i=(int)(r)-1;i>=(int)(l);--i)
#define EACH(it,o) for(auto it = (o).begin(); it != (o).end(); ++it)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end())
//debug
#define DUMP(x)  cerr << #x << " = " << (x)
#define LINE()    cerr<< " (L" << __LINE__ << ")"

class range {
private:
	struct Iter{
		int v;
		int operator*(){return v;}
		bool operator!=(Iter& itr) {return v < itr.v;}
		void operator++() {++v;}
	};
	Iter i, n;
public:
	range(int n) : i({0}), n({n}) {}
	range(int i, int n) : i({i}), n({n}) {}
	Iter& begin() {return i;}
	Iter& end() {return n;}
};

//input
template<typename T1,typename T2> istream& operator >> (istream& is,pair<T1,T2>& p){is>>p.first>>p.second;return is;}
template<typename T1> istream& operator >> (istream& is,tuple<T1>& t){is >> get<0>(t);return is;}
template<typename T1,typename T2> istream& operator >> (istream& is,tuple<T1,T2>& t){is >> get<0>(t) >> get<1>(t);return is;}
template<typename T1,typename T2,typename T3> istream& operator >> (istream& is,tuple<T1,T2,T3>& t){is >>get<0>(t)>>get<1>(t)>>get<2>(t);return is;}
template<typename T1,typename T2,typename T3,typename T4> istream& operator >> (istream& is,tuple<T1,T2,T3,T4>& t){is >> get<0>(t)>>get<1>(t)>>get<2>(t)>>get<3>(t);return is;}
template<typename T1,typename T2,typename T3,typename T4,typename T5> istream& operator >> (istream& is, const tuple<T1,T2,T3,T4,T5>& t){is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t);return is;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6> istream& operator >> (istream& is, const tuple<T1,T2,T3,T4,T5,T6>& t){is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t) >> get<5>(t);return is;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7> istream& operator >> (istream& is, const tuple<T1,T2,T3,T4,T5,T6,T7>& t){is >> get<0>(t) >> get<1>(t) >> get<2>(t) >> get<3>(t) >> get<4>(t) >> get<5>(t) >> get<6>(t);return is;}
template<typename T> istream& operator >> (istream& is,vector<T>& as){REP(i,as.size())is >>as[i];return is;}

//output
template<typename T> ostream& operator << (ostream& os, const set<T>& ss){for(auto a:ss){if(a!=ss.begin())os<<" "; os<<a;}return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const pair<T1,T2>& p){os<<p.first<<" "<<p.second;return os;}
template<typename K,typename V> ostream& operator << (ostream& os, const map<K,V>& m){bool isF=true;for(auto& p:m){if(!isF)os<<endl;os<<p;isF=false;}return os;}
template<typename T1> ostream& operator << (ostream& os, const tuple<T1>& t){os << get<0>(t);return os;}
template<typename T1,typename T2> ostream& operator << (ostream& os, const tuple<T1,T2>& t){os << get<0>(t)<<" "<<get<1>(t);return os;}
template<typename T1,typename T2,typename T3> ostream& operator << (ostream& os, const tuple<T1,T2,T3>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t)<<" "<<get<5>(t);return os;}
template<typename T1,typename T2,typename T3,typename T4,typename T5,typename T6,typename T7> ostream& operator << (ostream& os, const tuple<T1,T2,T3,T4,T5,T6,T7>& t){os << get<0>(t)<<" "<<get<1>(t)<<" "<<get<2>(t)<<" "<<get<3>(t)<<" "<<get<4>(t)<<" "<<get<5>(t)<<" "<<get<6>(t);return os;}
template<typename T> ostream& operator << (ostream& os, const vector<T>& as){REP(i,as.size()){if(i!=0)os<<" "; os<<as[i];}return os;}
template<typename T> ostream& operator << (ostream& os, const vector<vector<T>>& as){REP(i,as.size()){if(i!=0)os<<endl; os<<as[i];}return os;}

// values
template<typename T> T INF(){assert(false);};
template<> int INF<int>(){return 1<<28;};
template<> ll INF<ll>(){return 1LL<<58;};
template<> double INF<double>(){return 1e16;};
template<> long double INF<long double>(){return 1e16;};

template<class T> T EPS(){assert(false);};
template<> int EPS<int>(){return 1;};
template<> ll EPS<ll>(){return 1LL;};
template<> double EPS<double>(){return 1e-8;};
template<> long double EPS<long double>(){return 1e-8;};

template<typename T,typename U> T pmod(T v,U M){return (v%M+M)%M;}

class Main{
	public:
	void run(){
		int T;cin >> T;
		for(int q:range(T)){
			int B;cin >> B;
			int N;cin >> N;
			vector<int> ms(B);cin >> ms;

			if(N<=B){
				cout << make_tuple("Case","#"+to_string(q+1)+":",N)<<endl;
				continue;
			}

			ll l =0,r= 1LL<<50;
			while(r-l>1){
				ll m = (l+r)/2;

				ll c=0;
				for(int i:range(B))c += 1 + m/ms[i];

				if(c<N)l=m;
				else r=m;
			}
			ll t=l;

			// check
			ll c=0;
			for(int i:range(B))c += 1 +t/ms[i];

			// cerr << t <<endl;
			// cerr << c <<endl;

			priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que;
			for(int i:range(B)){
				// cerr << make_tuple(ms[i] * (t/ms[i]) + ms[i],i)<<endl;
				que.push({ms[i] * (t/ms[i]) + ms[i],i});
			}
			while(true){
				pair<ll,int> p=que.top();que.pop();
				c++;
				// cerr << make_tuple(c,p.first,p.second)<<endl;
				if(c== N){
					cout << make_tuple("Case","#"+to_string(q+1)+":",p.second+1)<<endl;
					break;
				}
				que.push({p.first+ms[p.second],p.second});
			}
		}

	}
};

int main(){
	cout <<fixed<<setprecision(20);
	cin.tie(0);
	ios::sync_with_stdio(false);
	Main().run();
	return 0;
}