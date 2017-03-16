#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int neighbors[10000][10000];
bool placed[10000][10000];
int place(int r, int c, int n)
{
    if(n <= (r * c + 1) / 2)
        return 0;
    set< pair<int, pair<int, int> > > s;
    set< pair<int, pair<int, int> > >::iterator it;
    for(int i=max(r, c); i >= 0; --i)
    {
        placed[i][c] == placed[r][i] == false;
        neighbors[i][c] == neighbors[r][i] == 0;
    }
    for(int i=0; i < r; ++i)
    {
        for(int j=0; j < c; ++j)
        {
            if((i + j) % 2)
            {
                neighbors[i][j] = 4 - (i == 0 || i == r-1 ? 1 : 0) - (j == 0 || j == c-1 ? 1 : 0);
                placed[i][j] = false;
                s.insert(make_pair(neighbors[i][j], make_pair(i, j)));
            }
            else
            {
                neighbors[i][j] = 0;
                placed[i][j] = true;
            }
        }
    }

    for(int i=n-(r*c+1)/2; i > 0 ; --i)
    {
        it = s.begin();
        pair<int, pair<int, int> > newElem = *it;
        int p = it->second.first, q = it->second.second;
        s.erase(newElem);
        placed[p][q] = true;
        for(int x=-1; x < 2; ++x)
        {
            for(int y=-1; y < 2; ++y)
            {
                if(abs(x) + abs(y) == 1 && p+x >= 0 && p+x < r && q+y >= 0 && q+y < c &&
                   !placed[p+x][q+y])
                {
                    newElem = make_pair(neighbors[p+x][q+y], make_pair(p+x, q+y));
                    s.erase(newElem);
                    newElem.first = ++neighbors[p+x][q+y];
                    s.insert(newElem);
                }
            }
        }
    }

    int resA = 0;
    for(int i=0; i < r; ++i)
    {
        for(int j=0; j < c; ++j)
        {
            if(placed[i][j])
            {
                for(int x=-1; x < 2; ++x)
                {
                    for(int y=-1; y < 2; ++y)
                    {
                        if(abs(x) + abs(y) == 1 && i+x >= 0 && i+x < r && j+y >= 0 && j+y < c &&
                           placed[i+x][j+y])
                        {
                            resA++;
                        }
                    }
                }
            }
        }
    }
    resA /= 2;

    s.clear();
    for(int i=max(r, c); i >= 0; --i)
    {
        placed[i][c] == placed[r][i] == false;
        neighbors[i][c] == neighbors[r][i] == 0;
    }
    for(int i=0; i < r; ++i)
    {
        for(int j=0; j < c; ++j)
        {
            if((i + j) % 2)
            {
                neighbors[i][j] = 0;
                placed[i][j] = true;
            }
            else
            {
                neighbors[i][j] = 4 - (i == 0 || i == r-1 ? 1 : 0) - (j == 0 || j == c-1 ? 1 : 0);
                placed[i][j] = false;
                s.insert(make_pair(neighbors[i][j], make_pair(i, j)));
            }
        }
    }

    for(int i=n-r*c/2; i > 0; --i)
    {
        it = s.begin();
        pair<int, pair<int, int> > newElem = *it;
        int p = it->second.first, q = it->second.second;
        s.erase(newElem);
        placed[p][q] = true;
        for(int x=-1; x < 2; ++x)
        {
            for(int y=-1; y < 2; ++y)
            {
                if(abs(x) + abs(y) == 1 && p+x >= 0 && p+x < r && q+y >= 0 && q+y < c &&
                   !placed[p+x][q+y])
                {
                    newElem = make_pair(neighbors[p+x][q+y], make_pair(p+x, q+y));
                    s.erase(newElem);
                    newElem.first = ++neighbors[p+x][q+y];
                    s.insert(newElem);
                }
            }
        }
    }
    int resB = 0;
    for(int i=0; i < r; ++i)
    {
        for(int j=0; j < c; ++j)
        {
            if(placed[i][j])
            {
                for(int x=-1; x < 2; ++x)
                {
                    for(int y=-1; y < 2; ++y)
                    {
                        if(abs(x) + abs(y) == 1 && i+x >= 0 && i+x < r && j+y >= 0 && j+y < c &&
                           placed[i+x][j+y])
                        {
                            resB++;
                        }
                    }
                }
            }
        }
    }
    resB /= 2;
    return min(resA, resB);
}

int main()
{
    int t, r, c, n;
    int res;

    cin >> t;
    for(int i=1; i <= t; ++i)
    {
        cin >> r >> c >> n;
        cout << "Case #" << i << ": " << place(r,c,n) << endl;
    }

    return 0;
}
