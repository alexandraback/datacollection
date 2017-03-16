#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<iostream>
#include<numeric>
#include<complex>
#include<sstream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<list>
#include<set>
#include<map>
using namespace std;

//===============================SHORTENINGS====================================
typedef long long int64;
typedef pair<int,int> PII;
#define X first
#define Y second
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
//#define VAR(a,b) __typeof(b) a=(b)
#define VAR(a,b) auto a=(b)
template<typename T> T inline sqr(T q){return q*q;}
#define sz(X) ((int)(X).size())
#define pb push_back
#define ALL(c) (c).begin(),(c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) (c).resize(unique(ALL(c))-(c).begin())
//===============================CONSTANTS======================================
const int INF=1000000001;
const int64 INF64=sqr((int64)INF);
const double EPS=1E-7;
//=================================LOOPS========================================
#define FOR(I,S,N) for(int I=(S);I<(N);I++)
#define REP(I,N) FOR(I,0,N)
#define FORD(I,S,N) for(int I=(S);I>=(N);I--)
#define FORV(i,v) FOR(i,0,sz(v))
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
//===============================STRINGS========================================
typedef stringstream SS;
template<typename T> string tos(T q,int w=0)
{ SS A;A.precision(w);A<<fixed<<q; return A.str();}
template<typename T> T sto(string s){SS A(s);T t;A>>t;return t;}
template<typename T> vector<T> s2v(string s,string d=" "){
    FORV(i,s)FORV(j,d)if(s[i]==d[j])s[i]=' ';
    int n=sz(s);while(n&&s[n-1]==' ')n--;
    s.resize(n);SS A(s);vector<T> ans;
    for(T t;A>>t;)ans.pb(t);
    return ans;
}
//================================DEBUG=========================================
template<typename T1,typename T2>ostream &operator<<(ostream &out,const 
pair<T1,T2> &t ){out << "( " <<  t.X << " , " << t.Y << " )";return out;}
template<typename T>ostream &operator<<(ostream &out,const vector<T> &t){
out<<"{ ";FORV(i,t){if(i)out<<", ";out<<t[i];}out<<" }";return out;}
#define PR(X) cout<<#X<<" = "<<(X)<<" "
#define PRL cout<<endl
//================================TIME==========================================
double Clock() {
	unsigned long long time;
#ifdef _MSC_VER
	time = __rdtsc();
#else
    __asm__ volatile ("rdtsc" : "=A" (time));
#endif
    return time / 2.5e9; 
}
//================================MAIN==========================================

struct Solver{
	VI m;
	int N;

	int y;

	Solver(){
	}

	void read(){
		int B;
		cin >> B >> N;
		m = VI(B);
		FORV(i, m)
			cin >> m[i];
	}

	int64 cnt(int64 t){
		int64 c = 0;
		
		FORV(i, m)
			c += t / m[i] + 1;

		return c;
	}

	int empty(int64 t){
		int64 c = cnt(t);
		if( c >= N )
			throw exception("SHIT");
		
		int h = N - (int)c;

		FORV(i, m){
			if( (t+1) % m[i] == 0 ){
				h--;
				if( h == 0 )
					return i;
			}
		}

		return -1;
	}

	void work(){
		if( N <=  sz(m) ){
			y = N;
			return;
		}

		int64 L = 0;
		int64 R = INF64;
		
		while( L + 1 < R ){
			int64 x = (L+R) / 2;
			int64 c = cnt(x);
			if( c >= N )
				R = x;
			else
				L = x;
		}

		y = empty(L) + 1;
	}

	void write(){
		cout << y << endl;
	}
};

int main(){
//freopen("input.txt" ,"r",stdin );
freopen("B-small-attempt0.in" ,"r",stdin );
//freopen("B-large.in" ,"r",stdin );
freopen("output.txt","w",stdout);
    int T;
    cin>>T;

	vector<Solver> solvers(T);
    
	REP(tc, T)
		solvers[tc].read();

//#pragma omp parallel for schedule(dynamic,1)
	REP(tc, T)
		solvers[tc].work();

    REP(tc, T){
        cout<<"Case #"<<tc+1<<": ";
		solvers[tc].write();
    }

    return 0;
}
