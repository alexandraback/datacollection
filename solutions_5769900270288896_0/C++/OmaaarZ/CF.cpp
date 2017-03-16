#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#define mod 1000000007
#define M_PI 3.14159265358979323846
using namespace std;
int n, m ;
int ma;
bool visited[16][16];
void solve(int i , int j,int counter,int all)
{
    if(counter ==0)
    {
        ma =min(ma,all);
        return;
    }
    if(i ==n)
    {
        return;
    }
    if(j== m)
    {
        return solve(i+1,0,counter,all);
    }
    int temp = all;
    if(i >0  &&visited[i-1][j] == 1)
        all++;
    if(j>0 &&visited[i][j-1]==1)
        all++;
    visited[i][j]=true;
    solve(i,j+1,counter-1,all);
    visited[i][j]=false;
    solve(i,j+1,counter,temp);

}
int main()
{
   freopen("B-small-attempt0.in","r",stdin);
    freopen("output.in","w",stdout);
    cin.sync_with_stdio(false);
    int t ;
    int tc=1;
    cin >> t;
    //memset(dp,-1,sizeof dp);
    while(t--)
    {
        int need;
        cin >> n >> m>> need;
        ma = INT_MAX;
        memset(visited, 0 , sizeof visited);
        solve(0,0,need,0);
        cout << "Case #" <<tc++ <<": "<<ma <<endl;
    }
    return 0;
}


