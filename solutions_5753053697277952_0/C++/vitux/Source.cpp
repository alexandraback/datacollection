#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define lol long long
using namespace std;

string filename = "A-small-attempt1.in";
ifstream in(filename);
ofstream out(filename + "_out.txt");

#define cin in
#define cout out

pair<int, int> pop_one(priority_queue<pair<int, int> > & q, int sc)
{
	if (q.size() == 2 && sc)
	{
		vector<pair<int, int> > t;
		for (int i = 0; i < 2; ++i)
		{
			t.push_back(q.top());
			q.pop();
		}
		q.push(t[0]);
		q.push(t[1]);
		if (t[0].first == t[1].first && t[0].first == 1)
			return make_pair(-1, -1);
	}
	if (q.empty())
		return make_pair(-1, -1);
	pair<int, int> r = q.top();
	q.pop();
	if (r.first - 1)
		q.push(make_pair(r.first - 1, r.second));
	return r;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		cout << "Case #" << i + 1 << ": ";
		priority_queue<pair<int, int> > q;
		for (int i = 0; i < n; ++i)
		{
			int a;
			cin >> a;
			q.push(make_pair(a, i));
		}
		while (!q.empty())
		{

			pair<int, int> u = pop_one(q, 0);
			pair<int, int> y = pop_one(q, 1);
			if (y.first != -1)
				cout << char('A' + u.second) << char('A' + y.second) << " ";
			else
				cout << char('A' + u.second) << " ";
		}
		cout << endl;
	}
	return 0;
}
