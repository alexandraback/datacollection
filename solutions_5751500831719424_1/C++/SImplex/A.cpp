#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <set>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <map>
using namespace std;

#define forn(i,n) for(int i = 0; i < (int)n; ++i)
#define _mp(a,b) make_pair(a,b)
#define _pb(x) push_back(x)
#define mins(a,b) a = min(a,b)
#define maxs(a,b) a = max(a,b)

int main() {
   ios_base::sync_with_stdio(false);
//    cout << fixed;
//    cout << setprecision(9);
    freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
    int T = 0;
    cin >> T;
    forn(test, T)
    {
        cout << "Case #"<< test+1 << ": ";
        int n = 0;
        cin >> n;
        vector<string> s(n);
        forn(i,n)
        {
            cin >> s[i];
            s[i]._pb(1);
        }

        vector<int> l(n);
        forn(i,n)
            l[i] = s[i].length();
        vector<int> ind(n,0);

        bool exit = false;
        forn(i,n - 1)
            if(s[i][0] != s[i+1][0])
                exit = true;
        if (exit)
        {
            cout << "Fegla Won\n";
            continue;
        }
        int ans = 0;
        while (!exit && ind[0] < l[0] - 1)
        {
            char c = s[0][ind[0]];
            char ne = 0;
            vector<int> tmpAns(n,0);
            forn(i,n)
            {
                int last = ind[i];
                while (s[i][ind[i]] == c)
                    ++ind[i];
                if (ne != 0 && s[i][ind[i]] != ne)
                {
                    exit = true;
                    break;
                }
                ne = s[i][ind[i]];
                tmpAns[i] = ind[i] - last;
               // cerr << "ee " << ind[i] << " " << last << endl;
            }
            sort(tmpAns.begin(), tmpAns.end());
            forn(i,n)
                ans += abs(tmpAns[n/2] - tmpAns[i]);
            if (ne == 1)
            {
                break;
            }
        }
        if (exit)
        {
            cout << "Fegla Won\n";
        }
        else
            cout << ans << "\n";

    }

    return 0;
}
