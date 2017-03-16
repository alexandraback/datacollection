#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#define N 30
using namespace std;

int a[N];
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("dataA.out", "w", stdout);

    int t, ys = 0;
    scanf("%d", &t);
    while (t--)
    {
        int n, cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            cnt += a[i];
        }


        int p1 = 0, m1 = 0, p2 = 0, m2 = 0;
        vector<char> ans;
        while (1)
        {
            p1 = -1, m1 = 0, p2 = -1, m2 = 0;
            for (int i = 0; i < n; ++i)
                if (a[i] > m2)
                {
                    if (a[i] > m1)
                    {
                        m2 = m1; p2 = p1;
                        m1 = a[i]; p1 = i;
                    }
                    else
                    {
                        m2 = a[i]; p2 = i;
                    }
                }
            if (m1 == 0) break;
            ans.push_back(' ');
            a[p1]--; ans.push_back('A' + p1);
            cnt--;
            if (m2 * 2 > cnt)
            {
                ans.push_back('A' + p2);
                a[p2]--;
                cnt--;
            }
        }

        printf("Case #%d:", ++ys);
        for (int i = 0; i < ans.size(); ++i)
            printf("%c", ans[i]);
        printf("\n");
    }

    return 0;
}
