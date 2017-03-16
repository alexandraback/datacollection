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

char ss[105][105];
int countt[105][105] = {0};

void change(char s[] , int x)
{
    int L = strlen(s);
    char c = s[0];
    int num = 1;
    int k = 0;
    for (int i = 1; i < L; i ++)
    {
        if (s[i] != s[i-1])
        {
            ss[x][k] = s[i-1];
            countt[x][k] = num;
            k ++;
            num = 1;
        }
        else num ++;
    }
    ss[x][k] = s[L-1];
    countt[x][k] = num;
    k ++;
    ss[x][k] = 0;
}

int main()
{
	freopen("A-large.in" , "r" , stdin);
	freopen("A-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n;
        scanf("%d" , &n);
        int bad = 0;
        char s[105][200];
        for (int i = 0; i < n; i ++) scanf("%s" , s[i]);
        
        memset(ss , 0 , sizeof(ss));
        memset(countt , 0 , sizeof(countt));
        for (int i = 0; i < n; i ++)
        {
            change(s[i] , i);
        }
        int L0 = strlen(ss[0]);
        for (int i = 1; i < n; i ++)
        {
            int L = strlen(ss[i]);
            if (L0 != L) {bad = 1; break;}
            for (int j = 0; j < L; j ++) if (ss[i][j] != ss[0][j]) {bad = 1; break;}
        }
        if (bad)
        {
            printf("Fegla Won\n");
        }
        else
        {
            int num = 0;
            for (int i = 0; i < L0; i ++)
            {
                int minv = 1 << 30;
                int maxv = 0;
                for (int j = 0; j < n; j ++)
                {
                    minv = min(minv , countt[j][i]);
                    maxv = max(maxv , countt[j][i]);
                }
                int minsum = 1 << 30;
                for (int k = minv; k <= maxv; k ++)
                {
                    int sum = 0;
                    for (int j = 0; j < n; j ++)
                        sum += abs(countt[j][i] - k);
                    minsum = min(minsum , sum);
                }
                num += minsum;
            }
            printf("%d\n" , num);

        }
    }
    return 0;
}