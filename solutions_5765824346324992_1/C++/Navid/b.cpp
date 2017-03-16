#include <iostream>
#include <vector>
using namespace std;

int isgood(int n, long long t, const vector<int> & ts) {
	long long sum = 0;
	for (int i=0; i<ts.size(); i++) {
		sum += t/ts[i] + 1 ;
	}
	return sum >= n;
}

int main() {
	int t;
	cin >> t;
	for (int tn=0; tn<t; tn++) {
		int b, n;
		cin >> b >> n;
		vector<int> ts;
		for (int i=0; i<b; i++) {
			int tmp;
			cin >> tmp;
			ts.push_back(tmp);
		}
		long long mini = -1;
		long long maxi = (long long) 1000000000 * (long long) 1000000;
		while (maxi-mini > 1) {
			long long mid = (maxi+mini)/2;
			if (isgood(n, mid, ts)) {
				maxi = mid;
			} else {
				mini = mid;
			}
		}
		long long sum = 0;
		for (int i=0; i<ts.size(); i++) {
			sum += maxi/ts[i] + 1 ;
		}
		int offset = sum-n;
		int ans = 0;
		for (int i=b-1; i>=0; i--) {
			if (maxi % ts[i] == 0) {
				if (offset == 0) {
					ans = i;
					break;
				} else {
					offset--;
				}
			}
		}
		cout << "Case #"<<tn+1<<": "<<ans+1<<endl;
	}
}