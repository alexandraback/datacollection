#include <stdio.h>
#include <string.h>

const int N = 30;

int A[N];

int get_max(){
	int res=0;
	for(int i=0;i<N;++i){
		if (A[i]>A[res]){
			res=i;
		}
	}
	return res;
}

int main(){
	int cases;
	scanf("%d",&cases);
	for(int t=1;t<=cases;++t){
		printf("Case #%d:",t);
		memset(A,0,sizeof(A));
		int n;
		scanf("%d",&n);
		int sum=0;
		for(int i=0;i<n;++i){
			scanf("%d",A+i);
			sum+=A[i];
		}
		while(sum){
			int x=get_max();
			A[x]--;
			--sum;
			printf(" %c",x+'A');
			if (!sum) break;
			int y=get_max();
			A[y]--;
			--sum;
			if (A[get_max()]>sum/2){
				A[y]++;
				sum++;
			} else{
				printf("%c",y+'A');
			}
		}
		puts("");
	}
	return 0;
}
