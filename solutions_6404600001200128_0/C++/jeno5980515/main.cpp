#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream fin("in.txt",ios::in);
    fstream fout("out.txt",ios::out);
    int n ;
    fin >> n ;
    for ( int n2 = 0 ; n2 < n ; n2 ++ ){
        if ( n2 > 0 )
            fout << endl ;
        int number ;
        fin >> number ;
        int a[10005] ;
        for ( int n3 = 0 ; n3 < number ; n3 ++ ){
            fin >> a[n3] ;
        }
        int maxrate = 0 ;
        int r1 = 0 , r2 = 0 ;
        for ( int i = 1 ; i < number ; i ++ ){
            if ( a[i-1] - a[i] > maxrate )
                maxrate = a[i-1] - a[i] ;
            if ( a[i] < a[i-1] )
                r1 += a[i-1] - a[i] ;
        }
        for ( int i = 0 ; i < number - 1 ; i ++ ){
            if ( a[i] < maxrate )
                r2 += a[i] ;
            else
                r2 += maxrate ;
        }
        fout << "Case #" << n2 + 1 << ": " << r1 << " " << r2 ;
    }
    return 0;
}
