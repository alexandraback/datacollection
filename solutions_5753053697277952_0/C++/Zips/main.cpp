#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max_N 30
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	int N;
	int S[max_N];
	int m1, m2, a;

	for(int i=0; i<T; i++){
		for(int j=0; j<max_N; j++) S[j] = 0;

		printf("Case #%d: ", i+1);

        scanf("%d", &N);

        for(int j=1; j<=N; j++){
			scanf("%d", &S[j]);
			S[0]+=S[j];
        }

        while(S[0]>0){
			m1 = 1;
			m2 = 1;
			a=0;
			for(int j=1; j<=N; j++){
				if(S[m1]<=S[j]){
					m2 = m1;
					m1 = j;
				}
				if(S[j]>((S[0]-2)/2)) a++;
			}

			if(a>=3){
				printf("%c ", 'A'+m1-1);
				S[m1]--;
				S[0]--;
			}
			else if(a==1){
				printf("%c%c ", 'A'+m1-1, 'A'+m1-1);
				S[m1]-=2;
				S[0]-=2;
			}
			else{
				printf("%c%c ", 'A'+m1-1, 'A'+m2-1);
				S[m1]--;
				S[m2]--;
				S[0]-=2;
			}
        }

		printf("\n");
	}

	return 0;
}
