//#include <stdio.h>
//
//int main()
//{
//	//freopen("B-small-attempt1.in", "r", stdin);
//	//freopen("B-small-attempt1.out", "w", stdout);
//
//	int t;
//	scanf("%d", &t);
//
//	for (int T = 1; T <= t; T++){
//		int r, c, n;
//		scanf("%d %d %d", &r, &c, &n);
//
//		int chk[18][18] = { 0 };
//
//		for (int i = 1; i <= r; i++)for (int j = 1; j <= c; j++)chk[i][j] = 1;
//
//
//		if (r + c <= n){}
//
//		int rem = r*c;
//		while (rem > n){
//			int a = -1, b = -1, k = -1;
//			for (int i = 1; i <= r; i++){
//				for (int j = 1; j <= c; j++){
//					if (chk[i][j]){
//						int tk = chk[i - 1][j] + chk[i + 1][j] + chk[i][j - 1] + chk[i][j + 1];
//						if (tk >= k){
//							k = tk;
//							a = i, b = j;
//						}
//					}
//				}
//			}
//			rem--;
//			chk[a][b] = 0; // 3 3 5 ¥‰¿∫ 4
//		}
//		
//		int ans = 0;
//		for (int i = 1; i <= r; i++){
//			for (int j = 1; j <= c; j++){
//				if (chk[i][j] && chk[i][j + 1])ans++;
//				if (chk[i][j] && chk[i + 1][j])ans++;
//			}
//		}
//
//		printf("Case #%d: %d\n", T, ans);
//	}
//}

#include <stdio.h>

int main()
{
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int T = 1; T <= t; T++){
		int r, c, n;
		scanf("%d %d %d", &r, &c, &n);

		int l = 1 << (r*c);

		int ans = 10003;
		
		for (int i = 0; i < l; i++){
			int x = 0;
			int k[18][18] = { 0 };
			for (int j = 0; j < r*c; j++){
				int a = (1 << j);
				if (i&a){
					x++;
					k[j / c][j%c] = 1;
				}// 2 3 6
				// 
			}
			if (x == n){
				int y = 0;
				for (int a = 0; a < r; a++){
					for (int b = 0; b < c; b++){
						if (k[a][b] && k[a + 1][b])y++;
						if (k[a][b] && k[a][b + 1])y++;
					}
				}
				if (ans > y)ans = y;
			}
		}

		printf("Case #%d: %d\n", T, ans);
	}
}