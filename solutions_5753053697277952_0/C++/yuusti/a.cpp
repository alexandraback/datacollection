#include <iostream> 
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <functional>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <ctime>
#include <unordered_map>

using namespace std;

string solve() {
	int n;
	cin >> n;

	int sum = 0;
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		q.push(make_pair(x, i));
		sum += x;
	}

	string ans = "";

	auto f = [&]() {
		auto p = q.top();
		q.pop();
		ans += 'A' + p.second;
		--p.first;
		q.push(p);
	};

	if (sum & 1) {
		sum--;
		ans += " ";
		f();
	}

	while (sum) {
		sum -= 2;
		ans += " ";
		f();
		f();
	}

	return ans;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d:", i);
		printf("%s\n", solve().c_str());
	}


}