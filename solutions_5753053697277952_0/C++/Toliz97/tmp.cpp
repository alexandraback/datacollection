#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
#define mk(a, b) make_pair(a, b)

struct Shivam {
	typedef std::pair<int, int> const& param_type;
	bool operator()(param_type lhs, param_type rhs) const {
		if (lhs != rhs) return lhs.first > rhs.first;
		else return lhs.second < rhs.second;
	};
};

int main()
{
	int t, T;
	int i;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	for (t = 1; t <= T; t++)
	{
		int n, sum = 0;  cin >> n;
		multiset<ii, Shivam> data;
		for (i = 0; i < n; i++)
		{
			int tmp; cin >> tmp;
			data.insert(mk(tmp, i));
			sum += tmp;
		}

		cout << "Case #" << t << ": ";
		while (sum)
		{
			if (n == 3 && (*data.begin()).first == 1)
			{
				int f = (*data.begin()).first, s = (*data.begin()).second;
				cout << (char) (s + 65);
				data.erase(data.begin());
				if (f > 1) data.insert(mk(f-1, s));
				cout << " ";
				sum -= 1;
			}
			else
			{
				int f = (*data.begin()).first, s = (*data.begin()).second;
				cout << (char) (s + 65);
				data.erase(data.begin());
				if (f > 1) data.insert(mk(f-1, s));
				f = (*data.begin()).first; s = (*data.begin()).second;
				cout << (char) (s + 65);
				data.erase(data.begin());
				if (f > 1) data.insert(mk(f-1, s));
				cout << " ";
				sum -= 2;
			}

			n = data.size();
		}
		cout << endl;
	}

	return 0;
}