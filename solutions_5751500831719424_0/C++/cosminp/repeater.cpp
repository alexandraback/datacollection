#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

const int MAX_SIZE 	= 101;
const int MAX_LEN   = 100;


string solve(string *s, int N)
{
	ostringstream 	out;
	int 			begin[MAX_SIZE];
	int 			count[MAX_SIZE];
	int 			res = 0;
	int 			finished = 0;

	memset(begin, 0, sizeof(begin));
	while (finished == 0)
	{
		char 	c = s[0][begin[0]];
		int 	start = 0;
		int 	best  = 1000000000;

		memset(count, 0, sizeof(count));
		for (int i = 0; i < N; i++)
		{
			if (s[i][begin[i]] == c) start++;
			for (; (begin[i] < s[i].size()) && (s[i][begin[i]] == c); begin[i]++, count[i]++);
			if (begin[i] == s[i].size()) finished++;
		}

		if (start != N) return string("Fegla Won");

		for (int len = 1; len <= 100; len++)
		{
			int nop = 0;
			for (int i = 0; i < N; i++)
			{
				nop += abs(len - count[i]);
			}
			best = min(best, nop);
		}
		res += best;
	}

	if (finished != N)
		out << "Fegla Won";
	else
		out << res;

	return string(out.str());
}


int main()
{
	ifstream 	f("in.txt");
	ofstream 	g("out.txt");
	int 		T, N;
	string 		s[MAX_SIZE];

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> N;
		for (int i = 0; i < N; i++)
			f >> s[i];

		g << "Case #" << test << ": " << solve(s, N) << endl;
	}

	return 0;
}
