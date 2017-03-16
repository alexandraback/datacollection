#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint a[1919];
int main()
{
	int t,n;lint m;
	cin>>t;
	rep(i,t){
		cin>>n>>m;
		rep(j,n) cin>>a[j];
		lint lo=0,hi=1145141919810893LL;
		while(hi>lo){
			lint mi=(hi+lo)/2,sum=0;
			rep(j,n) sum+=1+mi/a[j];
			if(sum<m) lo=mi+1;else hi=mi;
		}
		lint s2=0;vector<int> b;
		rep(j,n){
			s2+=(lo+a[j]-1)/a[j];
			if(lo%a[j]==0) b.pb(j);
		}
		printf("Case #%d: %d\n",i+1,b[(int)(m-s2-1)]+1);
	}
}
