#include <cstdlib>
#include <fstream>
#include <map>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if (a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }

using namespace std;

int main(int argc, char* argv[])
{
	string inputFileName = "A-small-attempt0.in";
	ifstream input(inputFileName);
	ofstream output(inputFileName + ".out");
	int T, R[2], mat[2][4][4];
	input >> T;
	for (int i = 1; i <= T; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			input >> R[j];
			for (int r = 0; r < 4; ++r)
			{
				for (int c = 0; c < 4; ++c)
				{
					input >> mat[j][r][c];
				}
			}
		}
		map<int, int> cnt;
		for (int j = 0; j < 2; ++j)
		{
			for (int c = 0; c < 4; ++c)
			{
				cnt[mat[j][R[j] - 1][c]] += j % 2 ? -1 : 1;
			}
		}
		int res = -1, zero = 0;
		for (auto it = cnt.begin(); it != cnt.end(); ++it)
		{
			if (it->second == 0)
			{
				++zero;
				if (zero == 1)
				{
					res = it->first;
				}
			}
		}

		output << "Case #" << i << ": ";
		if (zero == 1) output << res << endl;
		else if (zero == 0) output << "Volunteer cheated!\n";
		else output << "Bad magician!\n";
	}

	output.close();
	input.close();

	//system("pause");
	return 0;
}
