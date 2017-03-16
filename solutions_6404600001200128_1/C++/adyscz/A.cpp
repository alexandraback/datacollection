#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int meth1(vector<int> &Ms)
{
	int y = 0;
	for (int i = 1; i < Ms.size(); ++i) {
		if (Ms[i] < Ms[i-1])
			y += Ms[i-1] - Ms[i];
	}
	return y;
}

int meth2(vector<int> &Ms)
{
	int m = 0;
	for (int i = 0; i < Ms.size() - 1; ++i) {
		if (Ms[i] > Ms[i+1])
			m = max(m, Ms[i] - Ms[i+1]);
	}

	int r = 0;
	for (int i = 0; i < Ms.size() - 1; ++i)
		r += min(Ms[i], m);
	return r;
}

int main()
{
	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N; cin >> N;
		vector<int> Ms;
		for (int i = 0; i < N; ++i) {
			int m; cin >> m;
			Ms.push_back(m);
		}
		cout << "Case #" << t << ": " << meth1(Ms) << " " << meth2(Ms) << endl;
	}
	return 0;
}
