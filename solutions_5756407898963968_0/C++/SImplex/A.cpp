#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <set>
using namespace std;

#define forn(i,n) for(int i = 0; i < (int)n; ++i)
#define _mp(a,b) make_pair(a,b)
#define _pb(x) push_back(x)
#define mins(a,b) a = min(a,b)
#define maxs(a,b) a = max(a,b)



int main() {
    ios_base::sync_with_stdio(false);
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T = 0;
    cin >> T;
    int const maxl = 16;
    int const maxn = 4;
    forn(Case,T)
    {
        vector<bool> mask(maxl,true);
        int n = 0;
        forn(tmp,2){
        cin >> n;
        --n;
        forn(i,maxn)
        {
            bool curFlag = false;
            if (i == n)
                curFlag = true;
            forn(i, maxl/maxn)
            {
                int tmp = 0;
                cin >> tmp;
                --tmp;
                mask[tmp] = mask[tmp] & curFlag;
            }
        }
        }
        int count_ans = 0;
        int ans = -1;
        forn(i,maxl)
            if (mask[i])
            {
                ++count_ans;
                ans = i+1;
            }
        cout << "Case #" << Case + 1 << ": ";
        if (count_ans == 0)
            cout << "Volunteer cheated!\n";
        if (count_ans == 1)
            cout << ans << "\n";
        if (count_ans >= 2)
            cout << "Bad magician!\n";
    }
    return 0;
}
