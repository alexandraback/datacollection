#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

void solve()
{
	int n;
	cin >> n;

	vector<int64_t> nums(n);

	for(int64_t& i : nums)
	{
		cin >> i;
	}

	int64_t ansA = 0;
	int64_t ansB = 0;
	int64_t minRate = 0;

	for(int i = 1; i < nums.size(); i++)
	{
		if(nums[i] < nums[i - 1])
		{
			ansA += nums[i - 1] - nums[i];
			minRate = max(minRate, nums[i - 1] - nums[i]);
		}
	}

	for(int i = 1; i < nums.size(); i++)
	{
		ansB += min(nums[i - 1], minRate);
	}

	cout << ansA << " " << ansB;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}

	return 0;
}