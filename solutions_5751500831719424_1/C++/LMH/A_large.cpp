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
int i,j, k, N, M, K, fg, T;
int t[1000], Ni[1000], skip[1000], tmp[1000];
char str[1000][1000];
int check(){
	int cnt = 0;
	FI(i, 1, N){
		if(t[i] > Ni[i])
			cnt++;
			//return false;
	}
	if(cnt > 0 && cnt < N){
		fg = 1;
		return false;
	}else if(cnt == N){
		return false;
	}
	return true;
}
int main(){
	scanf("%d", &T);
	FI(k, 1, T){
		scanf("%d", &N);
		FI(i, 1, N){
			scanf("%s", str[i] + 1);
			
		}
		FI(i, 1, N){
			t[i] = 1;
			Ni[i] = strlen(str[i] + 1);
		}
		int Q = 0;
		fg = 0;
		do{
			int fg1 = 0, fg2 = 0;
			FI(i, 2, N){
				if(str[1][t[1]] != str[i][t[i]]){
					fg1 = 1;
				}
			}
			if(fg1 == 1){
				fg = 1;
				break;
			}
			FI(i, 1, N){
				skip[i] = 0;
			}
			int maxs = 0;
			FI(i, 1, N){
				j = 1;
				while(str[i][j + t[i]] == str[i][t[i]]){
					skip[i] = j++;
				}
				skip[i]++;
				tmp[i] = skip[i];
				maxs = max(maxs, skip[i]);
			}
			sort(tmp + 1, tmp + 1 + N);
			int standard = tmp[(N + 1)/ 2];
			FI(i, 1, N){
			//	printf("%d ", skip[i]);
			}
		//	system("pause");
			FI(i, 1, N){
				t[i] += skip[i];
				Q += abs(standard - skip[i]);
			}
			
			
		}while(check());
		printf("Case #%d: ", k);
		if(fg) printf("Fegla Won\n");
		else printf("%d\n", Q);
	}
}
