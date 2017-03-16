#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ifstream ifs("in.in");
    ofstream ofs("out.out");

    int T;
    ifs >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        ifs >> N;

        vector<string> lines;
        vector<string> simplified;
        vector<string> times;
        for (int i = 0; i < N; ++i) {
            string line;
            ifs >> line;
            lines.push_back(line);

            char lastChar = 0;
            char currentCount = 0;
            string time;
            for (int j = 0; j < line.length(); ++j) {
                if (line[j] != lastChar) {
                    if (currentCount > 0) {
                        time.push_back(currentCount);
                    }

                    lastChar = line[j];
                    currentCount = 1;
                } else {
                    ++currentCount;
                }
            }
            if (currentCount > 0) {
                time.push_back(currentCount);
            }
            times.push_back(time);

            for (int j = line.length() - 1; j > 0; --j) {
                if (line[j] == line[j-1]) {
                    line.erase(line.begin() + j);
                }
            }
            simplified.push_back(line);
        }

        bool possible = true;
        for (int i = 1; i < N; ++i) {
            if (simplified[i] != simplified[0]) {
                possible = false;
                break;
            }
        }

        ofs << "Case #" << t << ": ";
        if (!possible) {
            ofs << "Fegla Won" << endl;
        } else {
            int overallDistance = 0;
            for (int i = 0; i < simplified[0].length(); ++i) {
                char valueMin = CHAR_MAX;
                char valueMax = 0;
                for (int j = 0; j < N; ++j) {
                    string time = times[j];
                    char value = time[i];
                    if (value > valueMax) valueMax = value;
                    if (value < valueMin) valueMin = value;
                }

                int minTotalDistance = INT_MAX;
                for (int v = valueMin; v <= valueMax; ++v) {
                    int totalDistance = 0;
                    for (int j = 0; j < N; ++j) {
                        string time = times[j];
                        char value = time[i];
                        totalDistance += abs(value - v);
                    }
                    if (totalDistance < minTotalDistance) {
                        minTotalDistance = totalDistance;
                    }
                }

                overallDistance += minTotalDistance;
            }

            ofs << overallDistance << endl;
        }
    }

    return 0;
}
