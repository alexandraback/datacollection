#include<bits/stdc++.h>


using namespace std;
 
int X[1 << 18];
int a, b, n;
 
 
int P(int i);
int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> a >> b >> n;
 
		int M = a * b * n * 100;
		for (int i = 1; i < (1 << (a * b)); i++){
			X[i] = X[i - (i & -i)] + 1;
			if (X[i] == n) M = min(M, P(i));
		}
		printf("Case #%d: %d\n", t, M);
	}
}
int P(int i){
	int res = 0;
	for (int r = 0; r < a; r++){
		for (int c = 0; c < b; c++){
			if (c > 0 and (i & (1 << (r * b + c))) and (i & (1 << (r * b + c - 1))))
				res++;
			if (r > 0 and (i & (1 << (r * b + c))) and (i & (1 << (r * b + c - b))))
				res++;
		}
	}
return res;
}