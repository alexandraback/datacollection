#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#define INF 999999999
using namespace std;
typedef int lld;

lld MN(lld a, lld b)
{
    if (a < b) return a;
    return b;
}
lld MX(lld a, lld b)
{
    if (a > b) return a;
    return b;
}
lld eabs(lld num)
{
    if (num < 0) return -num;
    return num;
}

lld n;
vector<string> in, simple;
string hpr;
vector<lld> cool;

lld pass[102];

int main ()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    lld i, j, ii, jj, ind;
    lld nd;
    lld s1, s2;
    lld br1, br2;
    lld ans;

    lld tests, t;
    bool bad;

    scanf("%d", &tests);
    for (t=1; t<=tests; t++)
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
                //cout<<simple[i]<<"  vs  "<<simple[i+1]<<endl;
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

               // cout<<in[j][ind]<<"  trqbva da e  "<<simple[0][i]<<endl;

                nd = ind;
                while (nd+1 < in[j].size() && in[j][nd+1] == simple[0][i])
                {
                    nd++;
                }

              /*  if (nd+1 < in[j].size())
                {
                    cout<<in[j]<<endl;
                    cout<<"Ne mojem da dobavim sledvashtoto "<<in[j][nd+1]<<endl;
                }*/

               //if (t == 97)
              //  cout<<"Ima "<<nd-ind+1<<" "<<simple[0][i]<<endl;
                cool.push_back(nd-ind+1);

                pass[j] = nd+1;
            }

            sort(cool.begin(), cool.end());

            ind = (cool.size()+1)/2-1;
            //cout<<"Medianata e ind "<<ind<<" s "<<cool[ind]<<endl;
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

            //cout<<s1<<"  "<<br1<<"," <<s2<<"  "<<br2<<endl;

            ans += br1*cool[ind] - s1;
            ans += s2 - br2*cool[ind];

            //cout<<"Dobavqme "<<br1*cool[ind]-s1<<"  i  "<<s2-br2*cool[ind]<<endl;;
        }

        printf("%d\n", ans);
    }
}
