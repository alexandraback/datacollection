#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <climits>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <functional>
#include <iterator>
#include <complex>
#include <queue>
#include <cassert>
#include <sstream>
#include <cstdlib>

using namespace std;

double pi = acos((double) -1);
const int INF = 2147483647;

int main() {
    clock_t tStart = clock();
    int tests = 1;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int n;
        scanf("%d", &n);
        string str1, str2;
        vector<vector<char>> character_arr(n, vector<char>());
        vector<vector<int>> counter_arr(n, vector<int>());

        vector<string> strs;
        string str;
        for (int i = 0; i < n; i++) {
            cin >> str;
            strs.push_back(str);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < strs[i].length(); j++) {
                if (character_arr[i].size() == 0 || character_arr[i].back() != strs[i][j]) {
                    character_arr[i].push_back(strs[i][j]);
                    counter_arr[i].push_back(1);
                }
                else {
                    counter_arr[i][counter_arr[i].size() - 1]++;
                }
            }
        }

        int result = 0;
        bool similar = true;
        for (int i = 1; i < n; i++) {
            if (character_arr[i].size() != character_arr[i - 1].size()) {
                similar = false;
                break;
            }
        }

        if (similar) {
            for (int j = 0; j < character_arr[0].size(); j++) {
                int smallest = counter_arr[0][j], largest = counter_arr[0][j];
                for (int i = 1; i < n; i++) {
                    if (character_arr[i][j] != character_arr[i - 1][j]) {
                        similar = false;
                        break;
                    }

                    smallest = min(smallest, counter_arr[i][j]);
                    largest = max(largest, counter_arr[i][j]);
                }

                if (!similar)
                    break;

                int bestdiff = INF;
                for (int pbest = smallest; pbest <= largest; pbest++) {
                    int diff = 0;
                    for (int i = 0; i < n; i++) {
                        diff += abs(counter_arr[i][j] - pbest);
                    }

                    if (diff < bestdiff) {
                        bestdiff = diff;
                    }
                }

                result += bestdiff;
            }
        }

        if (!similar) {
            cout << "Case #" << test << ": Fegla Won\n";
        }
        else {
            cout << "Case #" << test << ": " << result << endl;
        }
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
