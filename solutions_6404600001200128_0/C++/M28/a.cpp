#include <cstdlib>
#include <cstdio>
#include <algorithm>

int N;
int mushrooms[1001];

int method1(){
	int c = 0;
	int last = mushrooms[0];
	for(int i = 1; i < N; ++i){
		if(mushrooms[i] < last){
			c += last - mushrooms[i];
		}
		last = mushrooms[i];
	}
	return c;
}

int method2(){
	int last = mushrooms[0];
	int c = 0;
	for(int i = 1; i < N; ++i){
		c = std::max(last - mushrooms[i], c);
		last = mushrooms[i];
	}
	
	int r = 0;
	last = mushrooms[0];
	for(int i = 1; i < N; ++i){
		r += std::min(last, c);
		last = mushrooms[i];
	}
	
	return r;
}

int main(){
	int t, T;
	scanf("%d", &T);
	for(t = 1; t <= T; ++t){
		scanf("%d", &N);
		
		for(int i = 0; i < N; ++i) scanf("%d", &mushrooms[i]);
		
		printf("Case #%d: %d %d\n", t, method1(), method2());
		
	}
	
	return 0;
}
