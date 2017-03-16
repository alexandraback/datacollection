#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;

int a[30];
int ans[26005][2];

int main()
{
    int i, j, n, m, cnt, cas = 1;
    int T;
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while( T -- ){
        scanf("%d", &n);
        for( i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
        memset( ans, 0, sizeof(ans) );
        int fl = 0, max1 = -1, maxid = -1;
        cnt = 0;
        while( !fl ){
            fl = 1;
            int sum = 0;
            max1 = maxid = -1;
            for( i = 1; i <= n; i ++ ){
                if( a[i] > max1 ){
                    max1 = a[i];
                    maxid = i;
                }
                sum += a[i];
            }
            a[maxid] --;sum --;
            int id = maxid;
            max1 = maxid = -1;
            for( i = 1; i <= n; i ++ ){
                if( a[i] > max1 ){
                    max1 = a[i];
                    maxid = i;
                }
            }
            if( max1 > sum/2 ){
                ans[cnt][0] = id;
                ans[cnt][1] = maxid;
                a[maxid] -- ;
                cnt ++;
            }
            else{
                ans[cnt][0] = id;
                cnt ++;
            }
            for( i = 1; i <= n; i ++ ){
                if( a[i] ){ fl = 0; break; }
            }
        }
        printf("Case #%d:", cas++);
        for( i = 0; i < cnt; i ++ ){
            if( ans[i][1] == 0 ){
                printf(" %c", 'A'+ans[i][0]-1);
            }
            else printf(" %c%c", 'A'+ans[i][0]-1, 'A'+ans[i][1]-1);
        }
        puts("");
    }
}
