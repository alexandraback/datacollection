#include <iostream>
#include <tuple>
#include <sstream>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <memory>
#include <array>

using namespace std;

string solve(vector<int> sens)
{
    string solution;

    while (any_of(sens.begin(), sens.end(), [](int i) { return i; })) {
        int bigsize = *max_element(sens.begin(), sens.end());
        int nbig = count(sens.begin(), sens.end(), bigsize);
        //for (int n : sens) { if (n == bigsize, n); }

        int count = 0;
        for (int i = 0; i < sens.size(); ++i) {
            
            if (sens[i] == bigsize) {
                solution += 'A' + (char)i;
                --sens[i];
                if (nbig % 2 == 1)
                    break;
                ++count;
                if (count == 2)
                    break;
            }
        }
        solution += ' ';
    }

    return solution;
}

int main(int argc, char *argv[])
{
    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);

    int numCases;
    cin >> numCases;

    int casei = 0;
    int n;
    while (++casei, cin >> n) {
        vector<int> sens;
        for (int i = 0; i < n; ++i) {
            int count;
            cin >> count;
            sens.push_back(count);
        }

        string solution = solve(sens);
        cout << "Case #" << casei << ": ";
        cout << solution;
        cout << endl;
    }

    return 0;
}