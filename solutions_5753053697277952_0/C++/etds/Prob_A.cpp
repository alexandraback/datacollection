
#define PROBLEM_NAME "A"
#define PROBLEM_SMALL_INPUT "-small-attempt1"
#define PROBLEM_LARGE_INPUT "-large"

#include <list>
#include <set>

using namespace std;


bool sorter(const pair<char, int>& a, const pair<char, int>& b)
{
	return a.second > b.second;
}

bool sorter2(const pair<char, int>& a, const pair<char, int>& b)
{
	return a.first < b.first;
}

int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in");
	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in", PROBLEM_NAME PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in", PROBLEM_NAME PROBLEM_LARGE_INPUT ".out.txt");

	int T;
	fin >> T;
	for (int cases=1; cases<=T; ++cases)
	{
		int N;
		fin >> N;

		vector<pair<char, int> > P;

		for (int i=0; i<N; ++i)
		{
			int a;
			fin >> a;
			P.push_back(make_pair('A'+i, a));
		}

		fout << "Case #" << cases << ":";

		while (true)
		{
/*			fout << endl;
			std::sort(P.begin(), P.end(), sorter2);
			int total = 0;
			for (int i=0; i<N; ++i)
			{
				total += P[i].second;
			}
			int falsealarm = false;
			for (int i=0; i<N; ++i)
			{
				fout << P[i].first << ":" << P[i].second << "/" << total << ", ";
				if (static_cast<double>(P[i].second)/static_cast<double>(total) > 0.5)
				{
					falsealarm = true;
				}
			}
			if (falsealarm)
				fout << "***********";
			fout << endl;
*/
			std::sort(P.begin(), P.end(), sorter);
			int Total = 0;
			for (int i=0; i<N; ++i)
			{
				Total += P[i].second;
			}

			if (N >= 3 && P[0].second == 1 && P[1].second == 1 && P[2].second == 1)
			{
				fout << " " << P[0].first;
				P[0].second--;
			}
			else if (P[0].second > 0 && P[1].second > 0)
			{
				fout << " " << P[0].first << P[1].first;
				P[0].second--;
				P[1].second--;
			}
			else if (P[0].second > 0)
			{
				fout << " " << P[0].first;
				P[0].second--;
			}
			else
			{
				fout << endl;
				break;
			}
		}
	}

	return 0;
}
