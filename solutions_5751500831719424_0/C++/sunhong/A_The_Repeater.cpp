#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN=110;
string word[MAXN];
vector<int> v[MAXN];

bool isValid(int N)
{
    for (int i=1;i<N;i++)
    {
        if (word[i].compare(word[0])!=0) return false;
    }
    return true;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A_small_output.txt","w",stdout);
    int T, N;
    char s[110];
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++)
    {
        scanf("%d",&N);
        for (int i=0;i<N;i++)
        {
            v[i].clear();
            scanf("%s",s);
            word[i] = s[0];
            int L = strlen(s);
            int counter = 1;
            int M = 1;
            for (int j=1;j<L;j++)
            {
                if (s[j]==word[i][M-1])
                {
                    counter++;
                }else{
                    word[i] += s[j];
                    M++;
                    v[i].push_back(counter);
                    counter = 1;
                }
            }
            v[i].push_back(counter);
        }
        if (!isValid(N))
        {
            printf("Case #%d: Fegla Won\n",cases);
            continue;
        }
        int result = 0;
        for (int i=0;i<v[0].size();i++)
        {
            int minc = 1000000000;
            int maxc = -1;
            for (int j=0;j<N;j++)
            {
                minc = min(minc,v[j][i]);
                maxc = max(maxc,v[j][i]);
            }
            int minAction = 1000000000;
            for (int j=minc;j<=maxc;j++)
            {
                int sum = 0;
                for (int k=0;k<N;k++)
                {
                    int t = v[k][i];
                    sum += abs(j-t);
                }
                minAction = min(minAction, sum);
            }
            result += minAction;
        }
        printf("Case #%d: %d\n",cases,result);
    }
    return 0;
}
