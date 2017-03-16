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
        int a1;
        ifs >> a1;
        vector<int> selectedRow;
        for (int row = 1; row <= 4; ++row) {
            for (int column = 1; column <= 4; ++column) {
                int n;
                ifs >> n;
                if (row == a1) {
                    selectedRow.push_back(n);
                }
            }
        }

        vector<int> repeatedNumbers;

        int a2;
        ifs >> a2;
        for (int row = 1; row <= 4; ++row) {
            for (int column = 1; column <= 4; ++column) {
                int n;
                ifs >> n;
                if (row == a2) {
                    for (size_t i = 0; i < selectedRow.size(); ++i) {
                        if (selectedRow[i] == n) {
                            repeatedNumbers.push_back(n);
                        }
                    }
                }
            }
        }

        ofs << "Case #" << t << ": ";

        if (repeatedNumbers.size() == 1) {
            ofs << repeatedNumbers[0] << endl;
        } else if (repeatedNumbers.size() > 1) {
            ofs << "Bad magician!" << endl;
        } else {
            ofs << "Volunteer cheated!" << endl;
        }
    }

    return 0;
}
