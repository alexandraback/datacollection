#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <iterator>
#include <functional>
#include <ctime>

using namespace std;

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define make_triple(x,y,z) make_pair((x), make_pair((y),(z)))
#define fr first
#define sc second
#define ts second.first
#define td second.second

typedef long long ll;
typedef unsigned long long ull; 

const long double eps = 1e-9;
const int inf = LONG_MAX;
const ll inf64 = LLONG_MAX;
const long double pi = 3.1415926535897932384626433832795;

#define N 40000

map<int, int> mp;

void doit(int jj)
{
	int k = 0;
	for (int h = 0; h < 4; h++)
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &k);
			if (h == jj - 1)
				mp[k]++;
		}
}

int main()
{
	int n;
	scanf("%d", &n);
	
	freopen("output1","w",stdout);
	
	for (int i = 0; i<n; i++)
	{
		mp.clear();
		int j;
		scanf("%d", &j);
		doit(j);
		scanf("%d", &j);
		doit(j);
		int c = 0;
		int ans;			
		snuke(mp, ii)
			if (ii->second == 2)
				c++, ans = ii->first;
		if (c == 0)
			printf("Case #%d: Volunteer cheated!\n", i+1);
		else
			if (c > 1)
				printf("Case #%d: Bad magician!\n", i+1);
			else
				printf("Case #%d: %d\n", i+1, ans);			
	}
	return 0;	
}