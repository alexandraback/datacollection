#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define forr(i,a,b) for(int i = (a); i <= (b); ++i)

using namespace std;

bool check(const vector<string>& vs)
{
    string s = vs[0];
    s.erase( unique(s.begin(), s.end()), s.end());
    string s0 = s;
    
    rep(i,vs.size())
    {
        s = vs[i];   
        s.erase( unique(s.begin(), s.end()), s.end());
        if (s != s0)
            return false;
    }
    return true;
}

int solve(const vector<string>& vs)
{
    vector<int> ss(vs.size()), is(vs.size());
    rep(i,vs.size())
    {
        int oi = 0, ni = oi;
        while (ni < vs[i].size() && vs[i][oi] == vs[i][ni])
            ++ni;
        
        ss[i] = ni;
        is[i] = ni;
    }
    int ans = 0;
    
    for(;;)
    {
        sort(ss.begin(), ss.end());
        int p = ss[ss.size() / 2];
        rep(i,ss.size())
            ans += abs(ss[i] - p);   
        
        rep(i,vs.size())
        {
            int oi = is[i], ni = oi;
            if (oi == vs[i].size())
                return ans;
                
            while (ni < vs[i].size() && vs[i][oi] == vs[i][ni])
                ++ni;
            
            ss[i] = ni - oi;
            is[i] = ni;
        }   
    }   
    return ans;
}

int main()
{
    freopen("out.txt", "w", stdout);
    freopen("inA.txt", "r", stdin);
    int T;
    cin >> T;
    int n;
    vector<string> vs;
    forr(tc,1,T)
    {
        cin >> n;
        vs.resize(n);
        rep(i,n)
        {
            cin >> vs[i];
        }   
            
        int ans = check(vs);
        if (ans)
            cout << "Case #" << tc << ": " << solve(vs) << "\n";            
        else
            cout << "Case #" << tc << ": " << "Fegla Won" << "\n";            
    }
    
    return 0;   
}
