#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <assert.h>
#include <functional>
#define SUBMIT 1
using namespace std;
void f() {
	freopen("c:\\icpc\\input.txt", "r", stdin);
	freopen("c:\\icpc\\output.txt", "w", stdout);
}
pair<int, char> cnt_letter[26];
int nonzeros() {
	int res = 0;
	for (int i = 0; i < 26; i++)
		if (cnt_letter[i].first>0) res++;
	return res;
}
bool comp(const pair<int, char> &l, const pair<int, char> &r) {
	return l.first > r.first;
}
int main(void) {
	if (SUBMIT) f();
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);

		
		int N; scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &cnt_letter[i].first);
			cnt_letter[i].second = 'A' + i;
		}
		int cnts;
		while (cnts = nonzeros()) {
			sort(cnt_letter, cnt_letter + N, comp);
			if (cnts > 2) {
				printf("%c ", cnt_letter[0].second);
				cnt_letter[0].first--;
			}
			else if (cnts == 2){
				if (cnt_letter[0].first > 1 && cnt_letter[1].first == 1) {
					printf("%c ", cnt_letter[0].second);
					cnt_letter[0].first--;
				}
				else {
					printf("%c%c ", cnt_letter[0].second, cnt_letter[1].second);
					cnt_letter[0].first--;
					cnt_letter[1].first--;
				}
				
			}
			else if (cnts == 1) assert(0);
		}
		printf("\n");
	}
}