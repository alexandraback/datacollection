#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;


int to[2][2] = {{0, -1}, {-1, 0}};
int dp[16][16];
int result, n, r, c;

void check()
{
    int count = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(dp[i][j])
            {
                for(int k = 0; k < 2; k++)
                {
                    int ii = i + to[k][0];
                    int jj = j + to[k][1];
                    if(ii >= 0 && ii < r && jj >= 0 && jj < c && dp[ii][jj])
                        count++;
                }
            }
        }
    }
    result = min(result, count);
}
void DFS(int i, int count)
{
    if(count == n)
    {
        check();
    }
    else
    {
        for(int j = i; j < r*c; j++)
        {
            dp[j/c][j%c] = 1;
            DFS(j+1, count+1);
            dp[j/c][j%c] = 0;
        }
    }
}
int main() {
    int T;
    cin>>T;
    int case_number = 1;
    while(T--)
    {
        cin>>r>>c>>n;
        result = INT_MAX;
        memset(dp, 0, sizeof(dp));
        DFS(0, 0);
        cout<<"Case #"<<case_number++<<": "<<result<<endl;
    }
}
