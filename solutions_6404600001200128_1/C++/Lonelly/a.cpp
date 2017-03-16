#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void solve(int index)
{
	int N;
	cin >> N;
	vector<int> m(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> m[i];
	}
	int answer1 = 0;
	int answer2 = 0;
	double speed = 0;
	for (int i = 1; i < N; ++i)
	{
		if (m[i] < m[i - 1])
		{
			answer1 += m[i - 1] - m[i];
			//speed = max(speed, (m[i - 1] - m[i]) / 10 + (((m[i - 1] - m[i]) % 10 > 0) ? 1 : 0));
			speed = max(speed, m[i - 1] - m[i]);
		}
	}
	//cout << speed << " ";
	for (int i = 1; i < N; ++i)
	{
		answer2 += min(speed, m[i - 1]);
	}
	cout << "Case #" << index + 1 << ": ";
	cout << answer1 << " " << answer2;
	cout << endl;
}

int main(int argc, char **argv)
{
#ifdef _WIN32
	if (argc == 2 && string(argv[1]) == "-d")
	{
		cout << "Sleep for 10 seconds" << endl;
		Sleep(10 * 1000);
	}
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		solve(i);
	}
	return 0;
}