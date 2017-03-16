#include <cstdio>
#include <algorithm>
using namespace std;

#define D(x) 
#define LL long long

const int MAX_N = (int)(1e3) + 10;
const int MAX_M = (int)(1e5) + 10;

int n, m;;
LL f[MAX_N];

LL cal(LL a)
{
	LL ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret += a / f[i] + 1;
	}
	return ret;
}

LL binary_search(LL start, LL end)
{
	LL l = start;
	LL r = end;
	D(printf("%lld %lld\n", l, r));
	while (l < r)
	{
		LL mid = (l + r) / 2;
		if (cal(mid) >= m)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}


int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d: ", case_num);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &f[i]);
		}
		LL ser_time = binary_search(0, *max_element(f, f + n) * (long long)m + 10);
		D(printf("%lld\n", ser_time));
		LL total_finished = 0;
		for (int i = 0; i < n; i++)
		{
			total_finished += ser_time / f[i] + 1;
		}
		LL over_head = total_finished - (m - 1);
		D(printf("%lld %lld\n", total_finished, over_head));
		int ans = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (ser_time % f[i] == 0)
			{
				over_head--;
				if (over_head == 0)
				{
					ans = i + 1;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
