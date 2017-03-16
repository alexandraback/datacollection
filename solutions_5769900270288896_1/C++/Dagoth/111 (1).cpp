#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
using namespace std;

int mx(int a)
{
    return max(a, 0ll);
}

signed main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    freopen("B-large (1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    int fix = 0;
    while(T--)
    {
        fix++;
       int r, c, n;
       cin >> r >> c >> n;
       if(c%2 == 1 && r%2 == 0)
        swap(r, c);
       int chess1 = 0, chess2 = 0;
       vector<vector<int> > br1(r, vector<int>(c, 0));
       vector<vector<int> > br2(r, vector<int>(c, 0));
       vector<int> bst1, bst2;
       for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
       {
           if((i + j)%2)
            br1[i][j] = 1, chess1++;
           else
            br2[i][j] = 1, chess2++;
       }

       if(n <= max(chess1, chess2))
       {
           cout << "Case #" << fix << ": " << 0 << '\n';
           continue;
       }

       for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(br1[i][j] == 0){
                    int mudak = 0ll;
                    if(i > 0)
                        mudak++;
                    if(i < r - 1)
                        mudak++;
                    if(j > 0)
                        mudak++;
                    if(j < c - 1)
                        mudak++;
                    bst1.push_back(mudak);
                }

        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                if(br2[i][j] == 0){
                    int mudak = 0;
                    if(i > 0)
                        mudak++;
                    if(i < r - 1)
                        mudak++;
                    if(j > 0)
                        mudak++;
                    if(j < c - 1)
                        mudak++;
                    bst2.push_back(mudak);
                }

            sort(all(bst1));
            sort(all(bst2));
            vector<int> pf1(bst1.size(), 0);
            vector<int> pf2(bst2.size(), 0);
            pf1[0] = bst1[0];
            pf2[0] = bst2[0];
            for(int i = 1; i < bst1.size(); i++)
                pf1[i] = pf1[i - 1] + bst1[i];
              for(int i = 1; i < bst2.size(); i++)
                pf2[i] = pf2[i - 1] + bst2[i];
                int res1 = pf1[n - chess1 - 1];
                int res2 = pf2[n - chess2 - 1];
                cout << "Case #" << fix << ": " << min(res1, res2) << '\n';
    }
    return 0;
}
