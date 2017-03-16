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

int T, N;
priority_queue<pair<int, char> > P; 

int main(int argc, char* argv[]) {
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            int cnt;
            cin >> cnt;
            P.push(make_pair(cnt, 'A' + i));
        }
        cout << "Case #" << (t + 1) << ":";
        while (!P.empty()) {
            pair<int, char> S1 = P.top();
            P.pop();
            if (P.empty()) {
                just_one:
                cout << " " << S1.second;
                S1.first--;
                if (S1.first > 0) {
                    P.push(S1);
                }
            } else {
                pair<int, char> S2 = P.top();
                P.pop();
                if (S2.first < S1.first) {
                    P.push(S2);
                    goto just_one;
                } else {
                    if (S1.first == 1) {
                        if (!P.empty()) {
                            P.push(S2);
                            goto just_one;
                        }
                    }
                    cout << " " << S1.second << S2.second;
                    S1.first--;
                    S2.first--;
                    if (S1.first > 0) {
                        P.push(S1);
                        P.push(S2);
                    }
                }
            }
        }

        cout << "\n";
    }
    return 0;
}
