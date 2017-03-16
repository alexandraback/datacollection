#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int nums[105];

int getmin(int n) {
	sort(nums, nums+n);
	int a = nums[n/2];
	int total = 0;
	for (int i = 0; i < n; i++) {
		total += abs(nums[i] - a);
	}
	return total;
}

char buf[105];
vector<pair<char, int> > v[105];
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		v[i].clear();
		for (int j = 0; buf[j] != '\0'; j++) {
			if (j == 0 || buf[j] != buf[j-1]) {
				v[i].push_back(pair<char,int>(buf[j], 1));
			} else {
				v[i][v[i].size() - 1].second++;
			}
		}
	}

	int len = v[0].size();
	for (int i = 1; i < n; i++) {
		if ((int)v[i].size() != len) {
			printf("Fegla Won\n");
			return;
		}
	}


	int total = 0;
	for (int j = 0; j < len; j++) {
		for (int i = 0; i < n; i++) {
			if (v[0][j].first != v[i][j].first) {
				printf("Fegla Won\n");
				return;
			}
			nums[i] = v[i][j].second;
		}
		total += getmin(n);
	}
	printf("%d\n", total);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
}
