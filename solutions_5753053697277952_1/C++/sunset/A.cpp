#include <cstdio>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	int N;
	int P[30];
	for(int NOWCASE=1; NOWCASE<=T; ++NOWCASE) {
		scanf("%d", &N);
		int sum = 0;
		for(int i=0; i<N; ++i) {
			scanf("%d", &P[i]);
			sum += P[i];
		}
		printf("Case #%d:", NOWCASE);
		while( sum>0 ) {
			int maxId=0;
			for(int i=1; i<N; ++i)
				if( P[i]>P[maxId] )
					maxId = i;
			if( P[maxId]==0 ) break;
			putchar(' ');
			putchar(maxId+'A');
			--sum;
			--P[maxId];

			if( sum==2 ) continue;
			if( sum==0 ) break;
			maxId=0;
			for(int i=1; i<N; ++i)
				if( P[i]>P[maxId] )
					maxId = i;
			if( P[maxId]==0 ) break;
			putchar(maxId+'A');
			--sum;
			--P[maxId];
		}
		puts("");
	}
	return 0;
}
