#include <iostream>
#include <vector>

using namespace std;

int MethodOne(vector<int> & nums, int * gap) {
	int eat = 0;
	for (int i = 0; i < nums.size() - 1; ++i) {
		int diff = nums[i] - nums[i + 1];
		if (diff > 0) {
			eat += diff;
			if (*gap < diff) {
				*gap = diff;
			}
		}
	}
	return eat;
}

int MethodTwo(vector<int> & nums, int gap) {
	int eat = 0;
	for (int i = 0; i < nums.size() - 1; ++i) {
		if (nums[i] < gap) {
			eat += nums[i];
		} else {
			eat += gap;
		}
	}
	return eat;
}

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int timestamps;
		cin >> timestamps;
		vector<int> nums(timestamps);
		for (int j = 0; j < timestamps; ++j) {
			cin >> nums[j];
		}
		int gap = 0;
		cout << "Case #" << i + 1 << ": " << MethodOne(nums, &gap) << " " << MethodTwo(nums, gap)<< endl;
		
	}
	return 0;
}