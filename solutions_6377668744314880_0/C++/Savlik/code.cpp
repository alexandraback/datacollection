#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>
#include <cstring>
#include <string>
#include <complex>

#define vi vector<int>
#define vpii vector< pair<int,int> >
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define FOREACH(it,x) for (auto it = (x).begin(); it!=(x).end(); ++it) 
#define sz(x) (int)(x).size()
#define FOR(i,n) for (ll i = 0; i < ll(n); i++)
#define REP(i,a,b) for (ll i = a; i < ll(b); i++)
#define READ(a) int a; scanf("%d", &a);
#define READV(v,n) vi v(n);FOR(i,n){scanf("%d", &v[i]);}
#define WRITE(v) "";FOR(i,sz(v))cout<<v[i]<<" ";cout
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ff first
#define ss second
#define X first
#define Y second
#define oo 2140000000ll

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const double PI = std::atan(1.0)*4;

vector<complex<double> > trees;
int n;

int main(){
	READ(T);
	FOR(t,T){
		cin>>n;
		trees.clear();
		FOR(i,n){
			double x, y;
			cin>>x>>y;
			trees.pb(complex<double>(x,y));
		}
		if(n==1){
			cout<<"Case #"<<(t+1)<<": "<<endl<< 0 <<endl;
			goto next;
		}

		cout<<"Case #"<<(t+1)<<": "<<endl;
		FOR(i,n){
			complex<double> akt = trees[i];
			int best = oo;
			FOR(j,n){
				if(i==j) continue;
				complex<double> akt2 = trees[j];
				int c1 = 0;
				int c2 = 0;
				FOR(k,n){
					if(k==i || k==j) continue;
					complex<double> akt3 = trees[k];
					complex<double> l1 = akt-akt2;
					complex<double> l2 = akt3-akt2;
					complex<double> x = l1/l2;
					double arg = std::arg(x);
					
					if(arg>0 && arg<PI) c1++;
					if(arg<0 && arg>-PI) c2++;
				}
				//cerr<<i<<" "<<j<<" "<<c1<<","<<c2<<endl;
				gmin(best, min(c1,c2));
			}
			cout<<best<<endl;
		}

		next:
		continue;

//		cout<<"Case #"<<(t+1)<<": "<< sum<<" "<<sum2 <<endl;
	}

	return 0;
}