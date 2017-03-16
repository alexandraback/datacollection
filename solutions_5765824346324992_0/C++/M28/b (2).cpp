#include <cstdlib>
#include <cstdio>
#include <numeric>

int barberDuration[1001];
int barberTimeLeft[1001];
int B, N;

long long gcd(int a, int b){
	for (;;){
	    if (a == 0) return b;
	    b %= a;
	    if (b == 0) return a;
	    a %= b;
	}
}

long long lcm(int a, int b){
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

int solve(){
	long long result = std::accumulate(barberDuration + 1, barberDuration + 1 + B, 1LL, lcm);
	
	if(result != 0){
		long long acc = 0;
		
		for(int k = 1; k <= B; ++k){
			acc += result / barberDuration[k];
		}
		
		if(acc != 0){
			//printf("r = %lld acc = %lld\n", result, acc);
			N -= 1;
			N %= acc;
			N += 1;
		}
	}
	
	for(int i = 0; i < N; ++i){
		int lowest = 1;
		for(int k = 2; k <= B; ++k){
			if(barberTimeLeft[k] < barberTimeLeft[lowest]){
				lowest = k;
			}
		}
		
		//printf("Costumer %d going to barber %d\n", i, lowest);
		if(i == N - 1) return lowest;
		
		
		int tmp = barberTimeLeft[lowest];
		if(barberTimeLeft[lowest] != 0){
			for(int k = 1; k <= B; ++k){
				barberTimeLeft[k] -= tmp;
			}
		}
		
		barberTimeLeft[lowest] = barberDuration[lowest];
		
	}
	return -1;
}

int main(){
	//stdin = freopen("b", "r", stdin);
	int t, T;
	scanf("%d", &T);
	
	for(t = 1; t <= T; ++t){
		scanf("%d%d", &B, &N);
		for(int i = 1; i <= B; ++i){
			scanf("%d", &barberDuration[i]);
			barberTimeLeft[i] = 0;
		}
		
		printf("Case #%d: %d\n", t, solve());
	}
	
	
	return 0;
}
