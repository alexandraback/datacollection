#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 1

using namespace std;

const int dirRow[2] = {1,0};
const int dirCol[2] = {0,1};

int arr[20];

int findPos(int row,int col, int r,int c)
{
    return row * c + col;
}

int checkSound(int r,int c)
{
    int ret = 0;
    for(int row = 0; row < r; row++)
    {
        for(int col = 0; col < c; col++)
        {
            int pos = findPos(row,col,r,c);
            if(arr[pos] == 0) continue;
            for(int dir = 0; dir < 2; dir++)
            {
                int row2 = row + dirRow[dir];
                int col2 = col + dirCol[dir];
                if(row2 >= r || col2 >= c) continue;    
                int pos2 = findPos(row2,col2,r,c); 
                if(arr[pos2] == 0) continue;
                ret++;                           
            }
        }
    }
    return ret;
}

int solve(int r,int c, int n)
{
    int ret = INF;
    int x = r * c;
    memset(arr,0,sizeof(arr));
    for(int i = x-1; i >= x-n; i--)
    {
       arr[i] = 1; 
    }
    do
    {
        ret = min(checkSound(r,c),ret);
    }
    while(next_permutation(arr,arr+x));
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ca = 1; ca <= t ; ca ++)
    {
        int r,c,n;
        scanf("%d %d %d",&r,&c,&n);    
        int res = solve(r,c,n);
        printf("Case #%d: %d\n",ca,res);
    }
    return 0;
}
