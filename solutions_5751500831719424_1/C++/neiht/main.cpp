#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool check(const string& str, const vector<char>& charOrder) {
    int nextOrder = 0; // The char order to be compared with
    char curChar = 0;
    for (auto& c : str) {
        if (curChar == 0 || c != curChar) {
            if (nextOrder >= (int) charOrder.size() ||
                c != charOrder[nextOrder]) {
                return false;
            }
            curChar = c;
            nextOrder++;
        }
    }

    if (nextOrder == (int) charOrder.size()) {
        return true;
    }
    else {
        return false;
    }
}

vector<int> countChars(const string& str) {
    vector<int> result;

    char curChar = str[0];
    int curCount = 0;
    for (auto& c : str) {
        if (c != curChar) {
            result.push_back(curCount);
            curChar = c;
            curCount = 1;
        } else {
            curCount++;
        }
    }
    result.push_back(curCount);

    return result;
}

int main() {
    int t; // number of test cases
    int curCase = 1;

    cin >> t;
    while (t--) {
        cout << "Case #" << curCase << ": ";

        int numStr;
        cin >> numStr;

        vector<string> strs;
        vector<char> charOrder;

        string temp;
        for (int i = 0; i < numStr; ++i) {
            cin >> temp;
            strs.push_back(temp);
        }

        // Find the distinct seq of chars from the first string
        for (auto& c : strs[0]) {
            if (charOrder.empty() || c != charOrder.back()) {
                charOrder.push_back(c);
            }
        }

        bool possible = true;
        for (int i = 1; i < numStr; i++) {
            if (!check(strs[i], charOrder)) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << "Fegla Won" << endl;
        } else {
            vector<vector<int>> counts;

            for (auto& s : strs) {
                counts.push_back(countChars(s));
            }

            // Find the average counts for each char
            int len = charOrder.size();
            vector<int> maxCount(len, 0);
            for (auto& v : counts) {
                for (int i = 0; i < len; i++) {
                    maxCount[i] = max(maxCount[i], v[i]);
                }
            }

            int totalChanges = 0;
            for (int i = 0; i < len; i++) {
                // Find the min changes needed for each character
                int minChanges = 0x0fffffff;
                for (int target = 1; target <= maxCount[i]; target++) {
                    int curCount = 0;
                    for (auto& v : counts) {
                        curCount += abs(v[i] - target);
                    }
                    if (curCount < minChanges) {
                        minChanges = curCount;
                    }
                }
                totalChanges += minChanges;
            }

            cout << totalChanges << endl;

        }
        curCase++;
    }
}
