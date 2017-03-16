#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

long long cutDone(long long time, int B, int M[]){
	long long totalCut = 0LL; 
	for(int i=0; i<B; i++){
		totalCut += (long long)ceil(time/(double)M[i]);
	}
	return totalCut;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int B;
		long long N;
		scanf("%d %lld", &B, &N);
		
		int M[B];
		for(int i=0; i<B; i++){
			scanf("%d",&M[i]);
		}
		
		long long left = 0LL;
		long long right = 100000000000000LL;
		long long mid;
		
		while(left<=right){
			mid = (left+right)/2;
			long long nMid = cutDone(mid, B, M);
			long long checkMid = cutDone(mid+1, B, M);
			if((nMid < N) && (checkMid >= N)){
				break;
			}if(nMid >= N){
				right = mid-1;
			} else {
				left = mid+1;
			}
		}

		int ans = 0;
		long long done = cutDone(mid, B,M);
		for(int i=0; i<B; i++){
			if(mid % M[i] == 0){
				done++;
				if(done ==N){
					ans = i+1;
					break;
				}
			}
		}
		
		printf("Case #%d: %d\n", t, ans);
		
	}
	return 0;
}