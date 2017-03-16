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

		int n;
		scanf("%d",&n);
		vector<string> s;
		string a;
		for(int i=0;i<n;i++) {
			cin>>a;
			s.push_back(a);
		}

		int f=1,ia=0;
		vector<ci> v[111];
		for(int j=0;j<n;j++){
			v[j].push_back(ci(s[j][0],1));
			int sa=s[j].length(),ia=0;
			for(int i=1;i<sa;i++){
				if(s[j][i-1]!=s[j][i]) {
					v[j].push_back(ci(s[j][i],1));ia++;
				}else v[j][ia].second++;
			}
		}
			
		int sv=v[0].size();
		for(int j=1;f && j<n;j++){
			if(sv!=v[j].size()) f=0;
			for(int i=0;f && i<sv;i++){ 
				if(v[0][i].first!=v[j][i].first) f=0;
			}
		}
		int ret=0;
		for(int i=0;i<sv;i++){
			int ans=10000000;
			for(int jj=1;jj<=100;jj++){
				int now=0;
				for(int j=0;j<n;j++){
				now+=(jj>v[j][i].second?jj-v[j][i].second:v[j][i].second-jj);
				}
				if(ans>now) ans=now;
			}
			ret+=ans;	
		}
		printf("Case #%d: ",TT);
		if(f) printf("%d\n",ret);
		else printf("Fegla Won\n");
	
		}


}
