
#define PROBLEM_NAME "A"
#define PROBLEM_SMALL_INPUT "-small-attempt0"
#define PROBLEM_LARGE_INPUT "-large"

#include <set>

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
		int Answer1;
		fin >> Answer1;
		std::set<int> set1;
		for (int i=0; i<4; ++i)
		{
			int a, b, c, d;
			fin >> a >> b >> c >> d;
			if (Answer1-1 == i)
			{
				set1.insert(a);
				set1.insert(b);
				set1.insert(c);
				set1.insert(d);
			}
		}
		int Answer2;
		fin >> Answer2;
		std::set<int> set2;
		for (int i=0; i<4; ++i)
		{
			int a, b, c, d;
			fin >> a >> b >> c >> d;
			if (Answer2-1 == i)
			{
				set2.insert(a);
				set2.insert(b);
				set2.insert(c);
				set2.insert(d);
			}
		}

		std::vector<int> v(10);
		std::vector<int>::iterator it = std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), v.begin());
		v.resize(it-v.begin());

		if (v.size() == 1)
		{
			fout << "Case #" << cases << ": " << v[0] << endl;
		}
		else if (v.size() == 0)
		{
			fout << "Case #" << cases << ": Volunteer cheated!" << endl;
		}
		else
		{
			fout << "Case #" << cases << ": Bad magician!" << endl;
		}
	}

	return 0;
}
