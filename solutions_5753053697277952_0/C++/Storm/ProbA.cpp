#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

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
		int count = 0;
		for (int i=0;i<n;i++) {
			cin >> vals[i];
			count += vals[i];
		}
		cout << "Case #" << (q1+1) << ": ";
		do {
			int pos = max_element(vals.begin(), vals.end()) - vals.begin();
			vals[pos]--;
			count--;
			if (count == 1 || (n == 2 && (max_element(vals.begin(), vals.end()) - vals.begin()) != pos)) {
				int pos1 = max_element(vals.begin(), vals.end()) - vals.begin();
				vals[pos1]--;
				cout << (char) ('A' + pos) << (char) ('A' + pos1) << " ";
			}
			else {
				cout << (char) ('A' + pos) << " ";
			}
		} while (*max_element(vals.begin(), vals.end()) != 0);
		cout << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}