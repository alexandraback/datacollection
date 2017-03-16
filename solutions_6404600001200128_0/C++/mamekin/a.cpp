#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

int solve1(const vector<int>& a)
{
    int n = a.size();
    int ans = 0;
    for(int i=1; i<n; ++i)
        ans += max(0, a[i-1] - a[i]);
    return ans;
}

int solve2(const vector<int>& a)
{
    int n = a.size();
    int x = 0;
    for(int i=1; i<n; ++i)
        x = max(x, a[i-1] - a[i]);

    int ans = 0;
    for(int i=0; i<n-1; ++i)
        ans += min(a[i], x);
    return ans;
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; ++i)
            cin >> a[i];
        cout << "Case #" << t << ": " << solve1(a) << ' ' << solve2(a) << endl;
    }
}