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

int solve(int n, vector<int> m)
{
    int b = m.size();
    if(n <= b)
        return n;

    long long left = 0;
    long long right = 1000000000000000LL;
    while(left < right){
        long long mid = (left + right) / 2;

        long long cnt = 0;
        for(int i=0; i<b; ++i)
            cnt += mid / m[i] + 1;

        if(cnt < n)
            left = mid + 1;
        else
            right = mid;
    }

    -- left;
    set<pair<long long, int> > s;
    for(int i=0; i<b; ++i){
        n -= left / m[i] + 1;
        s.insert(make_pair((left / m[i] + 1) * m[i], i + 1));
    }

    while(--n > 0)
        s.erase(s.begin());
    return s.begin()->second;
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        int b, n;
        cin >> b >> n;
        vector<int> m(b);
        for(int i=0; i<b; ++i)
            cin >> m[i];
        cout << "Case #" << t << ": " << solve(n, m) << endl;
    }

    return 0;
}