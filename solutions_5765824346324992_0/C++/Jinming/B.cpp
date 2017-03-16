#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a, int b){
	return (b == 0) ? a : gcd(b, a%b);
}

ll LCM(int a, int b){
	return a / gcd(a, b) * b;
}

ll LCM(vector<int> &M){
	ll lcm = 1;
	for(int i = 0; i < M.size(); i++){
		lcm = LCM(lcm, M[i]);
	}
	return lcm;
}

typedef pair<int, int> P;

int solve(int n, vector<int> &M){
	int B = M.size();

	ll lcm = LCM(M);
	int period = 0;
	for(int i = 0; i < B; i++){
		period += lcm / M[i];
	}
	n = n % period;
	n = n ? n : period;
	

	priority_queue<P, vector<P>, greater<P> > pq; // time, barberID
	for(int i = 0; i < B; i++){
		pq.push({0, i});
	}
	
	
	int ret = 0;
	while(n--){
		pair<int, int> cur = pq.top(); pq.pop();
		cur.first += M[cur.second];
		ret = cur.second;
		pq.push(cur);
	}
	return ret + 1;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		int n, B;
		scanf("%d %d", &B, &n);
		vector<int> M(B);
		for(int i = 0; i < B; i++){
			scanf("%d", &M[i]);
		}
		printf("Case #%d: %d\n", t, solve(n, M));
	}
	return 0;
}	
