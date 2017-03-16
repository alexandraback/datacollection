#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <list>

using namespace std;

const int MAX = 1e5;
const int INF = 1e9;
const double EPS = 1e-9;

int T;
int main() 
{
    freopen("input.txt", "r", stdin);
    freopen("outpu.txt", "w", stdout);
    cin >> T;
    string strs[101];
    int it[101], crnt[101];
    int cnt;
    for(int Ti = 1; Ti <= T; ++Ti)
    {
        cin >> cnt;
        for(int i = 0; i < cnt; ++i)
        {
            cin >> strs[i];
            it[i] = 0;
        }
        int moves = 0;
        int ln = strs[0].length();
        while(it[0] < ln)
        {
            char c = strs[0][it[0]];
            int mn = 100, mx = 1;
            for(int i = 0; i < cnt; ++i)
            {
                crnt[i] = 0;
                while(it[i] < strs[i].length() && strs[i][it[i]] == c)
                {
                    ++crnt[i];
                    ++it[i];
                }
                if(crnt[i] == 0)
                {
                    moves = -1;
                    break;
                }
                mn = min(mn, crnt[i]);
                mx = max(mx, crnt[i]);
            }
            if(moves == -1)
                break;
            int move = 1000000;
            for(int i = mn; i <= mx; ++i)
            {
                int c_move = 0;
                for(int j = 0; j < cnt; ++j)
                    c_move += abs(crnt[j] - i);
                move = min(c_move, move);
            }
            moves += move;
        }
        for(int i = 0; i < cnt; ++i)
            if(it[i] != strs[i].length())
            {
                moves = -1;
                break;
            }
        
        if(moves < 0)
            cout << "Case #" << Ti << ": Fegla Won\n";
        else
            cout << "Case #" << Ti << ": " << moves << '\n';
    }

    return 0;
}

