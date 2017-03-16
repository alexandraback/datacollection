#include <bits/stdc++.h>

const int MAXB = 1005;
long long N;
int B,A[MAXB];

long long check(long long val){
	long long sum = 0;
	for(int i=1;i<=B;i++){
		sum += (val+(long long)A[i]-1LL)/A[i];
	}
	return sum;
}

void run(int test){
	scanf("%d %lld",&B,&N);
	for(int i=1;i<=B;i++) scanf("%d",&A[i]);

	long long left = 0LL, right = 100000000000005, mid;
	while(left < right){
		mid = (left+right)/2LL;
		long long aa = check(mid);

		if(aa >= N) right = mid;
		else left = mid+1;
	}
	// left = start_time = [i]
	// left-1 = end_time 
	assert(left-1LL >= 0);

	long long v1 = check(left-1LL);
	int answer = -1;
	for(int i=1;i<=B;i++){
		if( (left-1LL)%A[i] == 0) v1++;
		if( v1 == N ){
			answer = i;
			break;
		}
	}
	assert(answer != -1);

	printf("Case #%d: %d\n",test,answer);
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);

	int T; scanf("%d",&T);
	for(int i=1;i<=T;i++) run(i);

	return 0;
}