#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

struct Block {
	int k;
	char c;
	bool operator<(const Block& nw) const {
		return k < nw.k;
	}
};

void push(const Block& val, std::priority_queue<Block>& h) {
	if (val.k) {
		h.push(val);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	std::cin >> tests;
	for (int t = 1; t <= tests; t++) {
		int n;
		std::cin >> n;
		std::priority_queue<Block> h;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int k;
			std::cin >> k;
			sum += k;
			h.push({ k, 'A' + i });
		}
		printf("Case #%d: ", t);
		while (sum) {
			if (h.top().k > sum / 2) {
				throw h.top().c;
			}
			if (sum % 2 || h.size() == 1) {
				auto x = h.top();
				h.pop();
				std::cout << x.c << " ";
				x.k--;
				sum--;
				push(x, h);
			}
			else {
				auto x = h.top();
				h.pop();
				auto y = h.top();
				h.pop();
				std::cout << x.c << y.c << " ";
				x.k--;
				y.k--;
				sum -= 2;
				push(x, h);
				push(y, h);
			}
		}
		std::cout << std::endl;
	}
	
	return 0;
}