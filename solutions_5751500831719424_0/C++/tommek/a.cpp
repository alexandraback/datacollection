#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> con(string s)
{
	int n = s.size();
	vector<char> v;
	for(int i = 0; i < n; ++ i)
		v.push_back(s[i]);
	return v;
}

string con(vector<char> t)
{
	string v = "";
	for(int i = 0; i < t.size(); ++ i)
		v += t[i];
	return v;
}

void UNIQUE(vector<char> &v)
{
	v.resize(distance(v.begin(), unique(v.begin(),v.end())));
}

void out(vector<int> x)
{
	for(int i = 0; i < x.size(); ++ i)
		cout << x[i] << " ";
	cout << endl;
}

int main()
{
	int q;
	cin >> q;

	for(int test = 1; test <= q; ++ test)
	{
		int n, wyn = 0;
		cin >> n;
		string s[n];
		for(int i = 0; i < n; ++ i)
			cin >> s[i];
		vector<char> v[n];
		for(int i = 0; i < n; ++ i)
		{
			v[i] = con(s[i]);
			UNIQUE(v[i]);
		}
		bool czy = false;
		for(int i = 0; i < n-1; ++ i)
			if(con(v[i]) != con(v[i+1]))
			{
				czy = true;
				break;
			}
		if(czy)
		{
			cout << "Case #"<<test<<": "<<"Fegla Won"<<endl;
			continue;
		}
		vector<int> r[n];
		for(int i = 0; i < n; ++ i)
		{
			int x = s[i].size();
			for(int j = 0; j < x; ++ j)
			{
				int f = 1;
				while(j + 1 < x && s[i][j+1] == s[i][j])
				{
					++ f;
					++ j;
				}
				r[i].push_back(f);
			}	
		}

		for(int i = 0; i < r[0].size(); ++ i)
		{
			int cos = 1e8;
			for(int l = 1; l <= 100; ++ l)
			{	
				int now = 0;
				for(int j = 0; j < n; ++ j)
					now += abs(r[j][i] - l);
				if(now < cos)
					cos = now;
			}
			wyn += cos;
		}

		cout << "Case #"<<test<<": "<<wyn<<endl;
	}

	return 0;
}
