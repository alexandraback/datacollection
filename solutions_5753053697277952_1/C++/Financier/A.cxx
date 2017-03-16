# include <bits/stdc++.h>
using namespace std;

int main()
{		
	int T; cin >> T;
	for(int T_=1; T_<=T; ++T_) {
		int n; cin >> n;
		vector<int> p(n, 0);
		for(int i=0; i<n; ++i) {
			scanf("%d", &p[i]);
		}
		
		int par = 0;
		for(int t:p) par += t;
		
		auto srt = [&](int a, int b) {
			return (p[a] < p[b]);	
		};
		
		priority_queue<int, vector<int>, decltype(srt)> que(srt);
		for(int i=0; i<n; ++i) que.push(i);
		
		
		printf("Case #%d:", T_);
		if (par & 1) {
			int t = que.top(); que.pop();
			printf(" %c", 'A' + t);
			p[t] -= 1;
			if (p[t]) que.push(t);
		}
		
		//continue;
		
		while(!que.empty()) {
			int a = que.top(); que.pop();
			int b = que.top(); que.pop();
			
			printf(" %c%c", 'A'+a, 'A'+b);
			
			p[a] -= 1;
			p[b] -= 1;
			
			if (p[a] > 0) que.push(a);
			if (p[b] > 0) que.push(b);
		}
		
		printf("\n");
	}
	return 0;
}