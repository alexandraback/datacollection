#include <vector>
#include <iostream>
using namespace std;

void process(int tc)
{
	int n = 0;
	int num[26];
	cin >> n;
	int total = 0;
	for (int i = 0 ; i < n ; ++i)
		cin >> num[i], total += num[i];
	cout << "Case #" << tc << ":";
	while (total) {
		int maxn = 0;
		vector<int> maxi;
		for (int i = 0 ; i < n ; ++i)
			if (num[i] > maxn)
				maxn = num[i], maxi.clear(), maxi.push_back(i);
			else if (num[i] == maxn)
				maxi.push_back(i);
		if (maxi.size() % 2) {
			cout << ' ' << (char) ('A' + maxi[0]);
			num[maxi[0]] --;
			--total;
		} else {
			cout << ' ';
			for (int i = 0 ; i < 2 ; ++i) {
				cout << (char) ('A' + maxi[i]);
				num[maxi[i]]--;
				--total;
			}
		}
	}
	cout << endl;
}
int main()
{
	int t = 0;
	cin >> t;
	for (int i = 1 ; i <= t; ++i)
		process(i);
}
