#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <hash_map>
#include <string>
#include <map>
#include <set>
#include <queue>

#if 0
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int256_t lll;
typedef uint256_t ulll;
#endif

using namespace std;
using namespace std::tr1;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T, R1, R2;

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t = 0; t != T; ++t) {
        cout << "Case #" << (t + 1) << ": ";
        cin >> R1; R1--;
        set<int> r1, r2;
        for (int r = 0; r != 4; ++r) {
            for (int c = 0; c != 4; ++c) {
                int card;
                cin >> card;
                if (r == R1) r1.insert(card);
            }
        }
        cin >> R2; R2--;
        for (int r = 0; r != 4; ++r) {
            for (int c = 0; c != 4; ++c) {
                int card;
                cin >> card;
                if (r == R2) r2.insert(card);
            }
        }
        vector<int> r3;
        set_intersection(r1.begin(), r1.end(), r2.begin(), r2.end(), back_inserter(r3));
        if (r3.size() == 0) {
            cout << "Volunteer cheated!\n"; 
        } else if (r3.size() == 1) {
            cout << r3.front() << "\n"; 
        } else {
            cout << "Bad magician!\n"; 
        }
    }
    return 0;
}
