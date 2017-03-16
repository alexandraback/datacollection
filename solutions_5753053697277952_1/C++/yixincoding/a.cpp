#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
// #include <unordered_map>
#include <cstring>
using namespace std;

void find(vector<int> p, int &m1, int &m2)
{
	if (p[m1] < p[m2]) swap(m1, m2);
	for (int i = 2; i < p.size(); i++)
	{
		if (p[i] >= p[m1])
		{
			m2 = m1; 
			m1 = i;
		}
		else
		{
			if (p[i] >= p[m2]) m2 = i;
		}
	}
}

int main()
{
	freopen ("test.in", "r", stdin);
	freopen ("test.out", "w", stdout);
	int T;
	cin >> T;
	for (int TT = 1; TT < T+1; TT++)
	{
		cout << "Case #" << TT << ':' ;
		int n;cin >> n;
		vector<int> p;
		p.clear();
		int total = 0;
		int party = n;
		for (int i = 0; i < n; i++)
		{
			int temp;cin>>temp;
			total += temp;
			p.push_back(temp);
		}
		if (total % 2 == 1) 
		{
			int m1= 0, m2 = 1;
			find(p, m1, m2);
			cout << ' ' << (char)('A' + m1);
			p[m1]--;
			total --;
		}
		for (; total > 0; total -= 2)
		{
			int m1=0, m2=1;
			find(p, m1, m2);
			if (p[m1] - p[m2] > 1)
			{
				cout <<' ' <<  (char)('A'+m1)  << (char)('A'+m1);
				p[m1]-=2;
			}
			else
			{
				cout << ' ' << (char)('A'+m1) << (char)('A' +m2);
				p[m1]--;
				p[m2]--;
			}
		}
		cout << endl;
	}	
}