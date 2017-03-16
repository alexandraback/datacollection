#include <cstdio>
#include <algorithm>
#include <array>
#include <cstring>
using namespace std;

long long int side(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3){
	return (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
}

void solve(int N, int *X, int *Y){
	for(int i=0;i<N;++i){
		unsigned int ans=static_cast<unsigned int>(-1);
		for(int j=0;j<N;++j){
			if(i==j)
				continue;
			unsigned int left=0, right=0;
			for(int k=0;k<N;++k){
				if(i==k || j==k)
					continue;
				long long int s=side(X[i],Y[i],X[j],Y[j],X[k],Y[k]);
				if(s>0)
					++left;
				else if(s<0)
					++right;
			}
			ans=min(ans, min(left, right));
			if(ans==0){
				break;
			}
		}
		printf("%u\n", ans);
	}
}

void parse(void){
	int result;
	int N;
	result=scanf("%d", &N);
	int X[N], Y[N];
	for(int i=0;i<N;++i){
		result=scanf("%d%d", &X[i], &Y[i]);
	}
	solve(N, X, Y);
	static_cast<void>(result);
}

int main(void){
	int test;
	int result=scanf("%d", &test);
	for(int i=1;i<=test;++i){
		printf("Case #%d:\n", i);
		parse();
	}
	static_cast<void>(result);
	return 0;
}
