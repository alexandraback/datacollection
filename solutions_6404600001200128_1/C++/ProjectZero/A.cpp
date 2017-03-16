#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int N,A[MAXN];

int com1(){
	int now = A[1],ans = 0;
	for(int i=2;i<=N;i++){
		if(A[i] < now){
			ans += (now - A[i]);
			now = A[i];
		}else now = A[i];
	}
	return ans;
}

int com2(){
	int now = A[1],ans = 0;
	for(int rate=0;rate<=100000;rate++){
		now = A[1], ans = 0;

		bool possible = true;
		for(int i=2;i<=N;i++){
			if(now - rate > A[i]){
				possible = false;
				break;
			}

			int add;
			if(now - rate < 0) add = now;
			else add = rate;

			ans += add;
			now = A[i];
		}
		if(possible) return ans;
		// printf("[%d]rate[%d] = %d\n",possible,rate,ans);
	}
	// return 0;
	// assert(false);
}

void run(int test){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]);

	int y = com1();
	int z = com2();
	printf("Case #%d: %d %d\n",test,y,z);
}

int main(){
	// freopen("A.txt","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);

	int T; scanf("%d",&T);
	for(int i=1;i<=T;i++) run(i);
	return 0;
}