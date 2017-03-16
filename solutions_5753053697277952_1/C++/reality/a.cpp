# include <bits/stdc++.h>
using namespace std;
# define x first
# define y second
# define ll long long
# define db long double
# define scn(x) scanf("%I64d",&x)
# define scan(x) scanf("%d",&x)
# define print(x) printf("%d ",x)
# define prnt(x) printf("%I64d ",x);
# define eol printf("\n")
# define IOS ios_base :: sync_with_stdio(0)
int s[505];
int main(void)
{
    ifstream fi("input");
    ofstream fo("output");
    int t;
    fi>>t;
    for (int cs = 1;cs <= t;++cs)
    {
        fo << "Case #" << cs << ": ";
        vector < string > ans;
        int n;
        fi>>n;
        for (int i = 1;i <= n;++i) fi>>s[i];
        int ok = 0;
        for (int i = 1;i <= n;++i) ok += s[i];
        while (ok)
        {
            int mx1 = max_element(s+1,s+1+n) - s;
            int cnt = s[mx1];
            s[mx1] = 0;
            int mx2 = max_element(s+1,s+1+n) - s;
            s[mx1] = cnt;
            --s[mx1];
            --s[mx2];
            ok -= 2;
            int Mx = *max_element(s+1,s+1+n);
            string nw = "";
            if (Mx + Mx > ok)
            {
                ++s[mx2];
                ++ok;
                nw += 'A' - 1 + mx1;
            }
            else
                nw += 'A' - 1 + mx1,nw += 'A' - 1 + mx2;
            ans.push_back(nw);
        }
        for (auto it : ans) fo << it << ' ';
        fo << '\n';
    }
    return 0;
}
