#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T& a, T& b) { if (a > b) return a; else return b; }
template <class T> T MIN(T& a, T& b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }

using namespace std;

int main(int argc, char* argv[])
{
	//string inputFileName = "A-small-attempt2.in";
	string inputFileName = "A-large.in";
	ifstream input(inputFileName);
	int T;
	int N[51];
	int sum[51];
	memset(sum, 0, sizeof(sum));
	vector<pair<int, int> > cnt[51];
	input >> T;
	for (int i = 0; i < T; ++i)
	{
		input >> N[i];
		for (int j = 0; j < N[i]; ++j)
		{
			int p;
			input >> p;
			sum[i] += p;
			cnt[i].push_back(make_pair(p, j));
		}
	}
	input.close();
	ofstream output(inputFileName + ".out");
	for (int i = 0; i < T; ++i)
	{
		output << "Case #" << (i + 1) << ":";
		auto curCNT = cnt[i];
		sort(curCNT.begin(), curCNT.end());
		if (sum[i] % 2)
		{
			output << " " << char(curCNT[N[i] - 1].second + 'A');
			--curCNT[N[i] - 1].first;
		}
		sort(curCNT.begin(), curCNT.end());
		while (curCNT[N[i] - 1].first > 0)
		{
			output << " " << char(curCNT[N[i] - 1].second + 'A') << char(curCNT[N[i] - 2].second + 'A');
			--curCNT[N[i] - 1].first;
			--curCNT[N[i] - 2].first;
			sort(curCNT.begin(), curCNT.end());
		}
		output << endl;
	}
	output.close();

	system("pause");
	return 0;
}
