#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <string.h>
#define ull unsigned long long
#define ll long long
using namespace std;

int r,c,n;
int ok( int x, int y )
{
    return x>=0 && y>=0 && x < r && y < c;
}

    int g[100][100];
    int d[2][2] = { 0,1,1,0 };


int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b-small.out","w",stdout);
    int t;
    scanf("%d",&t);
    for( int C = 0;C < t; ++C )
    {

        cin>>r>>c>>n;
        int ans = r * c * 2;
        for( int i = 0; i < ( 1 << (r*c) ); ++i )
        {
            memset(g,0,sizeof(g));
            int num = 0;
            for( int j = 0; ( 1 << j ) <=i; ++j )
            {
                if( ( 1 << j ) & i )
                {
                    int xr = j /c;
                    int rc = j % c;
                    g[xr][rc] = 1;
                    ++num;
                }
            }
          //  printf("i = %d num = %d\n",i,num);
            if( num != n ) continue;
            int ret = 0;
            for( int j = 0; j < r; ++ j )
            {
                for( int k = 0; k < c; ++k )
                {
                    if( g[j][k] == 0 ) continue;
                    for( int l = 0; l < 2; ++l )
                    {
                        int x = j + d[l][0];
                        int y = k + d[l][1];
                        if( ok (x,y) )
                        {
                            if( g[x][y] ) ret++;
                        }
                       // printf("x = %d y = %d ret = %d\n",x,y,ret);
                    }
                }
            }
          //  printf("i = %d ret = %d\n",i,ret);
            ans = min( ans, ret );
        }
        printf("Case #%d: %d\n",C+1,ans);
    }
}
