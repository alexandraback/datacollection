#include <bits/stdc++.h>

using namespace std;

#define lld long long int

lld A[10000];
int N;
lld checa(lld x){
	lld ans = 0;
	for(int i = 0; i < N; i++)
		ans += x / A[i];
	return ans;
}

int main(){
	int T;
	cin >> T;
	for(int caso = 1; caso <= T; caso++){
		printf("Case #%d: ", caso);
		long long int M;
		cin >> N >> M;
		for(int i = 0; i < N; i++){
			cin >> A[i];
		}
		M -= N;
		if(M <= 0){
			printf("%d\n", N);
			continue;
		}
		lld ini = 0, fin = M * 1000000ll, medio;
		while(ini < fin){
			medio = (ini + fin + 1) / 2;
			if(checa(medio) < M)
				ini = medio;
			else fin = medio - 1;
		}
		lld m = checa(ini);
		M -= m;
		ini++;
		for(int i = 0; i < N; i++){
			if(ini % A[i] == 0)
				M--;
			if(M == 0){
				printf("%d\n", i + 1);
				break;
			}
		}
	}
	return 0;
}