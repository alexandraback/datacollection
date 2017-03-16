// This file was compiled using clang-503.0.40
// clang++ -o run.bin -std=c++11 task.cxx
// ./run.bin < data.in > data.out

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>

# include <algorithm>
# include <vector>
# include <map>
# include <set>
# include <queue>
# include <deque>
# include <stack>
# include <bitset>

# include <cstdio>
# include <cstdlib>
# include <ctime>
# include <climits>
# include <limits>
# include <cstring>
# include <cmath>

using namespace std;

string clean_str(string str)
{
	string out = string();
	out += str[0];
	
	for(int i=1; i<str.size(); ++i)
	{
		if (str[i-1] != str[i]) out += str[i];
	}
	
	return out;
}

int main()
{
	int T; cin >> T;
	for(int T_=1; T_<=T; ++T_)
	{
		int N; cin >> N;
		string s1, s2; cin >> s1 >> s2;
		
		if (clean_str(s1) != clean_str(s2)) {
			printf("Case #%d: Fegla Won\n", T_);
		}
		else 
		{
			s1 += '0', s2 += '0';
			
			int count = 0;
			for(int left=0, right = 0; left < s1.size(); )
			{
				if (s1[left] == s2[right]) 
				{
					++left;
					++right;
				}
				else 
				{
					count += 1;
					if (s1[left-1] == s1[left]) ++left;
					else if (s2[right-1] == s2[right]) ++right;
					else cerr << "!!!!!! UNEXPECTD !!!!!!!" << endl;
				}
			}
			
			printf("Case #%d: %d\n", T_, count);
		}
		
	}
	return 0;
}