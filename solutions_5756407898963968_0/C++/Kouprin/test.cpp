#include <iostream>
#include <vector>
int t, r, rr, a[20], b[20];
using namespace std;
int main() {
cin >> t;
for(int T = 0; T < t; ++T) {
	cin >> r;
	--r;
	for(int i = 0; i < 16; ++i) cin >> a[i];
	cin >> rr;
	--rr;
	for(int i = 0; i < 16; ++i) cin >> b[i];
	vector<int> ans;
	for(int i = 0; i < 16; ++i)
	for(int j = 0; j < 16; ++j)
	if (i / 4 == r && j / 4 == rr && a[i] == b[j]) ans.push_back(a[i]);
	cout << "Case #" << T + 1 << ": ";
	if (ans.size() == 1) cout << ans[0] << endl; else
        if (ans.size() == 0) cout << "Volunteer cheated!" << endl; else
        cout << "Bad magician!" << endl;
}
	return 0;
}
