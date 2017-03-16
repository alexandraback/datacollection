#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include "fstream"

#define sz(X) ((int)X.size())
#define FOR(i,x,y) for(int i=x; i<y; ++i)
#define FORE(i,x,y) for(int i=x; i<=y; ++i)


using namespace std;
vector<vector<int> > D;
int R, C, N;
void clearGrid()
{
    FOR(i,0,R) FOR(j,0,C) D[i][j] = 0;
}

bool valid(int i)
{
    int n = 0;
    while(i)
    {
        if(i&1) n++;
        i = i>>1;
    }

    return n == N;
}

void createGrid(int i)
{
    FOR(r, 0, R)
        FOR(c, 0, C)
            if(i & (1<<(r*C + c))) D[r][c] = 1;
}

int test(int r, int c)
{
    int  a = 0;
    if(r-1 >= 0 && D[r-1][c]) a++;
    if(c+1 <  C && D[r][c+1]) a++;

    return a;
}
int check()
{
    int ans = 0;
    FOR(r,0, R)
    {
        FOR(c, 0, C)
        {
            if(D[r][c])
            ans += test(r,c);
        }

    }

    return ans;
}
int main()
{
    ofstream cout ("output.txt");
    ifstream cin ("input.txt");

    int T;
    cin>>T;

    FOR(i,1,T+1)
    {
        int ans = 10000;
        cin>>R>>C>>N;

        D = vector<vector<int>>(R, vector<int>(C,0));

        FORE(i,0,1<<R*C)
        {
            if(valid(i))
            {
                clearGrid();
                createGrid(i);
                ans = min(ans, check());
            }
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }

    return 0;
}
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
