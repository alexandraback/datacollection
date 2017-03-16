#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int map[101][101];
char input[101][101];
char id[101][101];
int num[100];
int n;

int main()
{
    int T;
    scanf("%d", &T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%d", &n);
        memset(map, 0, sizeof(map));
        memset(num, -1, sizeof(num));
        for(int i=0; i<n; ++i)
        {
            scanf("%s", input[i]);
            for(int j=0; input[i][j]; ++j)
            {
                if(j==0 || input[i][j] != input[i][j-1])
                    id[i][++num[i]] = input[i][j];
                ++map[num[i]][i];
            }
        }
        bool flag = true;
        for(int i=1; i<n&&flag; ++i)
            if(num[i]!=num[i-1]) flag = false;
        for(int p=0; p<=num[0]&&flag; ++p)
            for(int i=1; i<n&&flag; ++i)
                if(id[i][p] != id[i-1][p])
                    flag = false;
        printf("Case #%d: ", cas);
        if(flag)
        {
            int ans = 0;
            for(int p=0; p<=num[0]; ++p)
            {
                sort(map[p], map[p]+n);
                for(int i=0, j=n-1; i<j; ++i, --j)
                {
                    ans += map[p][j] - map[p][i];
                }
            }
            printf("%d\n", ans);
        }
        else puts("Fegla Won");
    }
    return 0;
}
