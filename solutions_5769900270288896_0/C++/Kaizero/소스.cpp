#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>X[10100], Y[10100];
int n, m, TC, T, K, Res, P[10100];
int Gap(int x, int y){
	return X[x][y] + Y[x][y] + X[x - 1][y] + Y[x][y - 1];
}
void Del(int x, int y){
	if (X[x][y]){
		Res--;
		X[x][y] = 0;
	}
	if (Y[x][y]){
		Res--;
		Y[x][y] = 0;
	}
	if (x>1 && X[x-1][y]){
		Res--;
		X[x-1][y] = 0;
	}
	if (y>1 && Y[x][y-1]){
		Res--;
		Y[x][y-1] = 0;
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, KK, RR;
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
		scanf("%d%d%d", &n, &m, &K);
		KK = K;
		if (n > m)swap(n, m);
		if (m == 1 || K * 2 <= n*m+1){
			printf("0\n");
			continue;
		}
		if (n == 1){
			printf("%d\n", m - 1 - (m - K) * 2);
			continue;
		}
		K = n*m - K;
		Res = n*(m - 1) + m*(n - 1);
		if (K * 2 <= (n - 2)*(m - 2) + 1){
			printf("%d\n", Res - K * 4);
			continue;
		}
		for (i = 0; i <= n; i++){
			X[i].resize(m + 1);
			Y[i].resize(m + 1);
		}
		for (i = 0; i <= n; i++){
			for (j = 0; j <= m; j++){
				X[i][j] = Y[i][j] = 1;
				if (!i || !j)X[i][j] = Y[i][j] = 0;
				if (i == n)X[i][j] = 0;
				if (j == m)Y[i][j] = 0;
			}
		}
		for (i = 2; i < n; i++){
			for (j = 2; j < m; j++){
				if ((i + j) % 2 == 0){
					Del(i, j);
					K--;
				}
			}
		}
		while (K){
			int MM = 0, x, y;
			for (i = 1; i <= n; i++){
				for (j = 1; j <= m; j++){
					if (MM < Gap(i, j)){
						MM = Gap(i, j);
						x = i;
						y = j;
					}
				}
			}
			Del(x, y);
			K--;
		}
		KK -= (n*m + 1) / 2;
		int cc, c = 0;
		for (i = 1; i <= n; i++){
			for (j = 1; j <= m; j++){
				if ((i + j) % 2 == 1){
					cc = 0;
					if (i == 1 || i == n)cc++;
					if (j == 1 || j == m)cc++;
					P[c++] = 4 - cc;
				}
			}
		}
		sort(P, P + c);
		RR = 0;
		for (i = 0; i < KK; i++)RR += P[i];
		printf("%d\n", min(RR, Res));
	}
}