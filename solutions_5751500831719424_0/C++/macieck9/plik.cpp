#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

struct dwa
{
	int a;
	char c;
	dwa() {}
	dwa(int m, char z) {a = m, c = z;}
};

vector<dwa> tab[102];
int v[102];

int main()
{
    ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(tab,0,sizeof(tab));
		int n;
		cin >> n;
		string s;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			int x = 1;
			for (int j = 0; j < s.size(); j++)
			{
				if (j == 0) continue;
				if (s[j] == s[j-1]) x++;
				else tab[i].push_back(dwa(x,s[j-1])), x = 1;
			}
			tab[i].push_back(dwa(x,s[s.size()-1]));
		}
		bool b = true;
		for (int i = 1; i < n; i++)
		{
			if (tab[i].size() != tab[0].size()) {b = false; break;}
		}
		cout << "Case #" << t << ": ";
		if (!b) {cout << "Fegla Won\n"; continue;}
		int m = tab[0].size();
		b = true;
		for (int i = 0; i < m and b; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (tab[j][i].c != tab[j-1][i].c) {b = false; break;}
			}
		}
		if (!b) {cout << "Fegla Won\n"; continue;}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) v[tab[j][i].a]++;
			int p = 0;
			int x = 0;
			for (int j = 100; j >= 1; j--)
			{
				x += p;
				p += v[j];
			}
			int l = 0;
			int mn = x;
			for (int j = 1; j <= 100; j++)
			{
				if (j > 1) x -= p;
				if (j > 1) x += l;
				l += v[j];
				p -= v[j];
				mn = min(mn,x);
			}
			ans += mn;
			memset(v,0,sizeof(v));
		}
		cout << ans << "\n";
		memset(tab,0,sizeof(tab));
	}




    return 0;
}
