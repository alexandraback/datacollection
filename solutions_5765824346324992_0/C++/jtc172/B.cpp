#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long int LLT ; 
#define MAXN 100000

int Ans ; 
int S[MAXN];
int N , M , T ; 
LLT Time ; 

void Init()
{
     scanf("%d %d",&N,&M);
     for ( int i = 1 ; i <= N ; i ++ ) 
         scanf("%d",&S[i]);
}

LLT Count( LLT x ) 
{
    LLT tmp = 0 ; 
    for ( int i = 1 ; i <= N ; i ++ ) 
        tmp += ( x / S[i] ) + 1  ; 
    return tmp ; 
}

void MatchTime()
{
     LLT l = 0 , r = (1LL)<<50 ; 
     while ( l < r - 1 ) {
           LLT mid = ( l + r ) / 2 ; 
           if ( Count( mid ) >= M  ) r = mid ; else l = mid ; 
     }
     if ( Count(l) >= M ) Time = l ; else Time = r ; 
} 

void Work()
{
     Time = 0 ; 
     MatchTime();
     int tmp = 0 ;
     for ( int i = 1 ; i <= N ; i ++ ) {
         
         if ( Time % S[i] != 0 ) tmp += 1 + ( Time / S[i] )  ; else tmp += ( Time / S[i] ) ;  
     }
     for ( int i = 1 ; i <= N ; i ++ ) 
         if ( Time % S[i] == 0 ) {
              if ( tmp + 1 == M ) {
                   Ans = i ; break; 
              } else 
                   tmp ++ ;  
         }
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&T);
    for ( int TestCase = 1 ; TestCase <= T ; TestCase ++ ) {
        Init();Work();
        printf("Case #%d: %d\n",TestCase,Ans);
    }
    return 0 ; 
}   