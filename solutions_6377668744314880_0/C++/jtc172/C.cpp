#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 5000
#define eps 1e-7
#define pi 3.1415926535f

double X[MAXN] , Y[MAXN] ; 
double arc[MAXN] ; 
int D[MAXN] ; 
int Ans[MAXN] ; 
int N , T ; 

bool cmp( int x , int y )
{
     if ( arc[x] < arc[y] ) return true ; 
     return false ;
}

double care( double x1 , double y1 , double x2 ,double y2 ) 
{
       return ( x1*y2 - x2*y1 ) ;
}
double chaji( int a , int b , int c ) 
{
       return care(X[a]-X[c],Y[a]-Y[c],X[b]-X[c],Y[b]-Y[c]) ;
}      

void Work(int q)
{
     Ans[q] = MAXN * 2 ; 
     if ( N == 1 ) Ans[q] = 0 ; 
     for ( int i = 1 ; i < q ; i ++ ) D[i] = i ; 
     for ( int i = q + 1 ; i <= N ; i ++ ) D[i-1] = i ;
     for ( int i = 1 ; i <= N ; i ++ ) {
         if ( i != q ) arc[i] = atan2(Y[i]-Y[q],X[i]-X[q]);
         if ( ( fabs( Y[i] - Y[q] ) < eps ) && ( X[i] < X[q] ) ) arc[i] = - pi ; 
     } 
     sort( D + 1 , D + N , cmp ) ; 
     int j ; 
     if ( arc[D[1]] >= 0 ) Ans[q] = 0 ; 
     j = 1 ; 
     for ( int i = 1 ; i <= N - 1 ; i ++ ) {
         if ( ( i < N - 1 ) && ( arc[D[i+1]] - arc[D[i]] > pi - eps ) ) Ans[q] = 0 ; 
         if ( arc[D[i]] <= 0 ) {
            if ( j < i ) j = i ; 
            while ( ( ( j + 1 ) <= N - 1 ) && ( chaji( D[i] , D[j+1] , q ) > 0 ) ) j ++ ;
            if ( j - i < Ans[q] ) Ans[q] = j - i ; 
            if ( N - 1 - j + i  < Ans[q] ) Ans[q] = N - 1  - j + i ; 
         }
     }
     j = 1  ; 
     for ( int i = 1 ; i <= N - 1 ; i ++ ) {
         if ( ( i < N - 1 ) && ( arc[D[i+1]] - arc[D[i]] > pi - eps ) ) Ans[q] = 0 ; 
         if ( arc[D[i]] <= 0 ) {
            if ( j < i ) j = i ; 
            while ( ( ( j + 1 ) <= N - 1 ) && ( chaji( D[i] , D[j+1] , q ) >= 0 ) ) j ++ ;
            if ( arc[D[j]] < arc[D[i]] + pi + eps ) {
               if ( j - i + 1 < Ans[q] ) Ans[q] = j - i + 1 ; 
               if ( N - 2 - j + i  < Ans[q] ) Ans[q] = N - 2  - j + i ; 
            } else {
               if ( j - i < Ans[q] ) Ans[q] = j - i ; 
               if ( N - 1 - j + i  < Ans[q] ) Ans[q] = N - 1  - j + i ; 
            }
         }
     }
     
}

void WholeWork()
{
     for ( int i = 1 ; i <= N ; i ++ ) Work(i);
     for ( int i = 1 ; i <= N ; i ++ ) printf("%d\n",Ans[i]);
}

void Init()
{
     scanf("%d",&N);
     for ( int i = 1 ; i <= N ; i ++ ) 
         scanf("%lf %lf",&X[i],&Y[i]);
}
     

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d",&T);
    for ( int TestCase = 1 ; TestCase <= T ; TestCase ++ ) {
        Init();
        printf("Case #%d:\n",TestCase);
        WholeWork();
    }
    return 0 ; 
}