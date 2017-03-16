#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <climits>
using namespace std;
#define MAXN 30
struct Senate {
	int Num;
	char Party;
	friend bool operator<(const Senate o1, const Senate o2) {
		return o1.Num > o2.Num;
	}
} senate[MAXN];
int main() {
	int T;
	scanf("%d", &T);
	for (int TT = 1; TT <= T; TT++) {
		printf("Case #%d:", TT);
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &senate[i].Num);
			senate[i].Party = 'A' + i;
		}
		while (senate[0].Num > 0) {
			sort(senate, senate + N);
			if (senate[0].Num == senate[1].Num && senate[1].Num!= senate[2].Num) {
				senate[0].Num--;
				senate[1].Num--;
				printf(" %c%c", senate[0].Party, senate[1].Party);
			}
			else {
				senate[0].Num--;
				printf(" %c", senate[0].Party);
			}
			sort(senate, senate + N);
		}
		printf("\n");
	}
}