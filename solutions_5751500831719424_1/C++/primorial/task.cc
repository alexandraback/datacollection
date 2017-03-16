#include <iostream>
#include <sstream> 
#include <cstdio>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdlib> 
#include <ctime>
#include <cassert>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;
template<typename T> T ABS(const T& val) { return val < 0 ? -val : val; }


int main ()
{
    std::ios_base::sync_with_stdio(false);

    int T;
    while (cin >> T) {
        for (int test = 1; test <= T; ++test) {
            cout << "Case #" << test << ": ";

            int N;
            cin >> N;

            string s;
            vector<vector<pair<int, int> > > counts;

            for (int i = 0; i < N; ++i) {
                cin >> s;
                vector<pair<int, int> > cnt;

                for (int i = 0; i < s.size(); ++i) {
                    if (i == 0 || s[i] != s[i - 1]) {
                        cnt.push_back(make_pair(s[i], 1));
                    } else {
                        ++cnt.back().second;
                    }
                }

                counts.push_back(cnt);
            }

            bool lost = false;
            for (int i = 0; i < N && !lost; ++i) {
                for (int j = i + 1; j < N && !lost; ++j) {
                    if (counts[i].size() != counts[j].size()) {
                        lost = true;
                        break;
                    }

                    for (int k = 0; k < counts[i].size(); ++k) {
                        if (counts[i][k].first != counts[j][k].first) {
                            lost = true;
                            break;
                        }
                    }
                }
            }

            if (lost) {
                cout << "Fegla Won\n";
                continue;
            }

            vector<vector<int> > ord(counts[0].size(), vector<int>());
            for (int i = 0; i < N; ++i) {
                for (int k = 0; k < counts[i].size(); ++k) {
                    ord[k].push_back(counts[i][k].second);
                }
            }

            int ans = 0;
            for (int i = 0; i < ord.size(); ++i) {
                sort(ord[i].begin(), ord[i].end());
                int mid = ord[i][ord[i].size() / 2];

                for (int j = 0; j < ord[i].size(); ++j) {
                    ans += ABS(ord[i][j] - mid);
                }
            }

            cout << ans << "\n";
        }
    }


    return 0;
}
