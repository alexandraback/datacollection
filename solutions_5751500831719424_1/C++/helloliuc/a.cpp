#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <stack>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
const double eps = 1e-6;
const int maxint = -1u>>2;

char s[110];

struct NODE
{
    char x;
    int cnt;
};

vector<NODE> node[110];
int n;

bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(node[i].size() != node[1].size())
        {
            return false;
        }
    }
    for(int j=0;j<node[1].size();j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(node[i][j].x != node[1][j].x)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int cas =1 ;cas <= T;cas++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            node[i].clear();
            scanf("%s",s);
            NODE tmp;
            tmp.x = s[0];
            tmp.cnt = 0;
            for(int j=0;s[j];j++)
            {
                if(s[j+1] == 0 || s[j+1] != tmp.x)
                {
                    node[i].push_back(tmp);
                    tmp.x = s[j+1];
                    tmp.cnt = 0;
                }
                else
                {
                    tmp.cnt ++;
                }
            }
        }

        if(!check())
        {
            printf("Case #%d: Fegla Won\n", cas);
            continue;
        }

        int len = node[1].size();
        int ans = 0;
        for(int j=0;j<len;j++)
        {
            int minval = maxint;
            for(int k=1;k<=n;k++)
            {
                int sum = 0;
                for(int i=1;i<=n;i++)
                {
                    int t = node[k][j].cnt - node[i][j].cnt;
                    sum += t > 0? t:-t;
                }
                if(sum < minval)
                {
                    minval = sum;
                }
            }
            ans += minval;
        }

        printf("Case #%d: %d\n",cas, ans);
    }


    return 0;
}

