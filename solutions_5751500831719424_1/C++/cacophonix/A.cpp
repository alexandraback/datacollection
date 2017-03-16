#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <complex>
#include <numeric>
#include <valarray>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define inf 1061109567LL
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define mem(x,a) memset(x,a,sizeof(x))
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define repi(i,a,b) for(int i(a),_b(b);i<_b;++i)
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




vector<pair<char,int> > v [111];

int n,t1,t2,t3;

char c1;


string s1,s2,s;


int mx[111];






int main(){
	ios_base::sync_with_stdio(0);
	
	freopen("in", "r", stdin);

	freopen("out", "w", stdout);
	
	
	
	
	int tests;
	cin>>tests;
	for(int t=1;t<=tests;t++){
		cout<<"Case #"<<t<<": ";
		cin>>n;
		
		char last= '%';
		t1=0;
		
		mem(mx,0);
		
		rep(i,111)v[i].clear();
		
		rep(i,n){
			cin>>s;
			last='$';
			t1=0;
			rep(j,len(s)){
				
				if(s[j]!=last&&t1){
					v[i].pb(mp(last,t1));
					last=s[j];
					t1=1;
					//~ cout<<"hic"<<endl;
				}
				else if(s[j]==last){
					t1++;
				}
				else {
					last=s[j];
					t1=1;
				}
			}
			if(t1){
				v[i].pb(mp(last,t1));
				//~ cout<<"hic"<<endl;
			}
		}
		
		//~ rep(i,n)debug(v[i]);
		
		
		rep(i,n){
			if(len(v[i])!=len(v[0])){
				cout<<"Fegla Won"<<endl;
				goto lll;
			}
			else {
				rep(j,len(v[0])){
					if(v[i][j].first!=v[0][j].first){
						cout<<"Fegla Won"<<endl;
						goto lll;
					}
				}
			}
		}
		
		rep(i,n){
			rep(j,len(v[0])){
				mx[j]=max(mx[j],v[i][j].second);
			}
		}
		
		
		
		t1=inf;
		
		repi(cnt,1,111)
		
		rep(i,n){
			t2=0;
			rep(j,n){
				rep(k,len(v[0]))
				
				t2+=abs(cnt-v[j][k].second);
			}
			t1=min(t2,t1);
		}
		
		t1=0;
		
		rep(k,len(v[0])){
			
			t3=inf;
			
			repi(cnt,1,111){
				
				t2=0;
				
				rep(i,n){
					
					t2+=abs(cnt-v[i][k].second);
					
				}
				
				
				
				t3=min(t2,t3);
				
			}
			
			//~ debug(k,t3);
			
			t1+=t3;
			
		}
		
		cout<<t1<<endl;
		lll:;
	}
	
	
	
}








