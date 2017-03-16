#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <assert.h>
using namespace std;

bool checkMaj(vector<int>& p, int maj)
{
	for (int i = 0; i < p.size(); ++i) {
		if (p[i] >= maj)
			return true;
	}
	return false;
}
int main()
{
	int num_of_testcases;
	cin >> num_of_testcases;
	for (int t = 1; t <= num_of_testcases; ++t){
		int np;
		cin >> np;
		vector<int> p(np);

		int tot = 0;
		for (int i = 0; i < np; ++i) {
			cin >> p[i];

			tot += p[i];
		}

		list<string> o;

		while (tot > 0)
		{
			string s = "";
			int ma = 0;
			int index = 0;
			for (int i = 0; i < np; ++i) {
				if (p[i] > ma)
				{
					ma = p[i];
					index = i;
				}
			}
			s+=(index + 'A');
			p[index]--;

			ma = 0;
			index = 0;
			for (int i = 0; i < np; ++i) {
				if (p[i] > ma)
				{
					ma = p[i];
					index = i;
				}
			}
			p[index]--;
			if (checkMaj(p, tot / 2) == false)
			{
				s += (index + 'A');
				tot--;
			}
			else {
				p[index]++;
			}

			tot--;

			o.push_back(s);
		}



		cout << "Case #" << t << ": ";
		for (auto& a : o)
			cout << a << " ";
		cout << endl;
	}

    return 0;
}

