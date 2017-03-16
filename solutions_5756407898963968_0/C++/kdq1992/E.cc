#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define ll long long
using namespace std;

#define N 111111

int a[10][10] , b[10][10] ;
int main() {
    freopen("A-small-attempt2.in" , "r" , stdin) ;
    freopen("A-small-attempt2.out" , "w" , stdout) ;
    int t ;cin >> t ;int ca = 0 ;

    while(t -- ) {
        int x , y ;

        cin >> x ;x -- ;
        for (int i = 0 ; i < 4 ; i ++ ) for (int j = 0 ; j < 4 ; j ++ ) cin >> a[i][j] ;
        cin >> y ;y -- ;
        for (int i = 0 ; i < 4 ; i ++ ) for (int j = 0 ; j < 4 ; j ++ ) cin >> b[i][j] ;int ans = 0 ;
        int fk = -1 ;
        for (int i = 0 ; i < 4 ; i ++ ) for (int j = 0 ; j < 4 ; j ++ ) if(a[x][i] == b[y][j]) ans ++ , fk = a[x][i] ;
        printf("Case #%d: " , ++ ca) ;
        if(ans >= 2) puts("Bad magician!") ;
        else if(ans == 0) puts("Volunteer cheated!") ;
        else cout << fk << endl;
    }
    return 0 ;
}
