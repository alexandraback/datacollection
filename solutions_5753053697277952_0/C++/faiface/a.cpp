#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int q = 1; q <= t; ++q) {
        int n;
        cin >> n;

        vector<int> parties(n);
        for (int i = 0; i < n; ++i) {
            cin >> parties[i];
        }

        vector<pair<int, int>> plan;

        // first stage
        bool all_equal = false;
        while (!all_equal) {
            all_equal = true;
            int maximum = parties[0];
            for (int i = 1; i < parties.size(); ++i) {
                if (parties[i] != maximum) all_equal = false;
                if (parties[i] > maximum) maximum = parties[i];
            }

            if (!all_equal) {
                for (int i = 0; i < parties.size(); ++i) {
                    if (parties[i] == maximum) {
                        parties[i]--;
                        plan.push_back({i, -1});
                    }
                }
            }
        }

        // second stage
        for (int i = 2; i < parties.size(); ++i) {
            for (int j = parties[i]; j > 0; --j) {
                parties[j]--;
                plan.push_back({i, -1});
            }
        }

        // third stage
        for (int i = 0; i < 2; ++i) {
            for (int j = parties[0]; j > 0; --j) {
                parties[0]--;
                parties[1]--;
                plan.push_back({0, 1});
            }
        }

        cout << "Case #" << q << ":";
        for (pair<int, int> p: plan) {
            cout << " ";
            if (p.first != -1) cout << (char)('A' + p.first);
            if (p.second != -1) cout << (char)('A' + p.second);
        }
        cout << endl;
    }
}
