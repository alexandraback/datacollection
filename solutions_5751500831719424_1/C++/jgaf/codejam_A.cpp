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

using namespace std;
#define MAX 105
#define pii pair<int ,int >
#define mp make_pair
#define pb push_back
struct Data{
    char c;
    int cnt;
    Data( char cc , int cnt2 ) : c( cc ) , cnt( cnt2 ){}
};
int n;
string s[ MAX ];
vector<Data> v[ MAX ];
void convert( int i ){
    for( int j = 0 ; j < s[ i ].length() ; ++j ){
        char c = s[ i ][ j ];
        int jj = j + 1;
        int cnt = 1;
        while( jj < s[ i ].length() && c == s[ i ][ jj ] ){
            jj++; cnt++;
        }
        j = jj - 1;
        v[ i ].push_back( Data(c , cnt ) );
    }
}

int solve(){
    int ans = 0;
    int i = 0;
    for( int ii = 0 ; ii < v[ i ].size() ; ++ii ){
        Data first = v[ i ][ ii ];
        int maxi = first.cnt , mini = first.cnt;
        //int cnt = first.cnt;
        for( int k = i + 1 ; k < n ; ++k ){
            if( v[ k ].size() != v[ i ].size()  )
                return -1;
            Data second = v[ k ][ ii ];
            if( second.c != first.c ){
                return -1;
            }
            //cout<<first.c<<" "<<second.c<<"   "<<first.cnt<<" "<<second.cnt<<endl;
            maxi = max( maxi , second.cnt );
            mini = min( mini , second.cnt );
            //cnt += second.cnt;
        }

        int _min = 1<<30;
        for( int k = mini ; k <= maxi ; ++k ){
            int cost = 0;
            for( int w = 0 ; w < n ; ++w ){
                cost += abs( k - v[ w ][ ii ].cnt );
            }
            _min = min( cost , _min );
        }
        ans += _min;
    }
    return ans;
}

int main(){
    int t, q , i,  j;
    freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d" , &n ) ; ++q ){
        for( i = 0 ; i < n && cin>>s[ i ] ; ++i ){
            v[ i ].clear();
            convert( i );
        }
        printf("Case #%d: " , q  );
        int ans = solve();
        if( ans == -1 )
            puts("Fegla Won");
        else
            printf("%d\n" , ans );
    }
    return 0;
}
