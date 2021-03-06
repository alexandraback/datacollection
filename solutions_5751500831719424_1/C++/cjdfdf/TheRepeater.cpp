#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
#include <iomanip>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h> 
#include <limits.h>
#include <locale.h> 
#include <math.h> 
#include <setjmp.h>
#include <signal.h> 
#include <stdarg.h> 
#include <stddef.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>

void theRepeaterHelper(const std::string& str, std::string& s, std::vector<int>& freq)
{
	int cnt = 1;
	s.push_back(str[0]);
	for (int i = 1; i < str.size(); ++i)
	{
		if (str[i] != str[i - 1])
		{
			s.push_back(str[i]);
			freq.push_back(cnt);
			cnt = 1;
		}
		else
			++cnt;
	}

	freq.push_back(cnt);
}


void theRepeater(const char* filename)
{
	std::ifstream fin;
	fin.open(filename);
	std::ofstream fout;
	std::string str = filename;
	str = str.substr(0, str.size() - 3) + ".out";
	fout.open(str.c_str());
	int T;
	fin >> T;

	for (int t = 1; t <= T; ++t)
	{
		int N;
		fin >> N;

		fout << "Case #" << t << ": ";

		std::string str;
		std::vector<std::string> vs(N);
		for (int i = 0; i < N; ++i)
		{
			fin >> str;
			vs[i] = str;
		}

		std::vector<std::string> v_s(N);
		std::vector<std::vector<int> > v_freq(N);
		bool flag = true;
		for (int i = 0; i < N; ++i)
		{
			theRepeaterHelper(vs[i], v_s[i], v_freq[i]);
			if (v_s[i] != v_s[0])
			{
				flag = false;
				break;
			}
		}

		if (!flag)
			fout << "Fegla Won\n";
		else
		{
			int cnt = 0;
			int len = static_cast<int>(v_s[0].size());
			for (int i = 0; i < len; ++i)
			{
				std::vector<int> tmp;
				for (int j = 0; j < N; ++j)
					tmp.push_back(v_freq[j][i]);

				std::sort(tmp.begin(), tmp.end());
				if (N % 2 == 1)
				{
					for (int j = 0; j < N; ++j)
						cnt += std::abs(tmp[j] - tmp[N / 2]);
				}
				else
				{
					int a = 0;
					int b = 0;
					for (int j = 0; j < N; ++j)
						a += std::abs(tmp[j] - tmp[N / 2 - 1]);

					for (int j = 0; j < N; ++j)
						b += std::abs(tmp[j] - tmp[N / 2]);

					cnt += std::min(a, b);
				}
			}

			fout << cnt << "\n";
		}		
	}

	fin.close();
	fout.close();
}

int main()
{
	theRepeater("A-large.in");
	return 0;
}
