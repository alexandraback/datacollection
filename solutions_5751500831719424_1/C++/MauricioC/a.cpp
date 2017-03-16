#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++) {
        int n;
        cin >> n;

        string strs[n];
        for (int i = 0; i < n; i++) {
            cin >> strs[i];
            strs[i] += "X";
        }

        int ptrs[n];
        memset(ptrs, 0, sizeof ptrs);

        char last = 'Z';
        bool possible = true;
        int ans = 0;

        while(possible && last != 'X') {
            last = strs[0][ptrs[0]];

            int this_step[n];
            memset(this_step, 0, sizeof this_step);

            for (int i = 0; i < n; i++) {
                assert(ptrs[i] < strs[i].size());

                if (strs[i][ptrs[i]] != last)
                    possible = false;

                while(strs[i][ptrs[i]] == last && ptrs[i] < strs[i].size()) {
                    ptrs[i]++;
                    this_step[i]++;
                }
            }

            if (last == 'X')
                break;

            sort(this_step, this_step + n);
            for (int i = 0; i < n; i++)
                ans += abs(this_step[n/2] - this_step[i]);
        }

        if (!possible)
            printf("Case #%d: Fegla Won\n", z);
        else {
            assert(last == 'X');
            printf("Case #%d: %d\n", z, ans);
        }
    }
}
