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
	int cnt = 0;
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
		std::string str1, str2;
		fin >> str1;
		fin >> str2;

		std::string s1, s2;
		std::vector<int> freq1, freq2;
		theRepeaterHelper(str1, s1, freq1);
		theRepeaterHelper(str2, s2, freq2);		
		
		fout << "Case #" << t << ": ";

		if (s1 != s2)
			fout << "Fegla Won\n";
		else
		{
			int cnt = 0;
			for (int i = 0; i < freq1.size(); ++i)
				cnt += std::abs(freq1[i] - freq2[i]);

			fout << cnt << "\n";
		}
	}

	fin.close();
	fout.close();
}

int main()
{
	theRepeater("A-small-attempt0.in");
	return 0;
}
