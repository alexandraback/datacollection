// CPPFLAGS=-std=gnu++11 -O3

#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for (int T = 1; T <= numCases; T++) {
        int N;
        cin >> N;

        vector<char> sequence;
        vector<vector<int> > counts(N);

        bool mismatch = false;
        for (int i = 0; i < N; i++) {
            string word;
            cin >> word;

            vector<char> thisSequence;
            for (int j = 0; j < word.length(); j++) {
                if (j == 0 || word[j] != word[j-1]) {
                    thisSequence.push_back(word[j]);
                    counts[i].push_back(0);
                }
                counts[i].back()++;
            }

            if (i == 0) {
                sequence = thisSequence;
            } else if (sequence != thisSequence) {
                mismatch = true;
            }
        }

        int totalCost = 0;
        if (!mismatch) {
            for (int j = 0; j < counts[0].size(); j++) {
                vector<int> sizes;
                for (int i = 0; i < N; i++) {
                    sizes.push_back(counts[i][j]);
                }
                sort(sizes.begin(), sizes.end());
                int median = sizes[N/2];
                for (int i = 0; i < N; i++) {
                    totalCost += abs(sizes[i]-median);
                }
            }
        }



        cout << "Case #" << T << ": ";
        if (mismatch) {
            cout << "Fegla Won";
        } else {
            cout << totalCost;
        }
        cout << endl;
    }
}
