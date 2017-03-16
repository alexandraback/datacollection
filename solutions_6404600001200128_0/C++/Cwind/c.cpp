//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<ctime>
#include<cctype>
#include<memory>
#include<cstdlib>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<climits>
#include<complex>
#include<utility>
#include<functional>
#define INF 0x7fffffff
#define FILL_NINF 0xef
#define FILL_INF 0x3f
#define RE cerr<<"REdebuge"<<endl;
#define M7 1000000007
#define M9 1000000009
#define ifor(s,n) for(int i=(s);i<(n);i++)
#define rep(rep_val) for(int REP_i=0;REP_i<(rep_val);REP_i++)
#define tmin(a,b,c) min((a),min((b),(c)))
#define tmax(a,b,c) max((a),max((b),(c)))
#define eps 1e-8
using namespace std;
typedef long long ll;
typedef pair<int, int> Poi;

const int maxv=1005;/////注意爆int问题！！~
int T,t=0;
int n;
int m[maxv];
int main(){
 freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
	cin>>T;
	while(T--){
		t++;
		cin>>n;
		for(int i=1;i<=n;i++) scanf("%d",&m[i]);
		int ans1=0;
		for(int i=2;i<=n;i++){
			if(m[i]<m[i-1]) ans1+=m[i-1]-m[i];
		}
		int maxs=0;
		for(int i=2;i<=n;i++){
			if(m[i]<m[i-1])
				maxs=max(maxs,m[i-1]-m[i]);
		}
		int ans2=0;
		for(int i=2;i<=n;i++){
			if(m[i-1]<maxs){
				ans2+=m[i-1];
			}
			else ans2+=maxs;
		}
		printf("Case #%d: %d %d\n",t,ans1,ans2);
	}
    return 0;
}