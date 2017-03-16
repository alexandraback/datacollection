#include <cstdio>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;

void solve(int N, int *M){
	int ans1=0;
	int ans2=0;
	int rate=0;
	for(int i=1;i<N;++i){
		if(M[i]<M[i-1]){
			ans1+=M[i-1]-M[i];
			rate=max(rate, M[i-1]-M[i]);
		}
	}
	for(int i=0;i<N-1;++i){
		if(rate>M[i])
			ans2+=M[i];
		else
			ans2+=rate;
	}
	printf(" %d %d\n", ans1, ans2);
}

void parse(void){
	int result;
	int N, M[10000];
	result=scanf("%d", &N);
	for(int i=0;i<N;++i){
		result=scanf("%d", &M[i]);
	}
	solve(N, M);
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
