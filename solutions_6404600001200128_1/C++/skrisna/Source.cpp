#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		vector<int> v(N);
		for (int n = 0; n < N; ++n)
			cin >> v[n];
		int mn1 = 0;
		int prev = v[0];
		int mind = 0;
		for (int n = 1; n < N; ++n)  
		{
			int d = v[n] - prev;
			if (d < 0)
				mn1 += (-d);
			prev = v[n];
			if (d < 0 && std::abs(d) > mind)
				mind = std::abs(d);
		}
		int mn2 = 0;
		prev = v[0];
		float f = (float)mind;
		for (int n = 1; n < N; ++n)  
		{
			mn2 += std::min(mind, prev);
			prev = v[n];
		}
		cout << "Case #" << t << ": " << mn1 << " " << mn2 << endl;
	}
}