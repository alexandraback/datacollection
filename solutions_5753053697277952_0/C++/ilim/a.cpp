#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n, T;
    vector< pair<int, int> > ppl;
    scanf("%d", &T);
    for(int t=1; t <= T; ++t)
    {
        int left = 0;
        scanf("%d", &n);
        for(int i=0; i < n; ++i)
        {
            int tmp;
            scanf("%d", &tmp);
            ppl.push_back(make_pair(tmp, 'A' + i));
            left += tmp;
        }
        
        printf("Case #%d:", t);
        while(left)
        {
            sort(ppl.rbegin(), ppl.rend());
            string evacuated = "";
            evacuated.push_back(ppl[0].second);
            ppl[0].first--;
            left--;
            for(int i=0; i < ppl.size(); ++i)
            {
                if(ppl[i].first * 2 > left)
                {
                    // same party member should be evacuated
                    evacuated.push_back(ppl[i].second);
                    ppl[i].first--;
                    left--;
                    break;
                }
            }
            printf(" %s", evacuated.c_str());
        }
        printf("\n");
        ppl.clear();
    }

    return 0;
}
