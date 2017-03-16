// B

#include <iostream>
#include <fstream>
using namespace std;

long long b, n;
long long barber[1005];
long long mn;

int main()
{
    ifstream fin ("B-small-attempt0.in");
    ofstream fout ("B-small.txt");
    int t;
    fin >> t;
    for ( int h = 1; h <= t; h++ )
    {
        fin >> b >> n;
        for ( long long i = 0; i < b; i++ )
        {
            fin >> barber[i];
            if ( i == 0 ) mn = barber[i];
            else mn = ( mn < barber[i] ) ? mn : barber[i];
        }
        if ( n <= b )
        {
            fout << "Case #" << h << ": " << n << endl;
            continue;
        }
        long long low = 0;
        long long high = mn * n;
        while ( high - low > 1 )
        {
            long long mid = ( low + high ) / 2;
            long long cnt = 0;
            for ( long long i = 0; i < b; i++ ) cnt += 1 + ( mid / barber[i] );
            if ( cnt < n ) low = mid;
            else high = mid;
        }
        long long hcount = 0, lcount = 0;
        for ( long long i = 0; i < b; i++ )
        {
            lcount += 1 + ( low / barber[i] );
            hcount += 1 + ( high / barber[i] );
        }
        long long p = -1;
        long long count = 0;
        while ( p < b && count != n - lcount )
        {
            p++;
            if ( high % barber[p] == 0 ) count++;
        }
        fout << "Case #" << h << ": " << p + 1 << endl;
    }
    return 0;
}
