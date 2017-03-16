#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
#include <math.h>
#include <map>
#include <string>
#include <deque>
#define LL long long int
#define double long double
using namespace std;

void solve(int t)
{
	int i,j,k,n;
	vector <string> S, bone;
	string s, help;
	cin>>n;
	for (i=0; i<n; i++)
	{
		cin >> s;
		S.push_back(s);
		help = s[0];
		for (j=1; j<s.size(); j++)
		{
			if (s[j] != s[j-1])
				help += s[j];
		}
		bone.push_back(help);
	}
	cout << "Case #" << t << ": ";
	for (i=1; i<n; i++)
	{
		if (bone[i]!=bone[0])
		{
			cout<<"Fegla Won"<<endl;
			return;
		}
	}
	string our = bone[0];
	int res = 0;
	for (i=0; i<our.size(); i++)
	{
		vector <int> help;
		int kol;
		for (j=0; j<n; j++)
		{
			kol = 0;
			while (S[j].size() && S[j][0]==our[i])
			{
				kol++;
				S[j].erase(0,1);
			}
			help.push_back(kol);
		}
		int ans = 1000000;
		for (j=1; j<=100; j++)
		{
			int sum = 0;
			for (k=0; k<n; k++) sum += abs(j-help[k]);
			ans = min(ans, sum);
		}
		res += ans;
	}
	cout<<res<<endl;
}

int main()
{
	freopen("A-large.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i,t;
	cin>>t;
	for (i=1; i<=t; i++)
		solve(i);
	return 0;
}