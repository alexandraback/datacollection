#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>
//#include <time.h>
using namespace std;
#define MAX 17
int dp[ MAX ][ (1<<16) + 5 ][ MAX ];
int h , w;
int n;
int bitcount( int n ){
    int cnt = 0;
    while( n ){
        n = n & ( n - 1 );
        cnt++;
    }
    return cnt;
}

int solve( int row , int mask , int neighbor ){
    //cout<<row<<" "<<mask<<" "<<neighbor<<endl;
    if( neighbor > n )
        return 1<<30;

    if( row == h ){
        if( neighbor == n )
            return 0;
        return 1<<30;
    }

    if( dp[ row ][ mask ][ neighbor ] != -1 )
        return dp[ row ][ mask ][ neighbor ];

    int ans = 1<<30;
    for( int i = 0 ; i < 1<<w ; ++i ){
        int up = (mask & i);
        int sum = bitcount( up );
        int ant = 0;
        for( int j = 31 ; j >= 0; --j ){
            if( i & (1<<j)){
                if( ant == 1 ){
                    sum++;
                }
                ant = 1;
            }else
                ant = 0;
        }
        //cout<<sum<<" "<<neighbor<<" mask "<<mask<<" --  "<<i<<" -- "<<row<<endl;
        ans = min( ans , sum + solve( row + 1 , i , neighbor + bitcount(i) ) );
    }
    return dp[ row ][ mask ][neighbor] = ans;
}

int main() {
    //srand (time(NULL));
    int t;
    scanf("%d", &t) ;
    for( int q = 1 ; q <= t && scanf("%d %d %d" , &h,  &w , &n ) ; ++q ){
        memset( dp , -1 , sizeof( dp ) );
        printf("Case #%d: %d\n", q , solve(0 , 0 , 0) );
    }
    return 0 ;
}
