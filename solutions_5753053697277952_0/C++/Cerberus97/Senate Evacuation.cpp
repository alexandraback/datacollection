//#include <iostream>
#include <fstream>
#include <set>

#define cin in
#define cout out

using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");

typedef pair <int, int> pr;

int main()
{
	int T, n, p[26];
	char letters[27];

	for (int i = 0; i < 26; ++i)
		letters[i] = 'A' + i;

	cin >> T;

	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		cin >> n;

		set <pr, greater <pr> > q;
		pr p1, p2;

		for (int i = 0; i < n; ++i)
		{
			cin >> p[i];
			q.insert(make_pair(p[i], i));
		}

		while (!q.empty())
		{
			if (q.size() == 2)
			{
				p1 = *(q.begin());
				q.erase(q.begin());
				p2 = *(q.begin());
				q.erase(q.begin());

				if (p1.first > p2.first)
				{
					p1.first--;
					cout << letters[p1.second] << ' ';

					q.insert(p1);
					q.insert(p2);
				}

				else
				{
					p1.first--;
					p2.first--;
					cout << letters[p1.second] << letters[p2.second] << ' ';

					if (p1.first != 0)
					{
						q.insert(p1);
						q.insert(p2);
					}
				}
			}

			else if (q.begin()->first == q.rbegin()->first)
			{
				if (q.begin()->first == 1 and q.size() % 2 != 0)
				{
					cout << letters[q.begin()->second] << ' ';
					q.erase(q.begin());
				}

				else
				{
					p1 = *(q.begin());
					q.erase(q.begin());
					p2 = *(q.begin());
					q.erase(q.begin());

					cout << letters[p1.second] << letters[p2.second] << ' ';

					p1.first--;
					p2.first--;

					if (p1.first != 0)
						q.insert(p1);

					if (p2.second != 0)
						q.insert(p2);
				}
			}

			else
			{
				p1 = *(q.begin());
				q.erase(q.begin());

				p1.first--;
				cout << letters[p1.second] << ' ';

				q.insert(p1);
			}
		}

		cout << '\n';
	}
}