#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

int main()
{
	//freopen("A-large.in" , "r" , stdin);
	freopen("A-small-attempt0.in" , "r" , stdin);
	//freopen("A-large.out" , "w" , stdout);
    freopen("A-small-attempt0.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int row1 , row2;
        int i , j;
        int a[4][4] , b[4][4];
        scanf("%d" , &row1);
        for (i = 0; i < 4; i ++)
            for (j = 0; j < 4; j ++)
                scanf("%d" , &a[i][j]);
        scanf("%d" , &row2);
        for (i = 0; i < 4; i ++)
            for (j = 0; j < 4; j ++)
                scanf("%d" , &b[i][j]);
        int t[17] = {0};
        for (i = 0; i < 4; i ++)
        {
            t[a[row1-1][i]] ++;
            t[b[row2-1][i]] ++;
        }
        int num = 0 , ans = -1;
        for (i = 1; i <= 16; i ++)
        {
            if (t[i] == 2) {ans = i; num ++;}
        }
        if (num == 1 && ans != -1) printf("%d\n" , ans);
        else if (num == 0) printf("Volunteer cheated!\n");
        else printf("Bad magician!\n");
    }
    return 0;
}