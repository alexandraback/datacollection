#include <iostream>
#include <fstream>
using namespace std;

int gcd ( int a, int b )
{
    int c;
    while ( a != 0 ) {
     c = a; a = b%a;  b = c;
    }
    return b;
}

int main()
{
    fstream fin("in.txt",ios::in);
    fstream fout("out.txt",ios::out);
    int n ;
    fin >> n ;
    for ( int n2 = 0 ; n2 < n ; n2 ++ ){
        if ( n2 > 0 )
            fout << endl ;
        int B , N ;
        fin >> B >> N ;
        long long int b[5000] , c[5000] ;
        for ( int bar = 0 ; bar < B ; bar ++ ){
            fin >> b[bar] ;
            c[bar] = 0 ;
        }
        int hcf = b[0] ;
        for ( int i = 1 ; i < B ; i ++ )
            hcf = hcf * b[i] / gcd(hcf,b[i]) ;
        int amount = 0 ;
        for ( int i = 0 ; i < B ; i ++ )
            amount += hcf / b[i] ;
        int mod = N % amount ;
        int result ;
        if ( mod == 0 )
            mod = amount ;
        N = mod ;
        long long int mint = 0 ;
        for ( int i = 0 ; i < N ; i ++ ){
            bool get = false ;
            for ( int j = 0 ; j < B ; j ++ ){
                if ( c[j] == mint ) {
                    if ( get == false ){
                        result = j + 1 ;
                        get = true ;
                        c[j] += b[j] ;
                    }
                }
            }
            mint = c[0] ;
            for ( int j = 0 ; j < B ; j ++ )
                mint = min(mint,c[j]) ;

        }
        fout << "Case #" << n2 + 1 << ": " << result ;
    }
    return 0;
}
