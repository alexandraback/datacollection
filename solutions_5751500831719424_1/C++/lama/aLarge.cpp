#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

const int MAXN = 110;
const int INF = 1e9 + 7;

pair<vector<int>, string> strip(string s) {
    vector<int> count;
    char last = s[0];
    string stripped (1, last);
    int countTemp = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == last) {
            countTemp++;
        } else {
            count.push_back(countTemp);
            countTemp = 1;
            last = s[i];
            stripped += last;
        }
    }
    count.push_back(countTemp);

    return make_pair(count, stripped);
}

// int manhattan(vector<int> v1, vector<int> v2) {
//     int res = 0;
//     for (int i = 0; i < v1.size(); ++i) {
//         res += abs(v1[i] - v2[i]);
//     }
//     return res;
// }

int main() {
    int T;
    cin >> T;
    for (int Ti = 1; Ti <= T; ++Ti) {
        int N;
        cin >> N;

        pair<vector<int>, string> words[MAXN];
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            words[i] = strip(s);
        }

        bool ok = true;
        for (int i = 1; i < N; ++i) {
            if (words[i].second.compare(words[0].second) != 0) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "Case #" << Ti << ": " << "Fegla Won" << endl;
        } else {
            // int res = INF;


            // for (int i = 0; i < N; ++i) {
            //     // Find sum of distances of all words to words[i]
            //     int sum = 0;
            //     for (int j = 0; j < N; ++j) {
            //         sum += manhattan(words[i].first, words[j].first);
            //     }

            //     // Find result
            //     res = min(res, sum);
            // }

            int res = 0;
            for (int i = 0; i < words[0].first.size(); ++i) {
                int minManhattan = INF;
                for (int j = 0; j < MAXN; ++j) {
                    int manhattan = 0;
                    for (int k = 0; k < N; ++k) {
                        manhattan += abs(words[k].first[i] - j);
                    }
                    minManhattan = min(minManhattan, manhattan);
                }
                res += minManhattan;
            }
            cout << "Case #" << Ti << ": " << res << endl;
        }
    }
    return 0;
}