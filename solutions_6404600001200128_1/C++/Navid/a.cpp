#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int tn=0; tn<t; tn++) {
		int n;
		cin >> n;
		vector<int> count;
		for (int i=0; i<n; i++) {
			int tmp;
			cin>>tmp;
			count.push_back(tmp);
		}
		int ans1 = 0;
		int maxrate = 0;
		int ans2 = 0;
		for (int i=1; i<n; i++) {
			if (count[i-1]>count[i]) {
				int diff = count[i-1] - count[i];
				ans1 += diff;
				if (diff > maxrate) {
					maxrate = diff;
				}
			}
		}
		for (int i=0; i+1<n; i++) {
			if (count[i] > maxrate) {
				ans2 += maxrate;
			} else {
				ans2 += count[i];
			}
		}
		cout << "Case #"<<tn+1<<": "<<ans1 <<' ' << ans2 << endl;
	}
}
