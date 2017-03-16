#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		int n;
		vector<pair<int, char>> data(26);
		scanf("%d", &n);

		int sum = 0;
		for(int i = 0; i < n; i++) {
			data[i].second = (char)(i + 'A');
			scanf("%d", &data[i].first);
			sum += data[i].first;
		}

		printf("Case #%d:", kase);
		while(true) {
			sort(data.rbegin(), data.rend());
			if(data[0].first == 0) break;

			data[0].first--;
			printf(" %c", data[0].second);

			if(sum % 2 == 1) {
				sum = 0;
				continue;
			}

			sort(data.rbegin(), data.rend());
			if(data[0].first == 0) break;
			data[0].first--;
			printf("%c", data[0].second);
		}

		printf("\n");
	}

	return 0;
}