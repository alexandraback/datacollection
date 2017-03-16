
#define PROBLEM_NAME "A"
#define PROBLEM_SMALL_INPUT "-small-attempt1"
#define PROBLEM_LARGE_INPUT "-large"

struct charinfo
{
	char ch;
	int freq;

	charinfo() : ch(0), freq(0) {}
};

typedef vector<charinfo> strinfo;

int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in", PROBLEM_NAME PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in");
	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in", PROBLEM_NAME PROBLEM_LARGE_INPUT ".out.txt");

	int T;
	fin >> T;
	for (int cases=1; cases<=T; ++cases)
	{
		int N;
		fin >> N;

		vector<strinfo> v(N);

		for (int i=0; i<N; ++i)
		{
			string str;
			fin >> str;
			char ch_last = 0;
			int cnt_curr = 0;
			for (size_t j=0; j<str.length(); ++j)
			{
				char ch = str[j];
				if (ch == ch_last)
				{
					cnt_curr++;
				}
				else if (ch_last == 0)
				{
					ch_last = ch;
					cnt_curr = 1;
				}
				else
				{
					charinfo chinfo;
					chinfo.ch = ch_last;
					chinfo.freq = cnt_curr;
					v[i].push_back(chinfo);
					ch_last = ch;
					cnt_curr = 1;
				}
			}
			charinfo chinfo;
			chinfo.ch = ch_last;
			chinfo.freq = cnt_curr;
			v[i].push_back(chinfo);
		}

		// check if "Fegla Won"
		strinfo& firstinfo = v[0];
		size_t firstinfo_size = firstinfo.size();
		bool felga_won = false;
		for (int i=1; i<N && !felga_won; ++i)
		{
			strinfo& currinfo = v[i];
			if (currinfo.size() != firstinfo_size)
			{
				fout << "Case #" << cases << ": Fegla Won" << endl;
				felga_won = true;
				break;
			}

			for (size_t j=0; j<firstinfo_size; ++j)
			{
				if (currinfo[j].ch != firstinfo[j].ch)
				{
					fout << "Case #" << cases << ": Fegla Won" << endl;
					felga_won = true;
					break;
				}
			}
		}

		if (felga_won)
			continue;

		vector<int> median;

		for (size_t j=0; j<firstinfo_size; ++j)
		{
			vector<int> freqs;
			for (int i=0; i<N; ++i)
			{
				freqs.push_back(v[i][j].freq);
			}
			std::sort(freqs.begin(), freqs.end());
			if (firstinfo_size % 2 == 0)
			{
				int f = freqs[N/2];
				median.push_back(f);
			}
			else
			{
				int f = freqs[N/2];
				median.push_back(f);
			}
		}

#define myabs(a, b)			((a)>(b) ? ((a)-(b)) : ((b)-(a)))

		int moves = 0;
		for (int i=0; i<N; ++i)
		{
			for (size_t j=0; j<firstinfo_size; ++j)
			{
				moves += myabs(median[j], v[i][j].freq);
			}
		}

		fout << "Case #" << cases << ": " << moves << endl;
	}

	return 0;
}
