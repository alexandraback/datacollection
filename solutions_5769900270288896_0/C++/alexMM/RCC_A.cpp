// RCC_A.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int countUnhappines(const vector <int>& pos, int r, int c) {
    vector <vector <bool> > matrix (r, vector <bool>(c, false));
    int ans = 0;
    for (int i = 0; i < pos.size(); ++i) {
        matrix[pos[i] / c][pos[i] % c] = true;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (i != r - 1 && matrix[i][j] && matrix[i + 1][j])
                ++ans;
            if (j != c - 1 && matrix[i][j] && matrix[i][j + 1])
                ++ans;
        }
    }
    return ans;
}

int main(int argc, char* argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int r, c, n;
        cin >> r >> c >> n;
        if (n == 0) {
            cout << "Case #" << t + 1 << ": " << 0 << endl;
            continue;
        }
        vector <int> pos;
        for (int i = 0; i < n; ++i) {
            pos.push_back(i);
        }
        int answer = countUnhappines(pos, r, c);
        while (pos[0] != r * c - n) {
            if (pos.back() != r * c - 1) {
                ++pos.back();
            }
            else {
                int i = pos.size() - 2;
                for (; i >= 0; --i) {
                    if (pos[i] < pos[i + 1] - 1)
                    {
                        ++pos[i];
                        break;
                    }
                }
                for (++i; i < pos.size(); ++i) {
                    pos[i] = pos[i - 1] + 1;
                }
            }
            answer = min(answer, countUnhappines(pos, r, c));
        }
        cerr << t << endl;
        answer = min(answer, countUnhappines(pos, r, c));
        cout << "Case #" << t + 1 << ": " << answer << endl;
    }
	return 0;
}

