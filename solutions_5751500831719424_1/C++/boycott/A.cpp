#include <assert.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int step[110][110];
int numG;

string group(int x, string str)
{
	
	//str += "^";
	
	string res = "";
	res += str[0];

	step[x][0] = 1;
	int g = 0;

	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] != res[res.length()-1]) {
			g++;
			step[x][g] = 1;
			res += str[i];
		}
		else 
		{
			step[x][g]++;
		}
	}
	numG = g+1;
	//cout << res << endl;
	return res;
}




int main() {
	int cases;
	cin >> cases;
	for (int t = 1; t <= cases; t++)
	{

		memset(step, sizeof(step), 0);

		int n, sum = 0;
		cin >> n;

		string first;
		cin >> first;

		string comm = group(0, first);
		

		bool flag = true;
		for (int j = 1; j < n; j++) 
		{
			string str;
			cin >> str;
			if (group(j, str) != comm) 
			{
				flag = false;
			}

		}
		if (!flag) {
			printf("Case #%d: Fegla Won\n", t);
			continue;
		}

		for (int i = 0; i < numG; i++) 
		{
			std::vector<int> v;
			for (int j = 0; j < n; j++)
			{
				v.push_back(step[j][i]);
			//	cout << step[j][i] << " "; 
			}
			//cout << endl;
			sort(v.begin(), v.end());
			int mid = v.size() / 2;
			for (int j = 0; j < n; j++)
			{
				sum += abs(v[j] - v[mid]);
			}
		}

		printf("Case #%d: %d\n", t, sum);
	}
	return 0;
}