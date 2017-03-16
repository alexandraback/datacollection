#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


typedef long long int64;


int64 count_customer(const int64 t, const vector<int> &m)
{
	int64 c = 0;

	for(auto mi : m) {

		if(t % mi == 0)
			c += t / mi;
		else
			c += t / mi + 1;
	}

	return c;
}


int main()
{
	int test_case;

	scanf("%d", &test_case);

	for(int case_num = 1; case_num <= test_case; ++case_num) {

		int b, n;
		vector<int> m;

		scanf("%d%d", &b, &n);
		m.resize(b);
		for(int i = 0; i < b; ++i)
			scanf("%d", &m[i]);

		int64 lb = 0, ub = 100000LL * n;

		if(count_customer(lb, m) >= n || count_customer(ub, m) < n)
			fprintf(stderr, "Error\n");

		while(ub - lb > 1) {

			const int64 mid = (lb + ub) / 2;

			if(count_customer(mid, m) < n)
				lb = mid;
			else
				ub = mid;
		}

		int ans = -1;
		int it = count_customer(lb, m);

		for(int i = 0; i < b; ++i) {
			if(lb % m[i] == 0)
				it += 1;
			if(it == n) {
				ans = i;
				break;
			}
		}

		printf("Case #%d: %d\n", case_num, ans + 1);

	}

	return 0;
}
