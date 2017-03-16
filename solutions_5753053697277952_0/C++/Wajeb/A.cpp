#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;

		multiset<pair<int, char> > senators;
		for(int i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			senators.insert(make_pair(x, 'A' + i));
		}

		vector<char> res;
		while(senators.size() > 2)
		{
			auto it = senators.end();
			it--;
			int num = it->first - 1;
			char c = it->second;
			res.push_back(c);

			senators.erase(it);
			if(num > 0) senators.insert(make_pair(num, c));
		}

		int sz = res.size();

		cout << "Case #" << t << ":";
		for(int i = 0; i < sz; i++) cout << " " << res[i];

		auto it = senators.begin();
		int num1 = it->first;
		char c1 = it->second;
		it++;
		int num2 = it->first;
		char c2 = it->second;

		for(int i = 0; i < abs(num2 - num1); i++)
		{
			if(num1 > num2) cout << " " << c1;
			else cout << " " << c2;
		}

		for(int i = 0; i < min(num1, num2); i++) cout << " " << c1 << c2;

		cout << endl;
	}

	return 0;
}