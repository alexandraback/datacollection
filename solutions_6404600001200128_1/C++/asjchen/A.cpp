// A

#include <iostream>
#include <fstream>
using namespace std;

int n;
int mush[1005];

int main()
{
    ifstream fin ("A-large.in");
    ofstream fout ("A-large.txt");
    int t;
    fin >> t;
    for ( int h = 1; h <= t; h++ )
    {
        fin >> n;
        for ( int i = 0; i < n; i++ ) fin >> mush[i];
        int sum1 = 0;
        int sum2 = 0;
        int rate2 = 0;
        for ( int i = 1; i < n; i++ )
        {
            if ( mush[i] < mush[i - 1] )
            {
                int d = mush[i - 1] - mush[i];
                sum1 += d;
                rate2 = ( rate2 > d ) ? rate2 : d;
            }
        }
        for ( int i = 0; i < n - 1; i++ )
        {
            if ( mush[i] > rate2 ) sum2 += rate2;
            else sum2 += mush[i];
        }
        fout << "Case #" << h << ": " << sum1 << " " << sum2 << endl;
    }
    return 0;
}
