#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
    while (true) {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b) {
    int tmp = gcd(a, b);
    return tmp ? (a / tmp * b) : 0;
}

int nlcm(int *a, int n) {
    if (n == 1)
        return *a;
	else
		return lcm(a[n-1], nlcm(a, n-1));
}

int Barber(int *nums, int B, int N) {
	int common = nlcm(nums, B);
	int iter = 0;
	for (int i = 0; i < B; ++i) {
		iter += common / nums[i];
	}
	N = N % iter;
	if (N == 0) {
		N += iter;
	}
	if (N < B) {
		return N;
	}
	vector<int> time_cost(B, 0);
	for (int i = 0; i < N; ++i) {
		int min_B = 0;
		int min_time = time_cost[0];
		for (int j = 1; j < B; ++j) {
			if (time_cost[j] < min_time) {
				min_time = time_cost[j];
				min_B = j;
			}
		}
		time_cost[min_B] += nums[min_B];
		if (i == N - 1) {
			return min_B + 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int B;
		int N;
		cin >> B;
		cin >> N;
		// vector<int> nums(B);
		int * nums = new int[B];
		for (int j = 0; j < B; ++j) {
			cin >> nums[j];
		}
		int gap = 0;
		cout << "Case #" << i + 1 << ": " << Barber(nums, B, N) << endl;
		
	}
	return 0;
}