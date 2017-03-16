#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct cmp
{
	bool operator()(pair<int, char> a, pair<int, char> b)
	{
		return a.first < b.first;
	}
};

int main()
{
	ifstream f("A-large.in", std::ios::in);
	int t;
	f >> t;
	string s;
	getline(f, s);
	for (int i = 0; i < t; i++)
	{
		int n;
		f >> n; getline(f, s);
		priority_queue < pair<int, char>, deque<pair<int, char>>, cmp> p;
		deque<int> d;
		map<char, int> m;
		for (int i = 0; i < n; i++)
		{
			int c; f >> c;
			p.push(make_pair(c, 'A' + i));			
		//	m.insert(make_pair('A' + i, c));
		}
		cout << "Case #" << i + 1 << ": ";
	
		while (!p.empty())
		{
			if (p.size() == 2)
			{
				auto k = p.top(); p.pop(); auto l = p.top(); p.pop();
				if (k.first == l.first) {
					cout << k.second << l.second << ' ';
					k.first--; l.first--;
					if (k.first != 0)
						p.push(k);
					if (l.first != 0)
						p.push(l);
				}
				else
				{
					cout << k.second << ' ';
					k.first--;
					p.push(l); p.push(k);
				}
			}
			else
			{
				auto a = p.top();
				p.pop();
				cout << a.second << ' ';
				a.first--;
				if (a.first != 0)
					p.push(a);
			}
		}
		cout << endl;
	}
	return 0;
}