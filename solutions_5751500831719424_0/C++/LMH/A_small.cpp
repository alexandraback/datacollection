#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define FI(i,a, b) for(i=a;i<=b;i++)
#define FD(i,a, b) for(i=a;i>=b;i--)

#define CL(x, y) memset(x, y, sizeof(x))
#define INF 100000000
#define MAXN ?
#define MAXE ?
using namespace std;
int i,j, k, N, M, K, T, Q, t1, t2;
char str[1000][1000];
int main(){
	scanf("%d", &T);
	FI(k, 1, T){
		scanf("%d", &N);
		FI(i, 1, N){
			scanf("%s", str[i] + 1);
		}
		int N1 = strlen(str[1] + 1) , N2 = strlen(str[2] + 1);
		int fg = 0;
		t1 = 1, t2 = 1;
		Q = 0;
		while(t1 <= N1 || t2 <= N2){
			if(str[1][t1] == str[2][t2]){
				t1 ++, t2 ++;
			}else{
				if(str[1][t1 - 1] == str[2][t2]){
					t2++;
					Q++;
				}else if(str[2][t2 - 1] == str[1][t1]){
					t1++;
					Q++;
				}else{
					fg = 1;
					break;
				}
			}
		}
		printf("Case #%d: ", k);
		if(fg) printf("Fegla Won\n");
		else printf("%d\n", Q);
	}
}
