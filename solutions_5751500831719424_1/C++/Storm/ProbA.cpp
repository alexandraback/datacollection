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
		int n;
		cin >> n;

		vector<string> vals(n);
		for (int i=0;i<n;i++) {
			cin >> vals[i];
		}

		vector<vector<pair<char, int> > > inp;
		for (int i=0;i<n;i++) {
			vector<pair<char, int> > temp;
			temp.push_back(make_pair(vals[i][0], 1));
			for (int j=1;j<vals[i].size();j++) {
				if (vals[i][j] == vals[i][j-1])
					temp[temp.size() - 1].second++;
				else
					temp.push_back(make_pair(vals[i][j], 1));
			}
			inp.push_back(temp);
		}

		int best = -1;
		bool flag = true;

		for (int i=1;i<inp.size();i++) {
			if (inp[i].size() != inp[0].size()) {
				flag = false;
				break;
			}
			for (int j=0;j<inp[0].size();j++) {
				if (inp[0][j].first != inp[i][j].first) {
					flag = false;
					break;
				}
			}

			if (!flag)
				break;
		}

		if (flag) {
			int count = 0;
			for (int j=0;j<inp[0].size();j++) {
				map<int, int> m;
				for (int i=0;i<inp.size();i++) {
					m[inp[i][j].second]++;
				}

				int large = -1;
				for (map<int,int>::iterator iter=m.begin();iter!=m.end();iter++) {
					int c=0;
					for (map<int,int>::iterator iter2=m.begin();iter2!=m.end();iter2++) {
						if (iter->first == iter2->first)
							continue;
						c += abs(iter->first - iter2->first) * iter2->second;
					}
					if (large == -1 || c < large)
						large = c;
				}
				count += large;
			}
			best = count;
		}

		cout << "Case #" << (q + 1) << ": ";

		if (best == -1)
			cout << "Fegla Won" << endl;
		else
			cout << best << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}