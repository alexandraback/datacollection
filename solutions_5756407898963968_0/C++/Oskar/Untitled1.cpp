#include <cstdio>

int n, t, l[20];

int main(){
	std::freopen("13.txt", "w", stdout);
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		int c = 0, x, y, ans = 0;
		for(int i = 1; i <= 16; i++) l[i] = 0;
		scanf("%d", &x);
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++){
				scanf("%d", &y);
				if(i + 1 == x) l[y] = 1;
			}
		scanf("%d", &x);
		for(int i = 0; i < 4; i++)
			for(int j = 0; j < 4; j++){
				scanf("%d", &y);
				if(i + 1 == x && l[y]){
					if(ans == 0) ans = y;
					else if(ans > 0) ans = -1;
				}
			}
		printf("Case #%d: ", i);
		if(ans == 0) printf("Volunteer cheated!\n");
		else if(ans > 0) printf("%d\n", ans);
		else printf("Bad magician!\n" );
	}
	scanf("\n");
}
