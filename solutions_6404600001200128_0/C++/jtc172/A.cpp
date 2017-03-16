#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
#define MAXN 100000

int A[MAXN] ;
int N , T ;
int Ans1,Ans2; 

void Init()
{
     scanf("%d",&N);
     for ( int i = 1 ; i <= N ; i ++ ) 
         scanf("%d",&A[i]);
     Ans1 = 0 ; Ans2 = 0 ; 
     for ( int i = 1 ; i <= N - 1 ; i ++ ) 
         if ( A[i+1] < A[i] ) Ans1 += A[i] - A[i+1];
     int Speed = 0 ; 
     for ( int i = 1 ; i <= N - 1 ; i ++ ) 
         if ( ( A[i+1] < A[i] ) && ( A[i] - A[i+1] > Speed ) ) 
            Speed =  A[i] - A[i+1]  ; 
     for ( int i = 1 ; i <= N - 1 ; i ++ ) 
         if ( ( A[i] < Speed ) ) Ans2 += A[i] ; else Ans2 += Speed ; 
}   

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    for ( int TestCase = 1 ; TestCase <= T ; TestCase ++ ) {
        Init();
        printf("Case #%d: %d %d\n",TestCase , Ans1,Ans2);
    }
    return 0 ; 
}       