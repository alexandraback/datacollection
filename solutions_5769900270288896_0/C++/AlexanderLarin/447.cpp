#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

const int MAX = 210000;
const int MAXC = 15;
const int INF = 1e9;
const int MOD = 1000000007;
const double EPS = 1e-11;

int T;
int r, c, n;

int tw, th, four;

int mx()
{
    int odd = r / 2 + (r & 1 ? 1 : 0);
    int even = r / 2;
    
    int codd = c / 2 + (c & 1 ? 1 : 0);
    int ceven = c / 2;
    return odd * codd + even * ceven;
}

int var1()
{
    if((r & 1) && (c & 1))
        tw = 0;
    else 
        tw = 2;
    
    th = (r - 1) / 2;
    th += (c & 1) ? (r - 1) / 2 : (r - 2) / 2;
    int odd = (r & 1) ? 0 : 1;
    int even = (r & 1) ? 2 : 1;
    four = 0;
    
    for(int i = 1; i < c - 1; ++i)
    {
        int curr = (i & 1) ? even : odd;
        th += curr;
        four += (r - curr) / 2;        
    }
    
    //cout << "var1 " << tw << ' ' << th << ' ' << four << endl;
    
    int me = n - mx();
    int out = 0;    
    
    for(;me > 0; --me)
    {
        if(tw > 0)
        {
            out += 2;
            --tw;
        }
        else if(th > 0)
        {
            out += 3;
            --th;
        }    
        else
        {
            out += 4;
            --four;
        }
    }
    
    return out;
}

int var2()
{
    if((r & 1) && (c & 1))
        tw = 4;
    else 
        tw = 2;
    
    th = (r - 2) / 2;
    th += (c & 1) ? (r - 2) / 2 : (r - 1) / 2;
            
    int odd = (r & 1) ? 2 : 1;
    int even = (r & 1) ? 0 : 1;
    four = 0;
    
    for(int i = 1; i < c - 1; ++i)
    {
        int curr = (i & 1) ? even : odd;
        th += curr;
        four += (r - curr) / 2;        
    }
    //cout << "var2 " << tw << ' ' << th << ' ' << four << endl;
    int me = n - mx();
    if((r & 1) && (c & 1))
        me++;
        
    int out = 0;    
    
    for(;me > 0; --me)
    {
        if(tw > 0)
        {
            out += 2;
            --tw;
        }
        else if(th > 0)
        {
            out += 3;
            --th;
        }    
        else
        {
            out += 4;
            --four;
        }
    }
    
    return out;
}

int ifone()
{        
    int codd = c / 2 + (c & 1 ? 1 : 0);
    if(codd >= n)
        return 0;
    int out = (n - codd) * 2;
    if(!(c & 1))
        out -= 1;
    return out;
}

int check()
{
    int x[20][20];
    int mn = INF;
    for(int i = 0; i < (1 << (r * c)); ++i)
    {
        //cout << "lol" << i << endl;
        int s = 0, t = 0;
        for(int j = 0; j < r * c; ++j)
        {
          //  cout << "lol" << s << ' ' << t << endl;
            x[s][t] = (i & (1 << j));            
            ++s;
            if(s >= r)
            {
                s = 0;
                t++;
            }
        }
        //cout << "lol" << i << endl;
        int cnt = 0, ot = 0;
        for(int j = 0; j < c; ++j)
        {
            for(int k = 0; k < r; ++k)
            {
                if(x[k][j])
                {
                    ++ot;
                    if(k < r - 1 && x[k + 1][j])
                        ++cnt;
                    if(j < c - 1 && x[k][j + 1])
                        ++cnt;
                }
            }
            if(ot == n)
                mn = min(cnt, mn);
        }
    }
    return mn;
}

int main()
{
    freopen("./out.txt", "w", stdout);
    cin >> T;
    for(int Ti = 0; Ti < T; ++Ti)
    {
        cin >> r >> c >> n;
        
        if(c < r)
            swap(r, c);
        //cout << check() << ' ';
        if(r == 1 || c == 1)
        {
            cout << "Case #" << Ti + 1 << ": " << ifone() << endl;
            continue;
        }
        
        int m = mx();
        if(n <= m)
        {
            cout << "Case #" << Ti + 1 << ": 0" << endl;
            continue;
        }
        
        int v1 = var1();
        int v2 = var2();
        
        //cout << v1 <<  ": " << v2 << endl;
        int out = min(v1, v2);
        
        cout << "Case #" << Ti + 1 << ": " << out << endl;
    }
}
