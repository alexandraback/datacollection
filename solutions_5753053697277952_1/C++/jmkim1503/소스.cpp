#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int main() {

	int T;
	scanf("%d", &T);

	vector<int> cnt;

	for (int tt = 1; tt <= T; tt++) {

		int N;
		scanf("%d", &N);

		cnt = vector<int>(N);
		int max_cnt = 0;
		int N_cnt = N;

		for (int i = 0; i < N; i++) {

			scanf("%d", &cnt[i]);
			max_cnt += cnt[i];
		}

		printf("Case #%d: ", tt);

		priority_queue<pair<int, int> > myQ;

		for (int i = 0; i < N; i++) {
			myQ.push(make_pair(cnt[i], i));
		}

		while (!myQ.empty()) {

			pair<int, int> now = myQ.top();
			myQ.pop();

			max_cnt--;

			printf("%c", now.second + 'A');

			cnt[now.second]--;

			if (myQ.empty()) break;

			if (cnt[now.second] > 0) {

				myQ.push(make_pair(cnt[now.second], now.second));
			}

			//ÇÑ°³´õ
			if (2 * myQ.top().first > max_cnt) {
				now = myQ.top();
				myQ.pop();
				max_cnt--;

				printf("%c", now.second + 'A');

				cnt[now.second]--;

				if (myQ.empty()) break;

				if (cnt[now.second] > 0) {

					myQ.push(make_pair(cnt[now.second], now.second));
				}
			}
			printf(" ");

			
		}
		printf("\n");
	}
}