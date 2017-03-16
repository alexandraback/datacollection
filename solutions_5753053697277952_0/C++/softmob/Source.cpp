#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;

void solve(int num_test)
{
	int n;
	cin >> n;
	vector<int> p(n);
	map<int, int> q;
	multiset<pair<int, int> > w;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
		q[i] += p[i];
	}
	int mx = 1000*1000*1000;
	for (auto & x : q)
	{
		w.insert({ x.second, x.first });
		mx = min(mx, x.second);
	}
	cout << "Case #" << num_test << ": ";
	while (!w.empty())
	{
		auto it = --w.end();
		if (it->first <= mx)
			break;
		cout << char('A' + it->second) << " ";
		auto r = *it;
		w.erase(it);
		--r.first;
		if (r.first > 0)
			w.insert(r);
	}
	while (w.size() > 2)
	{
		auto it = --w.end();
		for (int i = 0; i < it->first; ++i)
		{
			cout << char('A' + it->second) << " ";
		}
		w.erase(it);
	}
	string str;
	str += char('A' + w.begin()->second);
	w.erase(w.begin());
	str += char('A' + w.begin()->second);
	for (int i = 0; i < mx; ++i)
	{
		cout << str << " ";
	}
	cout << endl;
}

int main(void)
{
	ios::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		solve(i+1);
	}
	return 0;
}