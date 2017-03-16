#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q1=0;q1<z;q1++) {
	    int n;
		cin >> n;
		vector<int> vals(n);
		for (int i=0;i<n;i++) {
			cin >> vals[i];
		}

		int first = 0;
		int rate = 0;
		for (int i=0;i<n-1;i++) {
			if (vals[i+1] < vals[i]) {
				first += vals[i] - vals[i+1];
				rate = max(rate, vals[i] - vals[i+1]);
			}
		}

		int second = 0;
		int cur = vals[0];
		for (int i=1;i<n;i++) {
			if (cur < rate) {
				second += cur;
				cur = 0;
			}
			else {
				second += rate;
				cur -= rate;
			}
			cur = vals[i];
		}

		cout << "Case #" << (q1+1) << ": " << first << " " << second << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}