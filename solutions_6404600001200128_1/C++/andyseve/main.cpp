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
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _T;
    cin >> _T;
    for(int T = 0; T < _T; T++){
        cout << "Case #" << T+1 << ": ";
        int n; cin >> n;
        int m[n]; for(int i = 0; i < n; i++) cin >> m[i];
        int ans1 = 0, ans2 = 0;

        for(int i = 1; i < n; i++){
            if(m[i] < m[i-1]) ans1 += m[i-1] - m[i];
        }

        int rate = 0;
        for(int i = 1; i < n; i++){
            if(m[i] < m[i-1]) rate = max(rate, m[i-1] - m[i]);
        }
        for(int i = 0; i < n-1; i++){
            ans2 += min(m[i], rate);
        }
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
