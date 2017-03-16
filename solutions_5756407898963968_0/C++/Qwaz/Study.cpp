#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	freopen("output.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);

	int c;
	for(c = 1; c<=tc; c++){
		printf("Case #%d: ", c);

		int i, cnt[19];
		for(i = 1; i<=16; i++) cnt[i] = 0;

		for(i = 0; i<2; i++){
			int row;
			scanf("%d", &row);

			int j, k;
			for(j = 1; j<=4; j++){
				for(k = 0; k<4; k++){
					int t;
					scanf("%d", &t);
					
					if(j == row) cnt[t]++;
				}
			}
		}

		int ans = -1;
		for(i = 1; i<=16; i++){
			if(cnt[i] == 2){
				if(ans == -1) ans = i;
				else {
					puts("Bad magician!");
					break;
				}
			}
		}

		if(i == 17){
			if(ans == -1) puts("Volunteer cheated!");
			else printf("%d\n", ans);
		}
	}

	return 0;
}