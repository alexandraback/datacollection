#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)

template<typename T>
class heap : public priority_queue<T,vector<T>,greater<T> > {};

int main(void) {
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt) {
		int n;
		scanf("%d",&n);
		set<pair<int,char> > x;
		int cc[26];
		int total = 0;
		FOR(i,n) {
			int c;
			scanf("%d",&c);
			x.insert({c,'A'+i});
			cc[i]=c;
			total+=c;
		}
		
		string ans = "";
		while(!x.empty()) {
			auto last = x.rbegin();
			int count = (*last).first-1;
			char p = (*last).second;
			
			--cc[p-'A'];
			
			ans+=string(1,p);
			--total;
			x.erase({count+1,p});
			if(count) x.insert({count,p});
			
			last = x.rbegin();
			p = (*last).second;
			
			// max ma vacsinu
			if(total-cc[p-'A'] < cc[p-'A']) {
				ans+=string(1,p);
				ans+=" ";
				x.erase({cc[p-'A'],p});
				--cc[p-'A'];
				if(cc[p-'A']) x.insert({cc[p-'A'],p});
				--total;
			}
			else ans+=" ";
			
			
			
			
			
			
		}
		
		
		
		printf("Case #%d: ",tt);
		
		int len = ans.size();
		if(ans[len-1]==' ') --len;
		FOR(i,len) printf("%c",ans[i]);
		printf("\n");
		
		
	}
	
	
	
	
	
	
	
	
	
}