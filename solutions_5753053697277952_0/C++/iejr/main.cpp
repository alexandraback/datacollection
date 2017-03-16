//iejr Header files
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <ctime>
#include <cctype>
#include <functional>
#include <utility>
#include <numeric>

using namespace std;

//iejr: Type defination
typedef unsigned long long int             ULLN;
typedef long long int                      LLN;
typedef vector<int>                        VI;
typedef vector<vector<int> >               VVI;
typedef vector<string>                     VS;
typedef vector<vector<string> >            VVS;


//iejr: Compile Options
//#define C11_Standard
//
#ifdef C11_Standard
    #include <unordered_set>
    #include <unordered_map>

    #define HASHSET                  unordered_set
    #define HASHMAP                  unordered_map;
#endif // C11_Standard


//iejr: Local Debug
#define INPUT_REDIRECTION
#define OUTPUT_REDIRECTION

struct Node{
    int nIndex;
    int nVote;
    Node(): nIndex( 0 ), nVote( 0 ){};
};

bool cmp( const Node &n1, const Node &n2 ){
    return n1.nVote > n2.nVote;
}

//iejr: Main Function
int main()
{

#ifdef INPUT_REDIRECTION
    freopen( "A-small-attempt0.in", "r", stdin );
#endif // INPUT_REDIRECTION

#ifdef OUTPUT_REDIRECTION
    freopen( "out.txt", "w", stdout );
#endif // OUTPUT_REDIRECTION

    int T = 0;
    scanf( "%d", &T );
    for( int i = 1;i <= T;++i ){
        //your solution here
        int N = 0;
        scanf( "%d", &N );
        Node * nArray = new Node[N];
        int nSum = 0;
        for( int i = 0;i < N;++i ){
            nArray[i].nIndex = i;
            scanf( "%d", &nArray[i].nVote );
            nSum  += nArray[i].nVote;
        }

        sort( nArray, nArray + N, cmp );
        printf( "Case #%d: ", i );
        while( nArray[0].nVote > 0 ){
            if( (nArray[1].nVote -1) / (double)( nSum - 2 ) > 0.5 ){
                printf( "%c ", nArray[0].nIndex + 'A' );
                --nArray[0].nVote;
                --nSum;
            }
            else if( N > 2 && nArray[2].nVote / (double)( nSum - 2 ) > 0.5 ){
                printf( "%c ", nArray[0].nIndex + 'A' );
                --nArray[0].nVote;
                --nSum;
            }
            else{
                printf( "%c%c ", nArray[0].nIndex + 'A', nArray[1].nIndex + 'A' );
                --nArray[0].nVote;
                --nArray[1].nVote;
                --nSum;
                --nSum;
            }

            sort( nArray, nArray + N, cmp );
        }
        printf( "\n" );
    }

#ifdef INPUT_REDIRECTION
    fclose( stdin );
#endif // INPUT_REDIRECTION

#ifdef OUTPUT_REDIRECTION
    fclose( stdout );
#endif // OUTPUT_REDIRECTION

    return 0;
}
