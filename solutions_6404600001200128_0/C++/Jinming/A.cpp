#include<bits/stdc++.h>
using namespace std;

typedef long long ll; 

ll method1(vector<ll> &A){
	int n = A.size();
	ll ret = 0;
	for(int i = 1; i < n; i++){
		ret += (A[i] < A[i-1] ? A[i - 1] - A[i] : 0);
	}
	return ret;
}

ll method2(vector<ll> &A){
	int n = A.size();
	ll ret = 0;
	ll rate = 0;
	for(int i = 0 ; i < n - 1; i++){
		rate = max(rate, (A[i] - A[i+1]));
	}
	ll rest = 0, eaten = 0;
	for(int i = 0; i < n; i++){
		eaten += (rest > rate ? rate : rest);
		rest -= (rest > rate ? rate : rest);
		rest = A[i];
	}
	return eaten;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		int n;
		scanf("%d", &n);
		vector<ll> A(n);
		for(int i = 0; i < n; i++){
			scanf("%lld", &A[i]);
		}
		
		printf("Case #%d: %lld %lld\n", t, method1(A), method2(A));
	}
	return 0;
}
