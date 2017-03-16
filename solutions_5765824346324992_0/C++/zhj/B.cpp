#include<bits/stdc++.h>
#define int64 long long
#define sqr(x) (x)*(x)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define VI vector<int>
#define VI64 vector<int64>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define SZ(x) ((int)(x).size())
using namespace std;
const double pi=acos(-1);
int T,n,m,b[12000],tim;
int64 calc(int64 mid){
	int64 res=0;
	rep(i,1,m)res+=mid/b[i]+1;
	return res;
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&m,&n);
		rep(i,1,m)scanf("%d",&b[i]);
		int64 L=0,R=1ll<<60,mid;
		while(L<=R){
			mid=(L+R)/2;
			if(calc(mid)>=n)R=mid-1;
			else L=mid+1;
		}
		if(R>=0)n-=calc(R);
		rep(i,1,m)if((R+1)%b[i]==0){
			n--;
			if(!n){
				printf("Case #%d: %d\n",++tim,i);
				break;
			}
		}
	}
}		
