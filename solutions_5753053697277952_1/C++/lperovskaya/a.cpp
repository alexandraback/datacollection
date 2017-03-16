#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
	int tests;
	cin  >> tests;
	vector < pair <int,char> > p;
	int N;
	for (int i = 0; i < tests; i++)
	{
		cin >> N;
		p.clear();
		p.resize(N);
		for (int j = 0; j < N; j++)
		{
			cin >> p[j].first;
			p[j].second = 'A'+j;
		}
		sort (p.rbegin(),p.rend());
		cout << "Case #" << i+1 <<": ";
		while (p[0].first != p[1].first)
		{
			cout << p[0].second << " ";
			p[0].first --;
		}
		for (int j = N-1; j > 1; j--)
		{
			while (p[j].first != 0)
			{
				cout << p[j].second << " ";
				p[j].first --;
			}
		}
		while (p[0].first != 0)
		{
			cout << p[0].second << p[1].second << " "; 
			p[0].first --;
			p[1].first --;
		}
//		cout << "Case #" << i + 1 <<": INSOMNIA\n";
               cout << "\n";
	}
}