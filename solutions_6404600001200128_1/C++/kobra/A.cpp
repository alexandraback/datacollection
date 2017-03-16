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
    freopen("A-large.in", "r", stdin);
    //freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    int TESTS;
    cin >> TESTS;
    for (size_t test_number = 1; test_number <= TESTS; test_number++) {
        int N;
        cin >> N;
        vector<int> mushrooms;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            mushrooms.push_back(k);
        }
        int Ans1 = 0, Ans2 = 0;
        int biggestDecrease = 0;
        for (int i = 1; i < N; i++) {
            //cout << "M[i-1]=" << mushrooms[i - 1];
            Ans1 += max(mushrooms[i - 1] - mushrooms[i], 0);
            // cout << "Ans1 = " << Ans1 << endl;
            biggestDecrease = max(biggestDecrease, mushrooms[i - 1] - mushrooms[i]);
        }
        for (int i = 1; i < N; i++) {
            if (mushrooms[i - 1] > biggestDecrease) {
                Ans2 += biggestDecrease;
            } else
                Ans2 += mushrooms[i - 1];
        }

        cout << "Case #" << test_number << ": ";
        cout << Ans1 << " " << Ans2;

        cout << endl;
    }
    return 0;
}

