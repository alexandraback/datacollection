#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define INF 999999999
using namespace std;

int MN(int a, int b)
{
    if (a < b) return a;
    return b;
}
int MX(int a, int b)
{
    if (a > b) return a;
    return b;
}
int myabs(int num)
{
    if (num < 0) return -num;
    return num;
}

int n;
vector<string> in, simple;
string hpr;
vector<int> cool;

int pass[102];

int main ()
{
    int i, j, ind;
    int nd;
    int s1, s2;
    int br1, br2;
    int ans;

    int N;
    bool bad;

    scanf("%d", &N);
    for (int t=1; t<=N; t++)
    {
        printf("Case #%d: ", t);

        memset(pass, 0, sizeof(pass));
        in.clear();
        simple.clear();
        ans=0;

        scanf("%d", &n);
        for (i=1; i<=n; i++)
        {
            cin>>hpr;
            in.push_back(hpr);
        }

        for (i=0; i<in.size(); i++)
        {
            hpr = "";
            for (j=0; j<in[i].size(); j++)
            {
                hpr += in[i][j];
                ind = j;

                while (j+1<in[i].size() && in[i][j+1] == in[i][ind])
                {
                    j++;
                }
            }

            simple.push_back(hpr);
        }

        bad = false;
        for (i=0; i+1<simple.size(); i++)
        {
            if (simple[i] != simple[i+1])
            {
                printf("Fegla Won\n");

                bad = true;
                break;
            }
        }

        if (bad)
        {
            continue;
        }

        for (i=0; i<simple[0].size(); i++)
        {
            cool.clear();

            for (j=0; j<in.size(); j++)
            {
                for (ind=pass[j]; ind<in[j].size(); ind++)
                {
                    if (in[j][ind] == simple[0][i]) break;
                }

                nd = ind;
                while (nd+1 < in[j].size() && in[j][nd+1] == simple[0][i])
                {
                    nd++;
                }

                cool.push_back(nd-ind+1);

                pass[j] = nd+1;
            }

            sort(cool.begin(), cool.end());

            ind = (cool.size()+1)/2-1;
            s1=0;
            s2=0;
            br1=0;
            br2=0;

            for (j=0; j<ind; j++)
            {
                br1++;
                s1 += cool[j];
            }
            for (j=ind+1; j<cool.size(); j++)
            {
                br2++;
                s2 += cool[j];
            }

            ans += br1*cool[ind] - s1;
            ans += s2 - br2*cool[ind];

        }

        printf("%d\n", ans);
    }
    return 0;
}
