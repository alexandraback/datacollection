#include <bits/stdc++.h>

#define ll long long
#define __(x) cout << #x << " : " << x << endl;
#define out(a, i, n) for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

#define INOUT
#define TIME	

using namespace std;

template<typename U, typename V>
ostream &operator<<(ostream &s, const pair<U, V> &x)
{
	s << "(" << x.first << ", " << x.second << ")";
	return s;
}

template<typename U>
ostream &operator<<(ostream &s, const vector<U> &v)
{
	s << "[";
	bool was = false;
	for (auto it : v)
	{
		if (was) 
		{
			s << ", ";
		}
		was = true;
		s << it;
	}
	s << "]";
	return s;
}

template<typename U>
ostream &operator<<(ostream &s, const set<U> &x)
{
	s << "{";
	bool was = false;
	for (auto it : x)
	{
		if (was)
		{
			s << ", " << endl;
		}
		was = true;
		s << it;
	}
	s << "}";
	return s;
}

template<typename U, typename V>
ostream &operator<<(ostream &s, const map<U, V> &m)
{
	s << "{";
	bool was = false;
	for (auto it : m)
	{
		if (was)
		{
			s << ", " << endl;
		}
		was = true;
		s << it.first << ": " << it.second;
	}
	s << "}";
	return s;
}

void print(int test, int ans)
{
	cout << "Case #" << test << ": " << ans << endl;
	//printf("Case #%d: %d\n", test, ans);
}

int main()
{
#ifdef INOUT
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	
	int tests;
	cin >> tests;
	ll ans = 0;
	for (int test = 1; test <= tests; test++)
	{
		int n;
		cin >> n;
		int all = 0;
		priority_queue < pair <int, int> > q;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			q.push(mp(x, i));
			all += x;
		}
		cout << "Case #" << test << ": ";
		while (!q.empty())
		{
			if (q.size() == 1)
			{
				cout << (char) ('A' + q.top().second);
				if (q.top().first > 1)
				{
					cout << (char) ('A' + q.top().second);
				}
				break;
			}
			pair <int, int> it = q.top();
			q.pop();
			if (2 * (it.first - 1) <= all - 1 && q.top().first * 2 <= all - 1)
			{
				it.first--;
				if (it.first > 0)
					q.push(it);
				all--;
				cout << (char) ('A' + it.second) << " ";
			}
			else if (it.first > 1 && 2 * (it.first - 2) <= all - 2 && 2 * q.top().first <= all - 2)
			{
				it.first -= 2;
				all -= 2;
				if (it.first > 0)
					q.push(it);
				cout << (char) ('A' + it.second) << (char) ('A' + it.second) << " ";
			}
			else
			{
				cout << (char) ('A' + it.second) << (char) ('A' + q.top().second) << " ";
				it.first--;
				pair <int, int> it2 = q.top();
				q.pop();
				it2.first--;
				if (it.first > 0)
					q.push(it);
				if (it2.first > 0)
					q.push(it2);
				all -= 2;
			}
		}
		cout << endl;
	}

#ifdef TIME
	cerr << (double) clock() / CLOCKS_PER_SEC;
#endif 
	return 0;
}
