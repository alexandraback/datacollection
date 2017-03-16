#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>

using namespace std;

string arr[100];
int pos[100];

int main (int argc, char const* argv[])
{
	int T;
	scanf("%d",&T);
	
	for (int t=1; t <= T; ++t)
	{
		int n;
		scanf("%d",&n);
		
		for (int i = 0; i < n; i += 1)
		{
			char str[105];
			scanf("%s",str);
			arr[i] = str;
			pos[i] = 0;
			
		}
		
		int total = 0;
		bool valid = true;
		while (pos[0] != (int)arr[0].size())
		{	
			char letter = arr[0][pos[0]];
			
			vector<int> v;
			for (int i = 0; i < n; i += 1)
			{
				int idx = pos[i];
				if (arr[i][idx] != letter)
				{
					valid = false;
					break;
				}
				
				int cc = 0;
				while (idx < (int)arr[i].size() && arr[i][idx] == letter)
				{
					++cc;
					++idx;
				}
				
				if (!cc)
				{
					valid = false;
					break;
				}
				
				v.push_back(cc);
				
				pos[i] = idx;
			}
			
			int cost = 0x3f3f3f3f;
			int vc = v.size();
			for (int j = 0; j < n; j += 1)
			{
				int c = 0;
				for (int i = 0; i < vc; ++i)
				{
					if (v[i] != v[j])
						c += abs(v[i]-v[j]);
				}
				
				cost = min(cost,c);
			}
			
			total += cost;
		}
		
		printf("Case #%d: ",t);
		
		if (valid)
		{
			for (int i = 0; i < n; i += 1)
				valid = valid && (pos[i] == (int)arr[i].size());
		}
		
		if (valid)
			printf("%d\n",total);
		else
			printf("Fegla Won\n");
	}
	
	return 0;
}
