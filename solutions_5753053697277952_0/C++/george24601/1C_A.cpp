#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

typedef unsigned long long UL;
typedef long long LL;
#define LP(i, a, b) for (int i = int(a); i < int(b); i++)
#define LPE(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef pair<int, int> PII;
typedef vector<vector<PII> > WAL;
typedef vector<vector<int> > SAL;
#define INF 2000000000
#define Ep 1e-9

/*
 at each step, we can go either
 1 from max, 2 from max, or 1 from max and 1 from 2nd max

 consider only 2, wlog, number is sorted according to party
 => have to go C one by one
 3 parts

 while (maxParty < half) {


 }

 claim: suppose there is no majority, removing one each from the max 2 will not create new majority
 total size -= 2, so # required to be majority - 1, but max 2 each reduced 1 as well, which is < # required
 If there is one more that was of same #, then total > 3N +1, can't be majorying
 If nothing was of some #, they are no bigger than reduced one, so majority maintained

 order by pair <-n, i>


 while(true){
 sort(pair array)
 if(top is 0, we can done)
 remove one form first
 try removing second

 }

 */

int const MaxSize = 27;

int main() {
	//freopen("/Users/georgeli/A_1.in", "r", stdin);
	freopen("/Users/georgeli/Downloads/A-small-attempt0.in", "r", stdin);
	freopen("/Users/georgeli/A_small.out", "w", stdout);

	int T;
	scanf("%d", &T);

	int N;
	vector<PII> nums;

	LPE(cn, 1, T)
	{
		scanf("%d", &N);

		LP(i, 0, N)
		{
			int num;
			scanf("%d", &num);

			nums.push_back(PII(-num, i));
		}

		printf("Case #%d:", cn);

		int remaining = N;

		while (true) {
			sort(nums.begin(), nums.end());

			if (nums[0].first == 0)
				break;

			nums[0].first++;
			printf(" %c", nums[0].second + 'A');

			if(0 == nums[0].first)
				remaining--;

			assert(nums[1].first < 0);

			if(2 == remaining && nums[1].first == -1)
				continue; //waiting till next round

			nums[1].first++;
			printf("%c", nums[1].second + 'A');

			if(0 == nums[1].first)
				remaining--;
		}

		printf("\n");
	}

	return 0;
}
