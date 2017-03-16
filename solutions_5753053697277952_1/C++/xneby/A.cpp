#include <bits/stdc++.h>
using namespace std;

void test(int TT) {
	vector<string> answer;
	vector<int> P;

	int n;
	cin >> n;
	P.resize(n);

	for(int i=0; i<n; i++) cin >> P[i];

	int sum = accumulate(P.begin(), P.end(), 0);
	if(sum % 2 == 1) {
		auto it = max_element(P.begin(), P.end());
		answer.emplace_back(1, 'A' + distance(P.begin(), it));
		(*it) --;
		sum --;
	}

	while(sum > 0) {
		auto it = max_element(P.begin(), P.end());
		decltype(it) it2;
		for(it2 = P.begin(); !*it2 || it2 == it; it2++);
		answer.push_back(string(1, 'A' + distance(P.begin(), it)) + string(1, 'A' + distance(P.begin(), it2)));
		(*it)--; (*it2)--; sum-=2;
	}

	cout << "Case #" << TT << ":";
	for(auto a : answer) cout << " " << a;
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=t; i++) test(i);
}
