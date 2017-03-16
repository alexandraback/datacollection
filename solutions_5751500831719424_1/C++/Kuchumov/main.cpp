#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

const int N = 200;

int n;
vector<pair<int, char> > gr[N];

vector<pair<int, char> > get_gr()
{
 	string str;
 	cin >> str;

 	char cur_char = str[0];
 	int cur_cnt = 1;
 	vector<pair<int, char> > res;

 	for (int i = 1; i < (int)str.length(); i++)
 	{
 	 	if (cur_char != str[i])
 	 	{
 	 	 	res.push_back(make_pair(cur_cnt, cur_char));
 	 	 	cur_char = str[i];
 	 	 	cur_cnt = 0;
 	 	}

 	 	cur_cnt++;
 	}

 	res.push_back(make_pair(cur_cnt, cur_char));
 	
 	return res;
}

int get_steps(vector<int> list)
{
 	int best = (int)1e9;
 	for (int i = 0; i < (int)list.size(); i++)
 	{
 		int cur = 0;
 	 	int x = list[i];
 	 	for (int j = 0; j < (int)list.size(); j++)
 	 		cur += abs(list[j] - x);
 	 	best = min(best, cur);
 	}

 	return best;
}

int solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		gr[i] = get_gr();

	for (int i = 1; i < n; i++)
		if (gr[i].size() != gr[0].size())
			return -1;
			                               /*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (int)gr[i].size(); j++)
			cout << gr[i][j].first << " " << gr[i][j].second << endl;
	 	cout << "-----------" << endl;
	}                                    */

   	int ans = 0;
	for (int i = 0; i < (int)gr[0].size(); i++)
	{
		for (int j = 1; j < n; j++)
			if (gr[j][i].second != gr[0][i].second)
				return -1;

		vector<int> list;
		for (int j = 0; j < n; j++)
			list.push_back(gr[j][i].first);
		ans += get_steps(list);	
	}	

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int it = 0; it < t; it++)
	{
		int ans = solve();
		if (ans == -1)
			printf("Case #%d: Fegla Won\n", it + 1);
		else
			printf("Case #%d: %d\n", it + 1, ans);
	}

 	return 0;
}