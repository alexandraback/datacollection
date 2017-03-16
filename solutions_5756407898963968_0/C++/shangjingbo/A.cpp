#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

const int n = 4;

int answer1[n * n + 1], answer2[n * n + 1];

int main()
{
	int tests, test = 1;
	for (scanf("%d", &tests); test <= tests; ++ test) {
		int row1, row2;
		scanf("%d", &row1);
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				int x;
				scanf("%d", &x);
				answer1[x] = i + 1;
			}
		}
		scanf("%d", &row2);
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				int x;
				scanf("%d", &x);
				answer2[x] = i + 1;
			}
		}
		
		vector<int> answer;
		for (int i = 1; i <= n * n; ++ i) {
			if (answer1[i] == row1 && answer2[i] == row2) {
				answer.push_back(i);
			}
		}
		
		printf("Case #%d: ", test);
		if (answer.size() == 0) {
			puts("Volunteer cheated!");
		} else if (answer.size() > 1) {
			puts("Bad magician!");
		} else {
			printf("%d\n", answer[0]);
		}
	}
	return 0;
}
