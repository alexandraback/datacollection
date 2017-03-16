#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 210

int main()
{
    int t;
    int i,j;
    scanf("%d",&t);
    for(int ccnt=1; ccnt<=t; ++ccnt)
    {
        char s[MAX][MAX];
        int n[MAX][MAX];
        int len;
        for(i=0; i<MAX; ++i)
            for(j=0; j<MAX; ++j)
                n[i][j] = 0;

        int N;

        scanf("%d",&N);

        for(i=0; i<N; ++i)
        {
            char c, prev = 0;
            scanf(" ");
            for(j=-1; scanf("%c",&c)>0 && c>='a' && c<= 'z'; n[j][i]++)
                if(c != prev)
                    s[i][++j]=prev=c;
        }

        for(i=1; i<N; ++i)
        {
            for(j=0; n[j][i] && n[j][0]; ++j)
                if(s[0][j] != s[i][j])
                    break;
            if(n[j][i] || n[j][0]) break;
        }
        printf("Case #%d: ", ccnt);
        if(i<N)
        {
            printf("Fegla Won\n");
            continue;
        }
        for(len=0; n[len][0]; ++len);
        for(i=0; i<len; ++i)
            sort(n[i], n[i]+N);

        int res = 0;

        for(i=0; i<len; ++i)
            for(j=0; j<N; ++j)
                res += abs(n[i][j]-n[i][N/2]);
        printf("%d\n", res);
    }
    return 0;
}
