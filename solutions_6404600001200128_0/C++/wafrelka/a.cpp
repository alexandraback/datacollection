#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int test_case;

	scanf("%d", &test_case);

	for(int case_num = 1; case_num <= test_case; ++case_num) {

		int n;
		vector<int> m;

		scanf("%d", &n);
		m.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &m[i]);

		int x = 0, y = 0;
		int max_rate = 0;

		for(int i = 0; i < n - 1; ++i) {

			const int d = m[i + 1] - m[i];

			if(d < 0)
				x += -d;
			max_rate = max(max_rate, -d);
		}

		for(int i = 0; i < n - 1; ++i)
			y += min(max_rate, m[i]);

		printf("Case #%d: %d %d\n", case_num, x, y);

	}

	return 0;
}
