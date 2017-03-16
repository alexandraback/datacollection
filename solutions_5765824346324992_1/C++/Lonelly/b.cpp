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
	int B, N;
	cin >> B >> N;
	vector<int> M(B);
	for (int i = 0; i < B; ++i)
	{
		cin >> M[i];
	}
	long long i = 0;
	long long j = 1000 * 1000 * 1000;
	j *= 10000;
	while (i < j)
	{
		long long m = (i + j) / 2;
		long long sum = 0;
		for (int k = 0; k < B; ++k)
		{
			sum += m / M[k] + ((m % M[k]) == 0 ? 0 : 1);
		}
		//cout << i << " " << j << " " << m << " " << sum << " " << N << endl;
		if (sum >= N)
		{
			j = m;
		}
		else
		{
			i = m + 1;
		}
	}
	int prev = 0;
	if (i > 0)
	{
		for (int k = 0; k < B; ++k)
		{
			prev += (i - 1) / M[k] + (((i - 1) % M[k]) == 0 ? 0 : 1);
		}
	}
	//cout << i << " " << prev << endl;
	int result = 1;
	for (int k = 0; k < B; ++k)
	{
		//cout << i % M[k] << " " << prev << " " << N << endl;
		if (i == 0 || ((i - 1) % M[k] == 0))
		{
			++prev;
			if (prev >= N)
			{
				result = k + 1;
				break;
			}
		}
	}

	cout << "Case #" << index + 1 << ": " << result;
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