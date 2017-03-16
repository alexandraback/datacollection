/*
 * Code by Spiromanul
 */

# include "fstream"
# include "cstring"
# include "vector"
# include "queue"
# include "bitset"
# include "algorithm"
# include "map"
# include "unordered_map"
# include "deque"
# include "string"
# include "iomanip"
# include "cmath"
# include "stack"
# include "cassert"

const char IN [ ] =  "input" ;
const char OUT [ ] = "output" ;
const int MAX = 33 ;

# define pb push_back
# define mp make_pair
# define FORN( a , b , c ) for ( int a = b ; a <= c ; ++ a )
# define FORNBACK( a , b , c ) for ( int a = b ; a >= c ; -- a )

using namespace std ;

ifstream cin ( IN ) ;
ofstream cout ( OUT ) ;
int mat [ MAX ] [ MAX ] , R , C ,  cate , n ;
int CET = 1 << 30 ;

inline int inside ( int i , int j )
{
    return i <= R and i >= 1 and j <= C and j >= 1 ;
}
/*
inline void fill ( int i , int j )
{
    if ( inside ( i , j ) == 0 ) return ;
    if ( viz [ i ] [ j ] == 0 and mat [ i ] [ j ] == 1 )
    {
        viz [ i ] [ j ] = 1 ;
        ++ cate ;
        fill ( i + 1 , j ) ;
        fill ( i - 1 , j ) ;
        fill ( i , j + 1 ) ;
        fill ( i , j - 1 ) ;
    }
}

inline void fill_time ( )
{
    aux = 0 ;
    FORN ( i , 1 , R )
        FORN ( j , 1 , C ) {
            mat [ i ] [ j ] = 0 ;
            viz [ i ] [ j ] = 0 ;
        }
    FORN ( i , 1 , R )
        FORN ( j , 1 , C )
            if ( viz [ i ] [ j ] == 0 )
            {
                fill ( i , j ) ;
            }
}*/

int dx [ ] = { - 1 , 0 } ;
int dy [ ] = {  0 , -1 } ;

inline void check ( )
{
    cate = 0 ;
    FORN ( i , 1 , R )
        FORN ( j , 1 , C )
            FORN ( k , 0 , 1 )
                if ( mat [ i ] [ j ] and inside ( i + dx [ k ] , j + dy [ k ] ) and mat [ i + dx [ k ] ] [ j + dy [ k ] ] )
                    ++ cate ;
    CET = min ( CET , cate ) ;
}

inline void bakt ( int catee )
{
    if ( catee == n + 1 )
    {
        //fill_time ( ) ;
        check ( ) ;
        return ;
    }
    else {
        FORN ( i , 1 , R )
            FORN ( j , 1 , C )
            {
                if ( mat [ i ] [ j ] == 0 )
                {
                    mat [ i ] [ j ] = 1 ;
                    bakt ( catee + 1 ) ;
                    mat [ i ] [ j ] = 0 ;
                }
            }
    }
}

int sol [ MAX ] [ MAX ] [ MAX ] ;

int main()
{
    /*int t ;
    cin >> t ;
    FORN ( tests , 1 , t )
    {
        cin >> R >> C >> n ;
        FORN ( i , 1 , R )
            FORN ( j , 1 , C )
                mat [ i ] [ j ] = 0 ;
        for ( int i = 1 ; i <= R ; ++ i )
        {
            if ( i & 1 )
                for ( int j = 1 ; j <= C and n >= 1 ; j += 2 ){
                    mat [ i ] [ j ] = 1 ;
                    n -- ;
            }
            else {
                for ( int j = 2 ; j <= C and n >= 1 ; j += 2 ){
                    mat [ i ] [ j ] = 1 ;
                    n -- ;
                }
            }
        }
        FORN ( i , 1 , R )
            FORN ( j , 1 , C )
                if ( mat [ i ] [ j ] == 0 and n >= 1 )
                {
                    mat [ i ] [ j ] = 1 ;
                    n -- ;
                }
        CET = 1 << 30 ;
        check() ;
        cout << "Case #" << tests << ": " << CET << '\n' ;

        FORN ( i , 1 , R ){
            FORN ( j , 1 , C )
                cout << mat [ i ] [ j ] << ' ' ;
            cout << endl ;
        }
        cout << "-------------------------------------------\n" ;

    }*/

    /*FORN ( i , 1 , 16 )
        FORN ( j , 1 , 16 )
            FORN ( w , 1 , 16 )
            {
                CET = 1 << 30 ;
                if ( i * j > 16 or i * j < w ) continue ;
                R = i ;
                C = j ;
                n = w ;
                bakt ( 1 ) ;
                //cout << " sol [ " << i << " ]" << "[ " << j << " ]" << "[ " << n << " ] " << " = " << CET << ";\n" ;
            }*/
    int t ;
    cin >> t ;
    FORN ( tests , 1 , t )
    {
        int R , C , n ;
        cin >> R >> C >> n ;
        int mij = R * C ;
        mij /= 2 ;
        if ( R & 1 and C & 1 )
            mij ++ ;
        if ( n <= mij )
        {
           cout << "Case #" << tests << ": " << 0 << '\n' ;
           continue ;
        }
        int start = 1 ;
        if ( R & 1 and C & 1 )
            start = 2 ;
        ++ mij ;
        int cate = n - mij + 1 ;
        cout << "Case #" << tests << ": " << start + cate * 2  << '\n' ;
    }
    return 0;
}
