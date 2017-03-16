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
	for (int q=0;q<z;q++) {
		int b,n;
		cin >> b >> n;
		vector<int> vals(b);
		long long tot = 5;
		for (int i=0;i<b;i++) {
			cin >> vals[i];
			tot *= vals[i];
		}

		vector<int> avail(b, 0);
		vector<int> seq;
		for (int i=0;i<tot;i++) {
			for (int j=0;j<b;j++) {
				if (avail[j] <= i) {
					avail[j] = i + vals[j];
					seq.push_back(j);
				}
			}
		}

		n--;
		n -= (n / seq.size()) * seq.size();
		cout << "Case #" << (q + 1) << ": " << (seq[n] + 1) << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}