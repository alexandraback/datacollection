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

namespace _double_tmpl{
	typedef long double D;
	
	static constexpr D Ae=0;
	D A(D a,D b){return a+b;}D Ainv(D a){return -a;}
	D S(D a,D b){return A(a,Ainv(b));}
	
	static constexpr D Me=1;
	D M(D a,D b){return a*b;}D Minv(D a){return 1.0/a;};

	int sig(D a,D b=0){return a<b-EPS<D>()?-1:a>b+EPS<D>()?1:0;}
	template<typename T> bool eq(const T& a,const T& b){return sig(abs(a-b))==0;}

	D pfmod(D v,D MOD=2*M_PI){return fmod(fmod(v,MOD)+MOD,MOD);}
	
	//[0,PI)
	D AbsArg(D a){
		D ret=pfmod(max(a,-a),2*M_PI);return min(ret,2*M_PI-ret);
	}
}
using namespace _double_tmpl;

namespace _P{
	// using namespace _double_tmpl;
	typedef complex<D> P,Vec;
	const P O=P(0,0);
#define X real()
#define Y imag()
	istream& operator >> (istream& is,complex<D>& p){
    	D x,y;is >> x >> y;p=P(x,y);return is;
    }
	bool compX (const P& a,const P& b){return !eq(a.X,b.X)?sig(a.X,b.X)<0:sig(a.Y,b.Y)<0;}
	bool compY (const P& a,const P& b){return !eq(a.Y,b.Y)?sig(a.Y,b.Y)<0:sig(a.X,b.X)<0;}

	// a×b
	D cross(const Vec& a,const Vec& b){return imag(conj(a)*b);}
	// a・b
	D dot(const Vec&a,const Vec& b) {return real(conj(a)*b);}

	int ccw(const P& a,P b,P c){
		b -= a; c -= a;
		if (sig(cross(b,c))>0)   return +1;       // counter clockwise
		if (sig(cross(b,c))<0)   return -1;       // clockwise
		if (sig(dot(b,c)) < 0)     return +2;       // c--a--b on line
		if (sig(norm(b),norm(c))<0) return -2;       // a--b--c on line
		return 0;
	}

	// 最近点対
	// O(n logn)
	// verified by AOJLIB
	// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1093043
	D closestPair(vector<P>& ps,int l,int r){
        if(r-l<2)return INF<D>();
        D res=min(closestPair(ps,l,(l+r)/2),closestPair(ps,(l+r)/2,r));
        
        vector<P> ips;FOR(i,l,r)if(abs(ps[i].X - ps[(l+r)/2].X)<res)ips.push_back(ps[i]);
        sort(ALL(ips),compY);
        
        REP(i,ips.size())for(int j=i-10;j<i;j++)if(j>=0)
            res=min(res,abs(ips[i]-ips[j]));

        return res;
    }
	D closestPair(vector<P>& ps){return closestPair(ps,0,ps.size());}


	// verified by 
	// 事前にs-g
	// O-s → O-gの回転方向に関してソート．
	// (同角度の場合、距離が遠い方が前)
	P s,g;
	bool CompArg(const P& p1,const P&p2){
		if(abs(ccw(O,p1,p2))!=1)return abs(p1)>abs(p2);//sameline
		return ccw(O,p1,p2)==ccw(O,s,g);
	}

	//!!
	//角度ソート
	P dir;//基準方向
	bool Comp(const P& p1,const P&p2){
		if(sig(pfmod(arg(p1)-arg(dir)),pfmod(arg(p2)-arg(dir)))==0)return abs(p1)>abs(p2);
		return sig(pfmod(arg(p1)-arg(dir)),pfmod(arg(p2)-arg(dir)));
	}

}
using namespace _P;

namespace std{
	bool operator < (const P& a,const P& b){return _P::compX(a,b);}
  	bool operator == (const P& a,const P& b){return eq(a,b);}
};

namespace _poly{
	typedef vector<P> Poly,ConvexPoly;
	
	// verifed by AOJLIB
	// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092258
	enum { OUT, ON, IN };
	int contains(const Poly& ps, const P& p) {
	  	bool in = false;int n=ps.size();
	  	REP(i,n){
			P a = ps[i] - p, b = ps[pmod(i+1,n)] - p;
			if (a.Y > b.Y) swap(a, b);
			if (a.Y <= 0 && 0 < b.Y)
	 		if (cross(a, b) < 0) in = !in;
	    		if (cross(a, b) == 0 && dot(a, b) <= 0) return ON;
	  	}
		return in ? IN : OUT;
	}
	// 二倍面積
	// verifed by AOJLIB
    // http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092246
	D area2(const Poly& ps){
		D S=0;int n=ps.size();
		REP(i,n)S+=cross(ps[i],ps[pmod(i+1,n)]);
		return S;
	}
	// verifed by AOJLIB
	// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092256
    bool is_convex(const Poly& ps){
        int n=ps.size();
        REP(i,n)
            if(ccw(ps[pmod(i,n)],ps[pmod(i+1,n)],ps[pmod(i+2,n)])==-1)return false;

        return true;
    }
}
using namespace _poly;

namespace _convex_poly{
  	
    // 凸包
	//O(n logn)
	// verified by AOJLIB
    // http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092743
	ConvexPoly convex_hull(Poly ps) {
		int n = ps.size(), k = 0;
		sort(ALL(ps));
		Poly ch(2*n);
		REP(i,n){ // lower-hull
			while (k > 1 && cross(ch[k-1]-ch[k-2],ps[i]-ch[k-1]) < 0) --k;
			ch[k++]=ps[i];
		}
		for(int i=n-2,t=k;i>=0;i--){// upper-hull
			while (k > t && cross(ch[k-1]-ch[k-2],ps[i]-ch[k-1]) < 0) --k;
			ch[k++]=ps[i];
		}
		ch.resize(k-1);
		return ch;
	}

	// 凸多角形の直径    
    // O(n)
    // verified by AOJLIB
    // http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092749
    D convex_diameter(const ConvexPoly &ps) {
        const int n = ps.size();
        int is=0;REP(i,n)if(ps[i].Y > ps[is].Y) is = i;
        int js=0;REP(j,n)if(ps[j].Y < ps[js].Y) js = j;
        D maxd = abs(ps[is] - ps[js]);
        
        int i = is, maxi = is, j =js, maxj=js;
        do {
            if(cross(ps[pmod(i+1,n)]-ps[i],ps[pmod(j+1,n)]-ps[j]) >= 0) j = pmod(j+1,n);
            else i = pmod(i+1,n);
            if(abs(ps[i]-ps[j]) > maxd) maxd = abs(ps[i]-ps[j]);maxi = i; maxj = j;
        } while (i != is || j != js);
        return maxd;
        // farthest pair is (maxi, maxj).
    }

	// 凸多角形を反時計周りでソート
    // O(nlogn)
    // verified by AOJLIB
    // http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=1092743
    void ccw_sort(ConvexPoly &ps){
        const int n=ps.size();
		sort(ALL(ps));
        const P& O = ps[0];
        sort(ps.begin()+1,ps.end(),[&O](const P& l,const P& r) -> bool{return cross(l-O,r-O) > 0;});
        int sr=1;while(sr < n && cross(ps[sr]-O,ps[1]-O)==0)sr++;
        sort(ps.begin()+1,ps.begin()+sr,[&O](const P& l,const P& r) -> bool{return abs(l-O)<abs(r-O);});
        int el=n-1;while(el-1 >=1 && cross(ps[el-1]-O,ps[n-1]-O)==0)el--;
        sort(ps.begin()+el,ps.end(),[&O](const P& l,const P& r) -> bool{return abs(l-O)>abs(r-O);});
    }
}
using namespace _convex_poly;

class Main{
	public:
	void run(){
		int T;cin >> T;

		for(int q:range(T)){
			int N;cin >> N;
			vector<P> ps(N);
			for(int i:range(N)){
				int x,y;cin >> x >> y;
				ps[i]=P(x,y);
			}

			vector<int> res(N,INF<int>());
			for(int i:range(N)){
				vector<long double> args;
				for(int j:range(N))if(j!=i){
					args.push_back(pfmod(arg(ps[j]-ps[i]),2*M_PI));
				}
				sort(ALL(args));
				for(int j:range(args.size()))args.push_back(args[j]+2*M_PI);

				ll Mv = 0;
				for(int l:range(args.size())){
					int r = upper_bound(ALL(args),args[l]+M_PI+EPS<long double>())-args.begin() - 1;
					Mv= max<ll>(Mv,r-l+1);
				}
				res[i]=N-Mv-1;
			}

			cout << make_tuple("Case","#"+to_string(q+1)+":")<<endl;
			for(int i:range(N)){
				cout << res[i] <<endl;
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