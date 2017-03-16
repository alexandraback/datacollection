#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <climits>
using namespace std;

typedef long long LL;

vector<int> getCandidate(int ans) {
    vector<int> candidate;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int card;
            cin >> card;
            if (i == ans) {
                candidate.push_back(card);
            }
        }
    }
    return candidate;
}
int main() {
    int T;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        int ans1, ans2;
        cin >> ans1;
        vector<int> candidate1 = getCandidate(ans1 - 1);
        cin >> ans2;
        vector<int> candidate2 = getCandidate(ans2 - 1);

        vector<int> finalCandidates;

        for (int i = 0; i < candidate1.size(); i++) {
            for (int j = 0; j < candidate2.size(); j++) {
                if (candidate1[i] == candidate2[j]) {
                    finalCandidates.push_back(candidate1[i]);
                }
            }
        }

        cout << "Case #" << t << ": ";
        if (finalCandidates.size() == 1) {
            cout << finalCandidates[0] << endl;
        } else if (finalCandidates.size() > 1) {
            cout << "Bad magician!" << endl;
        } else {
            cout << "Volunteer cheated!" << endl;
        }

    }
}
