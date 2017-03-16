#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <vector>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;

int T,R,C,N, M[100][100], sol;

int computeCost()
{
    int cost = 0;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            if(M[i][j])cost = cost + M[i][j+1] + M[i+1][j];
    return cost;
}
int countBits(int X)
{
    int res = 0;
    for(int i = 0; i < 16; i++)
        if(X & (1<<i))
            res = res + 1;
    return res;
}

int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    cin>>T;
    for(int t = 1; t <= T; t++)
    {
        cin>>R>>C>>N;
        sol = 2 * R * C;
        for(int state = 0; state < (1<<(R*C)); state++)
        {
            if(countBits(state) != N)
                continue;
            //printf("%d\n",state);
            for(int i = 0; i <= R; i++)
                for(int j = 0; j <= C; j++)
                    M[i][j] = 0;
            for(int i = 0; i < R; i++)
                for(int j = 0; j < C; j++)
                {
                    if(state & (1<<(i*C + j)))
                        M[i][j]  = 1;
                }
            sol = min(sol, computeCost());
        }
        cout<<"Case #"<<t<<": "<<sol<<"\n";
    }
    return 0;
}
