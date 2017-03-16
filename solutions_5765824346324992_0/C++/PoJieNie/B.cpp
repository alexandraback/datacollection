#include <cstdio>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;

int min(int B, int *M){
	int m=M[0];
	for(int i=1;i<B;++i){
		if(M[i]<m)
			m=M[i];
	}
	return m;
}

int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}

void solve(int B, int N, int *M){
	int copy[B];
	for(int i=0;i<B;++i){
		copy[i]=M[i];
	}
	static_cast<void>(copy);
	if(N<=B){
		printf(" %d\n", N);
		return;
	}
	long long int g=1;
	for(int i=0;i<B;++i){
		int temp=gcd(g, M[i]);
		g*=M[i]/temp;
	}
	long long int cycle=0;
	for(int i=0;i<B;++i){
		cycle+=g/M[i];
	}
	N%=cycle;
	if(N==0)
		N+=cycle;
	for(int i=0;i<B;++i){
		M[i]=0;
	}
	for(;;){
		int m=min(B, M);
		for(int i=0;i<B;++i){
			M[i]-=m;
		}
		for(int i=0;i<B;++i){
			if(M[i]==0){
				M[i]=copy[i];
				--N;
				if(N==0){
					printf(" %d\n", i+1);
					return;
				}
			}
		}
	}
}

void parse(void){
	int result;
	int B, N;
	result=scanf("%d%d", &B, &N);
	int M[B];
	for(int i=0;i<B;++i){
		result=scanf("%d", &M[i]);
	}
	solve(B, N, M);
	static_cast<void>(result);
}

int main(void){
	int test;
	int result=scanf("%d", &test);
	for(int i=1;i<=test;++i){
		printf("Case #%d:", i);
		parse();
	}
	static_cast<void>(result);
	return 0;
}
