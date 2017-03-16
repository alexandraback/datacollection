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
    freopen("B.out", "w", stdout);

    int TESTS;
    cin >> TESTS;
    for (size_t test_number = 1; test_number <= TESTS; test_number++) {
        cout << "Case #" << test_number << ": ";
        int K;
        ll N;
        cin >> K >> N;
        vector<int> barbers;
        for (int i = 0; i < K; i++) {
            int a;
            cin >> a;
            barbers.push_back(a);
        }
        ll lower = 0;
        ll upper = (ll)1000000000 * (ll)1000000000;
        while (upper - lower > 1) {
            ll x = (lower + upper) / 2;
            ll k = 0;
            for (int i = 0; i < K; i++) {
                k += x / (ll)barbers[i] + (ll)1;
                if (k > N)
                    break;
            }
            if (k >= N)
                upper = x;
            else
                lower = x;
        }


        ll result = lower;
        ll last_quantity = 0;
        for (ll i = lower - 2; i < lower + 2; i++) {
            ll k = 0;

            for (int j = 0; j < K; j++) {
                k += i / (ll)barbers[j] + (ll)1;
            }
            if (k >= N) {
                result = i - 1;
                break;
            }
            last_quantity = k;
        }

        last_quantity = max(last_quantity, (ll)0);
        int answer = 0;
        for (int i = 0; i < K; i++) {
            if ((result + (ll)1) % barbers[i] == 0)
                last_quantity++;
            if (last_quantity == N) {
                answer = i;
                break;
            }
        }
        cout << answer + 1;
        cout << endl;
    }
    return 0;
}

