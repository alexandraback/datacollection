#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

void error( const char *str)
{
    cout << str;

    exit( 1);
}

int main()
{
    ifstream input( "input.txt");

    if ( !input )
        error( "Cannot open input file");

    ofstream output( "output.txt");

    if ( !output )
        error( "Cannot open output file");

    int num_cases;

    input >> num_cases;

    for ( int i = 0; i < num_cases; i++ )
    {
        int N;

        input >> N;

        vector<string> str( N);

        for ( int j = 0; j < N; j++ )
        {
            input >> str[j];
        }

        char prev_symb = 'A';
        bool fegla_won = false;
        int count = 0;

        while ( true )
        {
            char symb;
            int k = 0;

            for ( k = 0; k < N; k++ )
            {
                if ( str[k].size() )
                {
                    symb = str[k][0];

                    break;
                }
            }

            if ( k == N )
            {
                break;
            }

            int equal_prev = 0;
            int equal_symb = 0;

            for ( int k = 0; k < N; k++ )
            {
                if ( !str[k].size() )
                    continue;

                if ( str[k][0] == prev_symb )
                    equal_prev++;

                if ( str[k][0] == symb )
                    equal_symb++;
            }

            if ( !equal_prev && (equal_symb != N) )
            {
                fegla_won = true;

                break;
            }

            if ( equal_symb == N )
                prev_symb = symb;

            if ( (equal_prev <= N / 2) || (equal_prev == N) )
            {
                if ( equal_prev != N )
                    count += equal_prev;

                for ( int k = 0; k < N; k++ )
                {
                    if ( str[k].size() && (str[k][0] == prev_symb) )
                        str[k].erase( 0, 1);
                }
            } else
            {
                count += (N - equal_prev);

                for ( int k = 0; k < N; k++ )
                {
                    if ( !str[k].size() || (str[k][0] != prev_symb) )
                        str[k] = prev_symb + str[k];
                }
            }
        }

        if ( fegla_won )
            output << "Case #" << i + 1 << ": " << "Fegla Won" << "\n";
        else
            output << "Case #" << i + 1 << ": " << count << "\n";
    }

    return 0;
}
