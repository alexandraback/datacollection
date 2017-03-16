#include <iostream>
#include <climits>

using namespace std;

bool isOccupied(int i, int j, int c, unsigned int mask)
{
	if((i < 0) || (j < 0)) {
		return false;
	} else {
		return (1 << (i * c + j)) & mask;
	}
}

int getUnhappiness(int r, int c, int n, unsigned int mask)
{
	if(__builtin_popcount(mask) != n) {
		return INT_MAX;
	}
	int res = 0;
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			if(isOccupied(i, j, c, mask)) {
				if(isOccupied(i - 1, j, c, mask)) {
					++res;
				}
				if(isOccupied(i, j - 1, c, mask)) {
					++res;
				}
			}
		}
	}
	return res;
}

int solve(int r, int c, int n)
{
	unsigned int mask = 0;
	unsigned int max_mask = (1 << (r * c));
	int res = INT_MAX;
	while(mask < max_mask) {
		res = min(res, getUnhappiness(r, c, n, mask));
		++mask;
	}
	return res;
}

int main()
{
	int t;
	int n, r, c;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cin >> r >> c >> n;
		cout << "Case #" << i << ": " << solve(r, c, n) << endl;
	}
	return 0;
}
