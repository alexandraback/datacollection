#define f first
#define s second
#define INF 2000000000
#define LNF 8000000000000000000
#define mp make_pair
#define ll long long int
#define BL for(int K = 1; K <= T; K++)
#define db double

#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

char str[110][110];
vector<pair<char,int> > inp[110];
int cal[110];

int abs(int x)
{
    return (x < 0)? -x: x;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T,n,i,j,k;

    scanf("%d",&T);

    BL
    {
        scanf("%d",&n);

        for(i = 0; i < n; i++)
        {
            scanf("%s",str[i]);
            inp[i].clear();
        }

        for(i = 0; i < n; i++)
        {
            inp[i].push_back(mp(str[i][0],1));

            k = strlen(str[i]);

            for(j = 1; j < k; j++)
            {
                if(str[i][j] != str[i][j - 1])
                {
                    inp[i].push_back(mp(str[i][j],1));
                } else {
                    inp[i].back().s++;
                }
            }
        }

        for(i = 1; i < n; i++)
        {
            if(inp[i].size() != inp[0].size())
            {
                printf("Case #%d: Fegla Won\n",K);
                break;
            } else {
                for(j = 0; j < inp[i].size(); j++)
                {
                    if(inp[i][j].f != inp[0][j].f)
                    {
                        printf("Case #%d: Fegla Won\n",K);
                        goto out;
                    }
                }
            }
        }

        out:

        if(i == n)
        {
            k = 0;

            for(i = 0; i < inp[0].size(); i++)
            {
                for(j = 0; j < n; j++)
                {
                    cal[j] = inp[j][i].s;
                }

                nth_element(cal,cal + n / 2,cal + n);

                for(j = 0; j < n; j++)
                {
                    k += abs(cal[n / 2] - inp[j][i].s);
                }
            }

            printf("Case #%d: %d\n",K,k);
        }
    }
}
