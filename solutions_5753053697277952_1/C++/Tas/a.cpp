#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    int n_cases;
    cin >> n_cases;

    for (int cno=0; cno < n_cases; cno++)
    {
        int n_parties;
        cin >> n_parties;
        vector<int> freq(n_parties);
        for (int i=0; i < n_parties; ++i)
            cin >> freq[i];





        cout << "Case #" << cno+1 << ": ";

        auto it = max_element( freq.begin(), freq.end());
        auto idx1 = it-freq.begin();
        auto f1 = *it;
        *it = 0;

        it = max_element( freq.begin(), freq.end());
        auto f2 = *it;
        auto idx2 = it - freq.begin();
        *it = 0;


        //cout << f1 << " " << f2 << endl;
        //continue;

        while (f1 > f2)
        {
            cout << char( 'A' + idx1) << " ";
            --f1;
        }

        for ( int i=0; i < n_parties; ++i)
        {
            while ( freq[i] )
            {
                 cout << char( 'A' + i) << " ";
                 --freq[i];
            }
        }

        for (int i=0; i < f1; ++i)
        {
             cout << char( 'A' + idx1) << char('A' + idx2) << " ";
        }



        cout << "\n";

    }
}