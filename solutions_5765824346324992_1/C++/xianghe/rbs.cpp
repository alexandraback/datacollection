#include <iostream>
using namespace std;

typedef long long ll;
const ll MAX = 1e12;
ll a[2333];

int main()
{
	int T;
	freopen("B-large.in","r",stdin);
	freopen("rbs.out","w",stdout);
	while(cin >> T)
	{
		for(int j = 1 ; j <= T ; j++)
		{
			int B, N;
			cin >> B >> N;
			for(int i = 1; i <= B; i++)
				cin >> a[i];
			ll l = 0, r = MAX;
			ll mid = 0, tmp = 0;
			ll rst = 0, ans = 0;
			while(l < r)
			{
				mid = l + (r - l) / 2;
				tmp = 0;
				for(int i = 1; i <= B; i++)
				{
					tmp += mid / a[i] + 1;
				}
				if(tmp < N)
					l = mid + 1;
				else
					r = mid;
				ans = l;
			}
			for(int i = 1; i <= B; i++)
				rst += ans / a[i] + 1;
			tmp = rst - N + 1;
			for(int i = B; i > 0; i--)
			{
				if(l % a[i] == 0)
				{
					tmp--;
					if(tmp == 0)
					{
						rst = i;
						break;
					}
				}
			}
			cout << "Case #" << j << ": " << rst << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
