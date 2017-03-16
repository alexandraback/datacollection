#include <bits/stdc++.h>

using namespace std;

#define ll long long

int t;


void solve();

int main() {
	ios::sync_with_stdio(0);

	bool file = true;
	if (file) {
		freopen("A-large.in","r", stdin);
		freopen("output.out", "w", stdout);
	}

	cin >> t;
	for (int z = 1; z<= t; z++) {
		cout << "Case #" << z << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

int remaining[30];
vector < pair<int,int> > nums;
int sum;
int n;


bool still_valid() {
	for (int i = 0; i < n; i++) {
		if (nums[i].first > sum/2) return false;
	}
	return true;
}

void solve() {
	cin >> n;
	sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> remaining[i];
		sum+= remaining[i];
	}
	vector <string> res;
	nums.resize(n);
	while(sum > 0) {
		for (int i = 0; i < n; i++) {
			nums[i].first = remaining[i];
			nums[i].second = i;
		}
		sort(nums.begin(), nums.end());
		nums[n-1].first--;
		sum--;
		if (still_valid()) {
			char a = nums[n-1].second;
			a+= 'A';
			string s;
			s+= a;
			res.push_back(s);
			remaining[nums[n-1].second]--;
		} else {
			char a = nums[n-2].second;
			a+= 'A';
			char b = nums[n-1].second;
			b+= 'A';
			string s;
			s+= a;
			s+= b;
			res.push_back( s );
			remaining[nums[n-1].second]--;
			remaining[nums[n-2].second]--;
			sum--;
		}
	}
	cout << res[0];
	for (int i = 1; i < res.size(); i++) {
		cout << " " << res[i];
	}
}
