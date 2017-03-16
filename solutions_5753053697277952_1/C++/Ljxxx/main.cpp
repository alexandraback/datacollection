/*
 * main.cpp
 *
 *  Created on: 9 Apr 2016
 *      Author: ljchang
 */

#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int n, num[30];

void input() {
	scanf("%d", &n);
	for(int i = 0;i < n;i ++) {
		scanf("%d", &num[i]);
	}
}

void solve() {
	char output[3];
	while(true) {
		output[1] = output[2] = '\0';
		int max_d = 0, id = -1;
		for(int i = 0;i < n;i ++) if(num[i] > max_d) {
			max_d = num[i];
			id = i;
		}
		if(id == -1) break;

		-- num[id];
		output[0] = id+'A';

		int cnt = 0, sum = 0;
		for(int i = 0;i < n;i ++) if(num[i]) {
			++ cnt;
			sum += num[i];
		}
		if(cnt == 2&&(sum == 4||max_d == 1)) printf(" %s", output);
		else {
			max_d = 0; id = -1;
			for(int i = 0;i < n;i ++) if(num[i] > max_d) {
				max_d = num[i];
				id = i;
			}
			if(id != -1) {
				output[1] = id+'A';
				-- num[id];
			}
			printf(" %s", output);
		}

		max_d = 0, sum = 0;
		for(int i = 0;i < n;i ++) {
			if(num[i] > max_d) max_d = num[i];
			sum += num[i];
		}
		if(max_d*2 > sum) printf("\nWA\n");
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	for(int cas = 0; cas < t;cas ++) {
		input();
		printf("Case #%d:", cas+1);
		solve();
	}
	return 0;
}
