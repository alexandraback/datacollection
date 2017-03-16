#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;
int P[26];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	int testcase;

	string ans;

	scanf("%d", &testcase);
	for (int case_id = 1; case_id <= testcase; case_id++)
	{
		string ans;
		int N;
		vector<int> ret1;
		vector<int> ret2;
		printf("Case #%d: ", case_id);
		cin >> N;
		int total = 0;
		int max = 0;
		int pos = 0;
		for (int i = 0; i < N; i++){
			cin >> P[i];
			total += P[i];
			if (P[i]>max)
			{
				max = P[i];
				pos = i;
			}
		}
		while (total > 0)
		{
			ret1.push_back(pos);
			P[pos]--;
			total--;
			max--;
			for (int i = 0; i < N; i++){
				if (P[i]>max)
				{
					max = P[i];
					pos = i;
				}
			}
			if (max > total / 2)
			{
				ret2.push_back(pos);
				P[pos]--;
				total--;
				max--;
			}
			else
			{
				ret2.push_back(-1);
			}
		}
		
		for (int i = 0; i < ret1.size(); i++)
		{
			printf("%c", ret1[i]+'A');
			if (ret2[i]>=0)
				printf("%c", ret2[i]+'A');
			cout << " ";
		}


		printf("\n");
	}
	return 0;
}

