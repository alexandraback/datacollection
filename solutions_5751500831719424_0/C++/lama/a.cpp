#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

int main() {
    int T;
    cin >> T;
    for (int Ti = 1; Ti <= T; ++Ti) {
        int N;
        cin >> N;

        string s1, s2;
        cin >> s1 >> s2;

        vector<int> count1;
        char last = s1[0];
        string stripped1 (1, last);
        int count = 1;
        for (int i = 1; i < s1.size(); ++i) {
            if (s1[i] == last) {
                count++;
            } else {
                count1.push_back(count);
                count = 1;
                last = s1[i];
                stripped1 += last;
            }
        }
        count1.push_back(count);

        vector<int> count2;
        last = s2[0];
        string stripped2 (1, last);
        count = 1;
        for (int i = 1; i < s2.size(); ++i) {
            if (s2[i] == last) {
                count++;
            } else {
                count2.push_back(count);
                count = 1;
                last = s2[i];
                stripped2 += last;
            }
        }
        count2.push_back(count);

        if (stripped1.compare(stripped2) != 0) {
            cout << "Case #" << Ti << ": " << "Fegla Won" << endl;
        } else {
            int res = 0;
            for (int i = 0; i < count1.size(); ++i) {
                res += abs(count1[i] - count2[i]);
            }   
            cout << "Case #" << Ti << ": " << res << endl;
        }

        // DEBUG(stripped1);
        // DEBUG(stripped2);
        // for (int i = 0; i < count1.size(); ++i) {
        //     cout << count1[i];
        // }
        // cout << endl;
        // for (int i = 0; i < count2.size(); ++i) {
        //     cout << count2[i];
        // }
        // cout << endl;
    }
    return 0;
}