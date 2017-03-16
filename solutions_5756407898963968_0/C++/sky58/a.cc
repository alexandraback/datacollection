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
int ma[5][5];
int main()
{
	int t,a,fi,se;
	cin>>t;
	rep(i,t){
		cin>>a;a--;fi=0;se=0;
		rep(j,4) rep(k,4) cin>>ma[j][k];
		rep(k,4) fi+=(1<<ma[a][k]);
		cin>>a;a--;
		rep(j,4) rep(k,4) cin>>ma[j][k];
		rep(k,4) se+=(1<<ma[a][k]);
		fi&=se;
		cout<<"Case #"<<i+1<<": ";
		if(fi<1) cout<<"Volunteer cheated!"<<endl;
		else if(__builtin_popcount(fi)>1) cout<<"Bad magician!"<<endl;
		else{
			rep(j,17){
				if(fi==(1<<j)) cout<<j<<endl;
			}
		}
	}
}
