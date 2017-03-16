#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 105;
const int INFTY = 1000000000;
int N;
string S[MAXN];
int idx[MAXN], temp[MAXN];

int count(int i, char c)
{
	int cnt = 0;
	while (idx[i] < S[i].length() && c == S[i][idx[i]])
	{
		cnt++;
		idx[i]++;
	}
	return cnt;
}

int solve()
{
	int move = 0;
	memset(idx, 0, sizeof(idx));

	while (idx[0] < S[0].length())
	{
		char c = S[0][idx[0]];
		for (int i = 0; i < N; i++)
		{
			temp[i] = count(i, c);
			if (temp[i] == 0)
				return INFTY;	
		}

		int add = INFTY;
		for (int i = 1; i <= 100; i++)
		{
			int cur = 0;
			for (int j = 0; j < N; j++)
				cur += abs(temp[j] - i);
			add = min(add, cur);
		}
		move += add;
	}

	for (int i = 0; i < N; i++)
		if (idx[i] != S[i].length())
			return INFTY;

	return move;
}

int main()
{
	ifstream in ("2014round1BA.in");
	ofstream out ("2014round1BA.out");

	int T;
	in >> T;

	for (int t = 1; t <= T; t++)
	{
		in >> N;
		for (int i = 0; i < N; i++)
			in >> S[i];

		int best = solve();
		if (best != INFTY)
			out << "Case #" << t << ": " << best << "\n";
		else
			out << "Case #" << t << ": Fegla Won\n";
	}

	in.close();
	out.close();
	return 0;
}