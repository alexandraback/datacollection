#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <deque>
#include <list>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mem0(ar) memset(ar, 0, sizeof(ar))
#define mem1(ar) memset(ar, -1, sizeof(ar))

int main()
{
    //freopen("B-large.in", "r", stdin);
    freopen("B.in", "r", stdin);
    freopen("B2.out", "w", stdout);

    int TESTS;
    cin >> TESTS;
    for (size_t test_number = 1; test_number <= TESTS; test_number++) {
        cout << "Case #" << test_number << ": ";
        ll R, C, N;
        cin >> R >> C >> N;
        if (C < R)
            swap(R, C);
        if (R == 1 || C == 1) {
            ll worst_result = (C - 1);
            worst_result = max((ll)0, worst_result - (C - N) * 2);
            cout << worst_result << endl;
            continue;
        } else if (R == 2 || C == 2) {
            ll half = R * C / 2;
            ll worst_result = 0;
            if (N - half == 1) {
                worst_result = 2;
            } else if (N - half >= 2) {
                worst_result = 4 + (N - half - 2) * 3;
            }
            cout << worst_result << endl;
            continue;
        } else if (R == 3 && C == 3 && N == 5) {
            cout << 0 << endl;
            continue;
        }

        ll worst_result = C * (R - 1) + R * (C - 1);
        ll all_rooms = R * C;

        ll rooms_with_four = ((R - 2) * (C - 2) + (ll) 1) / (ll)2;
        if (N < all_rooms) {
            ll taken = min(rooms_with_four, all_rooms - N);
            N += taken;
            worst_result -= taken * (ll)4;
        }
        ll rooms_with_three = R + C - (ll)4;
        if (R % 2 == 1 && C % 2 == 1) {
            rooms_with_three -= (ll) 2;
        }
        if (N < all_rooms) {
            ll taken = min(rooms_with_three, all_rooms - N);
            N += taken;
            worst_result -= taken * (ll)3;
        }
        ll rooms_with_two = 2;
        if (N < all_rooms) {
            if (R % 2 == 1 && C % 2 == 1) {
                worst_result += 1;
                rooms_with_three = 2 * (ll)(R / 2 + C / 2) - rooms_with_three - 1;
                ll taken = min(rooms_with_three, all_rooms - N);
                N += taken;
                worst_result -= taken * (ll)3;
                rooms_with_two = 0;
            }
        }
        if (N < all_rooms) {

            ll taken = min(rooms_with_two, all_rooms - N);
            N += taken;
            worst_result -= taken * (ll)2;
        }
        cout << worst_result;
        cout << endl;
    }
}
