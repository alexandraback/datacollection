#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

const inline int __GET_INT(){int ret;scanf("%d",&ret);return ret;}
#define INPT_INT __GET_INT()

typedef long long LL;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);

    int total_test = INPT_INT;

    for(int cur_test = 1; cur_test <= total_test; ++cur_test)
    {
        int r = INPT_INT, c = INPT_INT, n = INPT_INT;

        int tot = r*c, res = (1<<30);

        for(int mask = 0; mask < (1<<tot);++mask) if(__builtin_popcount(mask) == n)
        {
            bool grid[20][20] = {0};
            for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j) if(mask & (1<<(i*c+j)))
            {
                grid[i][j] = true;
            }

            int cnt = 0;
            for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j) if(grid[i][j])
            {
                cnt += grid[i+1][j];
                cnt += grid[i][j+1];
            }
            res = min(res,cnt);
        }
        printf("Case #%d: %d\n",cur_test,res);
    }
	return 0;
}
