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
        vector<int> s1, s2;

        int w; cin >> w;
        for(int i = 1; i <= 4; ++i)
            for(int j = 1; j <= 4; ++j)
            {
                int x; cin >> x;
                if(w == i) s1.push_back(x);
            }

        cin >> w;
        for(int i = 1; i <= 4; ++i)
            for(int j = 1; j <= 4; ++j)
            {
                int x; cin >> x;
                if(w == i) s2.push_back(x);
            }

        int ct = 0, ret;
        for(int x : s1)
            for(int y : s2)
                if(x == y)
                    ++ct, ret = y;

		cout << "Case #" << tt << ": ";
		
		if(ct == 0) cout << "Volunteer cheated!";
		else if(ct == 1) cout << ret;
		else cout << "Bad magician!";
		
		if(tt < t) puts("");
    }
    return 0;
}