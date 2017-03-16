#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int N;
char str[105][105];
int sz[105];
char ori[105];
int ind[105];
vector<int> tab;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int T;
    scanf("%d", &T);
    getchar();

    for(int t = 1; t <= T; t++)
    {
        scanf("%d", &N);
        printf("Case #%d: ",t);
        getchar();
        int szo=0;
        int best=0;

        for(int i = 0; i < N; i++)
        {
            ind[i]=0;
            scanf("%s", str[i]);
            sz[i]=strlen(str[i]);
            if(i==0)
            {
                ori[0]=str[0][szo++];
                for(int j = 1; j < sz[i]; j++)
                {
                    if(str[i][j]==str[i][j-1])
                        continue;
                    ori[szo++]=str[i][j];
                }
            }
            //attention à pas oublier check sz
        }

        for(int i = 0; i < N; i++)
        {
            if(str[i][0]!=ori[0])
                goto fail;
            int curr=1;
            for(int j = 1; j < sz[i]; j++)
            {
                if(str[i][j]==str[i][j-1])
                    continue;
                if(ori[curr++]!=str[i][j])
                    goto fail;
            }
            if(curr != szo)
                goto fail;
        }

        for(int i = 0; i < szo; i++)
        {
            for(int j = 0; j < N; j++)
            {
                int cnt=0;
                while(ind[j] < sz[j] && str[j][ind[j]]==ori[i])
                {
                    cnt++;
                    ind[j]++;
                }
                tab.push_back(cnt);
            }
            sort(tab.begin(), tab.end());
            int med=tab[N/2];
            for(int j = 0; j < N; j++)
            {
                best += abs(med-tab[j]);
            }
            tab.clear();
        }

        printf("%d\n", best);
        goto end;

        fail:;

        printf("Fegla Won\n");

        end:;
    }

    return 0;
}
