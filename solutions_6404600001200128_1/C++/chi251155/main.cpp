#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <map>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        int N;
        cin >> N;
        vector<int> ms;
        ms.reserve(N);
        for(int i = 0; i < N; ++i)
        {
            int m;
            cin >> m;
            ms.push_back(m);
        }
        int f = 0, s = 0, d = 0;
        for(int i = 0; i < ms.size() - 1; ++i)
        {
            int diff = ms[i] - ms[i + 1];
            if(diff > d) d = diff;
        }
        for(int i = 0; i < ms.size() - 1; ++i)
        {
            f += max(ms[i] - ms[i + 1], 0);
            s += max(min(d, ms[i]), 0);
        }
        cout << "Case #" << t << ": " << f << " " << s << endl;
    }
    return 0;
}
