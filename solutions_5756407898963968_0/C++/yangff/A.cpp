#include <cstdio>

int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int t; scanf("%d", &t);
	int cas = 0;
	while (t--){
		cas++;
		int n;  scanf("%d", &n);
		int offset0 = 0, offset1 = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++){
				int x; scanf("%d", &x);
				if (i == n - 1) offset0 |= (1 << x);
			}
		scanf("%d", &n);
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++){
				int x; scanf("%d", &x);
				if (i == n - 1) offset1 |= (1 << x);
			}
		int r = offset0 & offset1;
		int ans = 0;
		for (int i = 1; i <= 16; i++)
			if (r & (1<<i)){
				if (ans == 0)
					ans = i;
				else{
					ans = -1;
					break;
				}
			}
		if (ans == 0){
			printf("Case #%d: Volunteer cheated!\n", cas);
			continue;
		}
		if (ans == -1){
			printf("Case #%d: Bad magician!\n", cas);
			continue;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
}