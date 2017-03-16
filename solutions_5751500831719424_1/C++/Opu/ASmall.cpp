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

int N;
vector<string> v;

int solve(vector<int> &cnt)
{
    int ret = (1<<30);
    sort(cnt.begin(),cnt.end());

    for(int i = cnt[0];i<=cnt[cnt.size()-1];++i)
    {
        int sum = 0;
        for(int j = 0;j<cnt.size();++j) sum += abs(i-cnt[j]);
        ret = min(ret,sum);
    }
    return ret;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    int caseCnt = INPT_INT;

    for(int cNo = 1;cNo<=caseCnt;++cNo)
    {
        v.clear();
        N = INPT_INT;

        for(int i = 0;i<N;++i)
        {
            char buf[102];
            scanf("%s",buf);
            v.push_back(buf);
        }

        vector<string> unique;

        for(int i = 0;i<v.size();++i)
        {
            unique.push_back("");
            for(int j = 0;j<v[i].size();++j)
            {
                if(!j) unique[i] += v[i][j];
                else
                {
                    if(v[i][j] != v[i][j-1]) unique[i] += v[i][j];
                }
            }
        }

        printf("Case #%d: ",cNo);

        bool fail = false;
        for(int i = 1;i<v.size();++i) if(unique[i] != unique[0])
        {
            fail  = true; break;
        }

        if(fail) puts("Fegla Won");
        else
        {
            vector<int> id;
            for(int i = 0;i<v.size();++i) id.push_back(0);

            int res = 0;
            string str = unique[0];

            for(int k = 0;k<str.size();++k)
            {
                vector<int> cnt;
                for(int i = 0;i<v.size();++i)
                {
                    cnt.push_back(0);
                    while( id[i] < v[i].size() && v[i][ id[i] ] == str[k] )
                    {
                        ++id[i];
                        ++cnt[i];
                    }
                }
                res += solve(cnt);
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
