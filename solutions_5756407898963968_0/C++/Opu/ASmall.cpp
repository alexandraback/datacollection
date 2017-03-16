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
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        int row1 = INPT_INT - 1, mat1[4][4];

        for(int i = 0;i<4;++i) for(int j = 0;j<4;++j)
        {
            mat1[i][j] = INPT_INT;
        }

        int row2 = INPT_INT - 1, mat2[4][4];

        for(int i = 0;i<4;++i) for(int j = 0;j<4;++j)
        {
            mat2[i][j] = INPT_INT;
        }

        int match_count = 0, res;

        for(int i = 0;i<4;++i) for(int j = 0;j<4;++j)
        {
            if(mat1[row1][i]==mat2[row2][j])
            {
                ++match_count;
                res = mat1[row1][i];
            }
        }

        printf("Case #%d: ",ca);

        if(match_count == 1) printf("%d\n",res);
        else if(match_count) puts("Bad magician!");
        else puts("Volunteer cheated!");
    }
    return 0;
}
