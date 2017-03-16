#include <cstdio>
using namespace std;

const long long INF = 1000000000000000;
const int B = 1000 + 100;
long long m[B];

long long c(long long t, int b)
{
	long long s = 0;

	for(int i = 1; i <= b; ++i)
		s += (t + m[i] - 1) / m[i];

	return s;
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int ca = 1; ca <= T; ++ca) {
		int b, n;
		scanf("%d%d", &b, &n);
		for(int i = 1; i <= b; ++i)
			scanf("%lld", &m[i]);

		long long min = 0, max = INF;
		while(min + 1 < max) {
			long long mid = (min + max) / 2;			
			if(c(mid, b) < n)
				min = mid;
			else
				max = mid;
		}

		long long p = n - c(min, b), j = 0;

		for(int i = 1; i <= b; ++i)
			if(min % m[i] == 0) {
				++j;
				if(j == p) {
					printf("Case #%d: %d\n", ca, i);
					break;
				}
			}
	}
}