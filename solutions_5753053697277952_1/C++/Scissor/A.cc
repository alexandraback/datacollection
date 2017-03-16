#include<bits/stdc++.h> 

using namespace std;

typedef pair<int, int> PII;

int main(){
	freopen("Al.in", "r", stdin);
	freopen("Al.out", "w", stdout);
	int T; cin>>T;
	for(int o = 1; o <= T; o++){
		int n;
		printf("Case #%d:", o);
		scanf("%d", &n);
		priority_queue<PII> Q;
		while(!Q.empty()) Q.pop();
		int tot = 0;
		for(int i = 1; i <= n; i++){
			int x;
			scanf("%d", &x);
			Q.push(PII(x, i));
			tot += x;
		}
		if (tot & 1){
			PII Nico = Q.top();
			Q.pop(); Q.push(PII(Nico.first - 1, Nico.second));
			printf(" %c", Nico.second + 'A' - 1);
			tot--;
		}
		for(; tot; tot -= 2){
			PII Nico = Q.top();
			Nico.first--;
			printf(" %c", Nico.second + 'A' - 1);
			Q.pop(); Q.push(Nico);
			Nico = Q.top();
			Nico.first--;
			printf("%c", Nico.second + 'A' - 1);
			Q.pop(); Q.push(Nico);
		}
		puts("");
	}
	return 0;
}
