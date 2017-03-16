#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <windows.h>

using namespace std;

void solve(int index)
{
	int N;
	cin >> N;
	vector<string> s(N);
	vector<int> it(N, 0);
	int maxlen = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> s[i];
		maxlen = max<int>(maxlen, s[i].size());
	}
	cout << "Case #" << index + 1 << ": ";
	bool cont = true;
	int result = 0;
	while (cont)
	{
		if (it[0] == s[0].size())
		{
			for (int i = 0; i < N; ++i)
			{
				if (it[i] != s[i].size())
				{
					result = -1;
					break;
				}
			}
			break;
		}
		vector<int> cnt(N, 0);
		char c = s[0][it[0]];
		for (int i = 0; i < N; ++i)
		{
			while (it[i] < s[i].size() && s[i][it[i]] == c)
			{
				++it[i];
				++cnt[i];
			}
		}
		int result1 =  N * maxlen;
		for (int i = 0; i < N; ++i)
		{
			int result2 = 0;
			if (cnt[i] == 0)
			{
				result = -1;
				break;
			}
			for (int j = 0; j < N; ++j)
			{
				result2 += abs(cnt[i] - cnt[j]);
			}
			result1 = min<int>(result1, result2);
		}
		if (result == -1)
		{
			break;
		}
		result += result1;
	}
	if (result == -1)
	{
		cout << "Fegla Won";
	}
	else
	{
		cout << result;
	}
	cout << endl;
}

int main(int argc, char **argv)
{
	if (argc == 2 && string(argv[1]) == "-d")
	{
		cout << "Sleep for 15 seconds" << endl;
		Sleep(15 * 1000);
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		solve(i);
	}
	return 0;
}