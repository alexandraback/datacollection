

#include <cstdlib>
#include <cstdio>
#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;


int main(int argc, char ** argv)
{
    // read the tests count
    int T = 0;
    cin >> T;
    // run the test cases
    int t = 0;
    while (t < T)
    {
        ++t;
        // load the values
        int N;
        cin >> N;
        string line;
        getline(cin, line);
        vector<string> strings(N);
        for (int i = 0; i < N; ++i)
        {
            getline(cin, strings[i]);
        }
        // solve
        // positions in the string
        vector<string::size_type> pos(N, 0);
        // all strings must have the same leeters in the same order,
        // only the counts of successive letters can differ
        bool failed = false;
        size_t moves = 0;
        while (pos[0] < strings[0].size())
        {
            // successive counts
            vector<size_t> counts(N, 0);
            // select a letter
            const char c = strings[1][pos[1]];
            for (vector<string>::size_type j = 0; j < strings.size(); ++j)
            {
                if (strings[j][pos[j]] != c) {
                    // have a letter, that is not in the other string
                    failed = true;
                    break;
                }
                while ((pos[j] < strings[j].size()) && (strings[j][pos[j]] == c)) {
                    ++pos[j];
                    ++counts[j];
                }
            }
            if (failed) break;
            // determine the lowest count of moves for the particular letter
            sort(counts.begin(), counts.end());
            size_t min = (size_t)-1;
            for (size_t i = *counts.begin(); i <= *counts.rbegin(); ++i)
            {
                size_t tmp = 0;
                for (size_t k = 0; k < counts.size(); ++k)
                {
                    int diff = counts[k] - i;
                    if (diff < 0) diff = -diff;
                    tmp += diff;
                }
                if (min > tmp)
                {
                    min = tmp;
                }
                else // if (min < tmp)
                {
                    break;
                }
            }
            assert(min != (size_t)-1);
            moves += min;
        }
        for (vector<string>::size_type i = 0; i < strings.size(); ++i)
        {
            if (pos[i] < strings[i].size())
            {
                failed = true;
                break;
            }
        }
        cout << "Case #" << t << ": ";
        if (failed)
            cout << "Fegla Won";
        else
            cout << moves;
        cout << endl;
    }
    return EXIT_SUCCESS;
}
