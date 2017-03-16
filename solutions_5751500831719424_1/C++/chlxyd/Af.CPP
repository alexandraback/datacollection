/*
 * Author:  chlxyd
 * Created Time:  2014/5/4 0:06:59
 * File Name: A.CPP
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clrs( x , y ) memset( x , y , sizeof(x) )
int n , T ; 
char s[110][110] ;
vector<char> v[110] ;
vector<int> num[110] ;
void did( int i ) {
    v[i].clear() ;
    num[i].clear() ;
    rep( j , strlen(s[i]) ) {
        if ( j == 0 || s[i][j] != s[i][j-1] ) {
            v[i].push_back(s[i][j]) ;
            num[i].push_back(1) ;
        }
        else {
            num[i][num[i].size()-1] ++ ;
        }
    }
}
int cal( vector<int> now ) {
    int ret = 100000000 ;
    rep( i , now.size() ) {
        int ans = 0 ;
        rep( j , now.size() )
            ans += abs(now[j]-now[i]) ;
        ret = min( ret , ans ) ;
    }
    return ret ;
}
int solve() {
    vector<int> now ;
    int ret = 0 ;
    rep( j , v[1].size() ) {
        now.clear() ;
        now.push_back(num[1][j]) ;
        repf( i , 2 , n )  {
            if ( v[i].size() != v[1].size() || v[i][j] != v[1][j] ) {
                return -1 ;
            }  
            else now.push_back(num[i][j]) ;
        }
        ret += cal(now) ;
    } 
    return ret ;
}
int main(){
    //freopen("AA.out","w",stdout) ;
    scanf("%d" , &T ) ;
    repf( t , 1 , T ) {
        scanf("%d" , &n );
        repf( i , 1 , n ) 
            scanf("%s" , s[i] ) ;
        //puts(s[1]);
        //if (s[1][0] == 'g' && s[1][1] == 'z' && s[1][2] == 't' ) puts("this") ;
        repf( i , 1 , n ) did(i) ;
        printf("Case #%d: " , t ) ;
        int ret = solve() ;
        if ( ret == -1 ) puts("Fegla Won") ;
        else printf("%d\n" , ret ) ;
    }
}

