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

bool grid[10][10003];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

    int total_test = INPT_INT;

    for(int cur_test = 1; cur_test <= total_test; ++cur_test)
    {
        LL r = INPT_INT, c = INPT_INT, n = INPT_INT;
        LL res = (1LL<<60);

        if(r > c) swap(r,c);

        if(r < 8)
        {
            int _try = 2;
            while(_try--)
            {
                int tmp = n;
                memset(grid,0,sizeof(grid));

                for(int i = 0; i < r; ++i)
                {
                    bool flag = ((i%2)?0:1);
                    if(_try == 1) flag = !flag;

                    for(int j = 0; j < c; ++j)
                    {
                        grid[i][j] = flag;
                        n -= flag;
                        flag = !flag;
                    }
                }
                int dx[] = {0,0,1,-1};
                int dy[] = {-1,1,0,0};

                int val[5] = {0};

                for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j) if(!grid[i][j])
                {
                    int cnt = 0;
                    for(int k = 0; k < 4; ++k)
                    {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x < 0 || y < 0) continue;
                        cnt += grid[x][y];
                    }
                    val[cnt]++;
                }

                int cur_res = 0;
                for(int i = 0; i < 5; ++i)
                {
                    cur_res += min(n,(LL)val[i])*i;
                    n -= min(n,(LL)val[i]);
                }
                res = min(res,(LL)cur_res);
                n = tmp;
            }
        }
        else
        {
            LL cnt = (c/2 + c%2) * (r/2 + r%2) + (c/2) * (r/2);

            if(cnt >= n) res = 0;
            else
            {
                n -= cnt;
                if( (r%2) == 0 || (c%2) == 0 )
                {
                    cnt = 2;
                }

                res = 0;
                res += min(n,cnt)*2;
                n -= min(n,cnt);

                cnt = ((c-2)/2 + c%2) + ((r-2)/2+r%2);
                if(r % 2)
                {
                    cnt += ((c-2)/2 + c%2);
                }
                else cnt += ((c-4)/2 + c%2);

                if(c % 2)
                {
                    cnt += ((r-2)/2 + r%2);
                }
                else cnt += ((r-4)/2 + r%2);

                res += min(n,cnt) * 3;
                n -= min(n,cnt);

                res += (LL)n*4LL;
            }
        }

        printf("Case #%d: %lld\n",cur_test,res);
    }
	return 0;
}
