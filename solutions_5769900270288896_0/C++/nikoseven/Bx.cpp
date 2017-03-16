#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int r,c;
const int DI[] = {-1,1,0,0};
const int DJ[] = {0,0,-1,1};

int cBit(int x) {
	int r = 0;
	while(x) {
		if(x&1)
			++r;
		x >>= 1;
	}
	return r;
}

int count(int s) {
	int A = 0;
	for(int i=0;i<r;++i) for(int j=0;j<c;++j) if( (s>>(i*c+j))&1 ) {
		if( j<c-1 && (s>>(i*c+j+1))&1 )
			++A;
		if( i<r-1 && (s>>(i*c+j+c))&1 )
			++A;
	}
	return A;
}

int main() {
	int T,ics = 0;
	scanf("%d",&T);
	while(T--) {
		int z;
		scanf("%d%d%d",&r,&c,&z);
		int L = r*c;
		int ans = r*c*4;
		for(int i=0;i<(1<<L);++i) if( cBit(i) == z ) {
			ans = min(ans,count(i));
			if(ans == 0)
				break;
		}
		printf("Case #%d: %d\n",++ics,ans);
	}
	return 0;
}