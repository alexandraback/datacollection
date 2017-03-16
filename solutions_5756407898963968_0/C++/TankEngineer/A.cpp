#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d", &a);
		--a;
		vector<int> tmp;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				int u;
				scanf("%d", &u);
				if (i == a) {
					tmp.push_back(u);
				}
			}
		}
		scanf("%d", &b);
		--b;
		vector<int> ans;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				int v;
				scanf("%d", &v);
				if (i == b) {
					for (int k = 0; k < 4; ++k) {
						if (tmp[k] == v) {
							ans.push_back(v);
						}
					}
				}
			}
		}
		static int id = 0;
		printf("Case #%d: ", ++id);
		if (ans.size() == 0) {
			printf("Volunteer cheated!\n");
		} else if (ans.size() > 1) {
			printf("Bad magician!\n");
		} else {
			printf("%d\n", ans[0]);
		}
	}
	return 0;
}
