#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define sz size

using namespace std;
typedef long long L;
typedef double D;
typedef vector<L> vi;
typedef vector<vi> vvi;
typedef pair<L,L> ii;


int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, -1, 0, 1};

int n, r, c;
int mp[20][20];
#define OK(i, j) ((i) >= 0 && (i) < r && (j) >= 0 && (j) < c)

int bt(int i, int j)
{
    int ret;
    if(i == r)
    {
        ret = 0;
        int amt = 0;
        for(int i = 0; i < r; ++i)
        {
            for(int j = 0; j < c; ++j) if(mp[i][j])
            {
                ++amt;
                for(int k = 0; k < 4; ++k)
                {
                    if(OK(i + di[k], j + dj[k])
                        && mp[i + di[k]][j + dj[k]]) ++ret;
                }
            }
        }
        if(amt != n) return 1000;
    }
    else
    {
        int ni, nj;
        if(j + 1 == c)
        {
            ni = i +1;
            nj = 0;
        }
        else
        {
            ni = i;
            nj = j + 1;
        }
        mp[i][j] = 1;
        ret = bt(ni, nj);
        mp[i][j] = 0; 
        ret = min(ret, bt(ni, nj));
        
    }

    return ret;
}

void solve(void)
{
    cin >> r >> c >> n;

//    for(int i = 0; i < r; ++i)
//    {
//        for(int j = 0; j < c; ++j)
//        {
//            mp[i][j] = 0;
//            for(int k = 0; k < 4; ++k)
//            {
//                if(OK(i + di[k], j + dj[k])) ++mp[i][j];
//            }
//        }
//    }

    memset(mp, 0, sizeof mp);
    cout << bt(0,0)/2 << '\n';;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T;
    cin >> T;

    for(int caso = 1; caso <= T; ++caso)
    {
        cout << "Case #" << caso << ": ";
        solve();
    }
}
