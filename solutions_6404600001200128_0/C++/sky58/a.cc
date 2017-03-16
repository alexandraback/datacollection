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
int a[1919];
int main()
{
	int n,t;
	cin>>t;
	rep(i,t){
		cin>>n;rep(j,n) cin>>a[j];
		int ret=0,re2=0,ma=0;
		rep(j,n-1){
			ret+=max(0,a[j]-a[j+1]);
			ma=max(ma,a[j]-a[j+1]);
		}
		rep(j,n-1){
			re2+=min(ma,a[j]);
		}
		printf("Case #%d: %d %d\n",i+1,ret,re2);
	}
}
