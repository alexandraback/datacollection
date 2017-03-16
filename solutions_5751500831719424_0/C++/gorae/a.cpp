#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<char,int> ci;

int main(){
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int TT=1;TT<=T;TT++){

		int n,ans=0;
		scanf("%d",&n);
		string a,b;
		cin>>a>>b;

		int f=1,ia=0,ib=0,sa=a.length(),sb=b.length();
		vector<ci> v;
		v.push_back(ci(a[0],1));
		for(int i=1;i<sa;i++){
			if(a[i-1]!=a[i]) {
				v.push_back(ci(a[i],1));ia++;
			}else v[ia].second++;
		}
		vector<ci> vv;
		vv.push_back(ci(b[0],1));
		for(int i=1;i<sb;i++){
			if(b[i-1]!=b[i]) {
				vv.push_back(ci(b[i],1));ib++;
			}else vv[ib].second++;
		}

		int sv=v.size(),svv=vv.size();
		if(sv!=svv) f=0;
		if(f) for(int i=0;i<sv;i++){ 
			if(v[i].first!=vv[i].first) f=0;
			else ans+=(v[i].second>vv[i].second?v[i].second-vv[i].second:vv[i].second-v[i].second);
		}
		printf("Case #%d: ",TT);
		if(f) printf("%d\n",ans);
		else printf("Fegla Won\n");
	}
}
