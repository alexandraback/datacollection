

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
    size_t cases = 0;
    cin >> cases;
    // run the test cases
    size_t n = 0;
    while (n != cases)
    {
        ++n;
        set<int> selected;
        set<int> candidates;
        int ch, x, r, c;
        // first grid
        cin >> ch;
        for (r = 1; r <= 4; ++r)
        {
            for (c = 1; c <= 4; ++c)
            {
                cin >> x;
                if (r == ch)
                {
                    // insert the possibility
                    selected.insert(x);
                }
            }
        }
        // second grid
        cin >> ch;
        for (r = 1; r <= 4; ++r)
        {
            for (c = 1; c <= 4; ++c)
            {
                cin >> x;
                if (r == ch)
                {
                    const set<int>::const_iterator found = selected.find(x);
                    if (found != selected.end())
                    {
                        candidates.insert(x);
                    }
                }
            }
        }
        // write out the result
        cout << "Case #" << n << ": ";
        switch (candidates.size())
        {
        case 0:
            cout << "Volunteer cheated!";
            break;
        case 1:
            cout << *candidates.begin();
            break;
        default:
            cout << "Bad magician!";
            break;
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
