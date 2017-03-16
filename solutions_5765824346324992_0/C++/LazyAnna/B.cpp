#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int tests;
	int b;
	long long n;
	int a[2000];
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> b >> n;
		//cout << b << " " << n << endl;
		int mmax = 0;
		for (int i = 0; i < b; ++i) {
			cin >> a[i];
			if (a[i] > mmax) mmax = a[i];
		}
		//sort(a, a + b);
		int maxn = 0;
		for (int i = 0; i < b; ++i)
			maxn += (mmax / a[i]);
		long long maxtime = (n / maxn + 1) * mmax;
		long long head = 0;
		long long tail = maxtime;
		while (head <= tail) {
			long long mid = (head + tail) / 2;
			int flag = 0;
			bool bf = false;
			long long count = 0;
			for (int i = 0; i < b; ++i) {
				long long x = mid / a[i];
				if (x * a[i] == mid) {
					if (flag == 0) flag = i + 1;
					count += x;
				} else {
					count += (x + 1);
				}
			}
			//cout << mid << " " << count << endl;
			//if ((count == n - 1) && (flag != 0)) {
			//	cout << "Case #" << t << ": " << flag << endl;
			//	break;
			//}
			if (count > n - 1) {
				tail = mid - 1;
				continue;
			}
			for (int i = 0; i < b; ++i) {
				if (mid % a[i] == 0) ++count;
				if (count == n) {
					bf = true;
				    cout << "Case #" << t << ": " << i + 1 << endl;	
				    break;				
				}
			}
			if (bf) break;
			head = mid + 1;
		} 
	}
	return 0;
}