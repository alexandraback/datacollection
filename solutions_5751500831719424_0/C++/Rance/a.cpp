#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct {
	char ch;
	int count;
} subs;

vector<subs> conv_str_to_subs_vec(string s)
{
	vector<subs> v;
	subs t;
	char last = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] != last) {
			t.ch = s[i];
			t.count = 1;
			v.push_back(t);
			last = s[i];
		} else {
			v.back().count++;
		}
	}

	return v;
}

bool match(vector<subs>& v1, vector<subs>& v2)
{
	if (v1.size() != v2.size())
		return false;

	for (int i = 0; i < v1.size(); i++) {
		if (v1[i].ch != v2[i].ch)
			return false;
	}

	return true;
}

int main()
{
	int cases;

	cin >> cases;

	for (int i = 1; i <= cases; i++) {
		int count;

		cin >> count;

		bool ok = true;
		vector<vector<subs> > vv;

		for (int j = 0; j < count; j++) {
			string temp;

			cin >> temp;
			
			if (ok) {
				vector<subs> v = conv_str_to_subs_vec(temp);

				if (vv.size() >= 1 && !match(vv[0], v))
					ok = false;

				vv.push_back(v);
			}
		}

		if (ok) {
			int sum = 0;

			for (int j = 0; j < vv.back().size(); j++) {
				int min = 100000;
				int max = 0;

				for (int k = 0; k < vv.size(); k++) {
					count = vv[k][j].count;

					if (count < min)
						min = count;

					if (count > max)
						max = count;
				}

				int diffmin = 100000;

				for (int k = min; k <= max; k++) {
					int diff = 0;

					for (int m = 0; m < vv.size(); m++) {
						count = vv[m][j].count;
						diff += abs(count - k);
					}

					if (diff < diffmin)
						diffmin = diff;
				}

				sum += diffmin;
			}

			cout << "Case #" << i << ": " << sum << endl;
		} else
			cout << "Case #" << i << ": Fegla Won" << endl;
	}

	return 0;
}
