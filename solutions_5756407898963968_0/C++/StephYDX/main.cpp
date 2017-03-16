#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		int r1;
		scanf("%d", &r1);
		--r1;
		int cards[4];
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				int num;
				scanf("%d", &num);
				if (i == r1) {
					cards[j] = num;
				}
			}
		}
		int r2;
		scanf("%d", &r2);
		--r2;
		int ans = -1;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				int num;
				scanf("%d", &num);
				if (i == r2) {
					bool found = false;
					for(int k = 0; k < 4; ++k) {
						if (cards[k] == num) {
							found = true;
						}
					}
					if (found) {
						if (ans == -1) 
							ans = num;
						else
							ans = -2;
					}
				}
			}
		}
		if (ans == -1) {
			printf("Case #%d: Volunteer cheated!\n", cas);
		}
		else if (ans == -2) {
			printf("Case #%d: Bad magician!\n", cas);
		}
		else {
			printf("Case #%d: %d\n", cas, ans);
		}
	}
	return 0;
}
