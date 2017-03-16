#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool check(string const & s, string const & origin)
{
    string templ;
    templ += s[0];
    for(int i = 1; i < s.length(); ++i)
        if(s[i] != templ.back())
            templ += s[i];
    return origin == templ;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
    
	for(int t = 1; t <= T; ++t)
	{
        int n;
        cin >> n;
        vector <string> S(n);
        for(int i = 0; i < n; ++i)
            cin >> S[i];
        
        string templ;
        templ += S[0][0];
        for(int i = 1; i < S[0].length(); ++i)
            if(S[0][i] != templ.back())
                templ += S[0][i];
        
        bool can = true;
        for(int i = 0; i < n; ++i)
            if(!check(S[i], templ))
                can = false;
        
        if(!can)
        {
            cout << "Case #" << t << ": " << "Fegla Won" << endl;
            continue;
        }
        
        vector <int> mins(templ.length(), 1000), maxs(templ.length(), 0);
        vector < vector <int> > V(n);
        
        for(int i = 0; i < n; ++i)
        {
            int cur = 0;
            for(int j = 0; j < templ.length(); ++j)
            {
                int len = 0;
                while(cur < S[i].length() && S[i][cur] == templ[j])
                {
                    ++len; ++cur;
                }
                mins[j] = min(mins[j], len);
                maxs[j] = max(maxs[j], len);
                V[i].push_back(len);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < templ.length(); ++i)
        {
            int tmpans = 100000;
            for(int k = mins[i]; k <= maxs[i]; ++k)
            {
                int curans = 0;
                for(int j = 0; j < n; ++j)
                    curans += abs(V[j][i] - k);
                tmpans = min(curans, tmpans);
            }
            ans += tmpans;
        }
        
        cout << "Case #" << t << ": " << ans << endl;
	}
    
	return 0;
}
