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
		
		vector<string> vec(N);
		for(int i=0; i<vec.size(); ++i) cin >> vec[i];
		
		string gold = clean_str(vec[0]);
		bool eq = true;
		for(int i=1; i<vec.size() && eq; ++i)
		{
			eq &= (gold == clean_str(vec[i]));
		}
		
		if (!eq) {
			printf("Case #%d: Fegla Won\n", T_);
		}
		else 
		{	
			for(int i=0; i<vec.size(); ++i) vec[i] += '0';
			
			vector<map<int, int>> cc(gold.size());
			for(int s=0; s<vec.size(); ++s)
			{
				string &str = vec[s];
				for(int g=0, p=0; g<gold.size(); ++g)
				{
					int cnt = 0;
					while(str[p] == gold[g]) ++cnt, ++p;
					cc[g][cnt] += 1;
				}
			}
			
			int count = 0;
			for(int i=0; i<cc.size(); ++i)
			{
				deque<int> up;
				map<int, int> up_mp = cc[i];
				while(up_mp.size() != 1)
				{
					auto left = up_mp.begin();
					up.push_back(left->second);
					up_mp[left->first +1] += left->second;
					up_mp.erase(left->first);
				}
				
				deque<int> down;
				map<int, int> down_mp = cc[i];
				while(down_mp.size() != 1)
				{
					auto right = down_mp.rbegin();
					down.push_front(right->second);
					down_mp[right->first -1] += right->second;
					down_mp.erase(right->first);
				}
				
				for(int k=0; k<up.size(); ++k)
				{
					count += min(up[k], down[k]);
				}
			}
			
			printf("Case #%d: %d\n", T_, count);
		}
		
	}
	return 0;
}