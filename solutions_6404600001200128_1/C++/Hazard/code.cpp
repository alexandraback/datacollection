#include <iostream>
using namespace std;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tc=1; tc<=t; tc++) {
		int n;
		int data[1005];
		cin >> n;
		for (int i=1; i<=n; i++) cin >> data[i];
		int a = 0, b = 0, c = 0;
		for (int i=1; i<n; i++) {
			if (data[i] > data[i + 1]) {
				a += (data[i] - data[i + 1]);
				if (data[i] - data[i + 1] > b) b = data[i] - data[i + 1];
			}
		}
		for (int i=1; i<n; i++) {
			if (data[i] < b) c += data[i];
			else c += b;
		}
		cout << "Case #" << tc << ": " << a << " " << c << endl;
	}
	return 0;
}
