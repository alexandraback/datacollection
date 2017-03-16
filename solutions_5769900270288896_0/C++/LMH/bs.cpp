#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define FI(i,a, b) for(int i=a;i<=b;i++)
#define FD(i,a, b) for(int i=a;i>=b;i--)

#define CL(x, y) memset(x, y, sizeof(x))
#define INF 2000000000
#define MAXN ?
#define MAXE ?
#define ll long long
using namespace std;
int n, m[1000][1000], t, r, c, ans;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int calc(){
	int ret = 0;
	FI(i, 1, r){
		FI(j, 1, c){
			FI(k, 0, 3){
				if(m[dx[k] + i][dy[k] + j] && m[i][j])
					ret++;
			}
		}
	}
	return ret / 2;
}
void dfs(int x, int l){
	if(x == 0){
		int tmp = calc();
		if(tmp < ans){
		
			ans = min(tmp, ans);
		}
	
	}else{
		FI(i, l + 1, r * c){
			m[(i - 1) / c + 1][i % c + 1] = 1;
			dfs(x - 1, i); 
			m[(i - 1) / c + 1][i % c + 1] = 0;
		}
	}
}
int main(){
	scanf("%d", &t);
	FI(k, 1, t){
		ans = INF;
		scanf("%d%d%d", &r, &c, &n);
		dfs(n, 0);
		printf("Case #%d: %d\n", k, ans);
	}
}
