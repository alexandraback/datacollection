#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    for(int tt = 1; tt <= t; ++tt)
    {
        cerr << "Executing Case #" << tt << "\n";
        cout << "Case #" << tt << ": ";

        int n; cin >> n;
        string a[n], b[n];

        bool can = true;
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];

            b[i] = "";
            char c = '#';
            for(int j = 0; j < int(a[i].size()); ++j)
                if(c != a[i][j])
                {
                    c = a[i][j];
                    b[i] += c;
                }

            if(b[i] != b[0])
            {
                puts("Fegla Won");
                can = false;
                break;
            }
        }
        if(!can) continue;

        string s = b[0];
        int cur[n];
        memset(cur, 0, sizeof(cur));

        int ret = 0;
        for(int i = 0; i < int(s.size()); ++i)
        {
            int ct[n];
            memset(ct, 0, sizeof(ct));
            for(int j = 0; j < n; ++j)
                while(cur[j] < int(a[j].size()) and a[j][cur[j]] == s[i])
                    ++cur[j], ++ct[j];

            sort(ct, ct + n);

            int ans = 0x7fffffff;
            for(int fin = ct[0]; fin <= ct[n-1]; ++fin)
            {
                int sum = 0;
                for(int j = 0; j < n; ++j)
                    sum += abs(ct[j] - fin);
                ans = min(ans, sum);
            }
            ret += ans;
        }

        cout << ret << "\n";
    }
    return 0;
}