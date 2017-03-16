//#define ONLINE_JUDGE

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
# include <array>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("small.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        int n;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        string common;
        for (int i = 0; i < s.front().size(); ++i) {
            if (i == 0  || s.front()[i] != s.front()[i-1])
                common += s.front()[i];
        }
        bool possible = true;
        for (int i = 1; i < s.size() && possible; ++i) {
            int k = 0;
            for (int j = 0; j < s[i].size() && possible; ++j) {
                char c = s[i][j];
                if (j != 0 && c != s[i][j-1])
                    ++k;
                if (k == common.size()  || common[k] != c)
                    possible = false;
            }
            if (k != common.size() - 1)
                possible = false;
        }

        cout << "Case #" << cas << ": ";

        if (possible) {
            int answer = 0;
            for (int i = 0; i < common.size(); ++i) {
                vector<int> sum(100);
                //int min = 1, max = 1;
                const char cur = common[i];
                for (int j = 0; j < s.size(); ++j) {
                    const string & str = s[j];
                    int start = 0;
                    int t = i;
                    for (int k = 1; t > 0; ++k) {
                        if (str[k] != str[k-1]) {
                            if (--t == 0) {
                                start = k;
                            }
                        }
                    }
                    int num = 1;
                    for (int k = start + 1; k < str.size(); ++k) {
                        if (str[k] != cur)
                            break;
                        ++num;
                    }
                    for (int k = 0; k < sum.size();++k) {
                        sum[k] += abs(num - k - 1);
                    }
                  //  min = std::min(min, num);
                    //max = std::max(max, num);
                }

                answer += *min_element(sum.begin(), sum.end());
            }
            cout << answer;
        }
        else {
            cout << "Fegla Won";
        }

        std::cout << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    //putchar('\n');
#endif
}
