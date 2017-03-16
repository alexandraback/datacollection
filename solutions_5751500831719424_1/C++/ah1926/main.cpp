#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

int N, Answer;
vector<string> Strings;
vector< vector< pair<char, int> > > CompressedStrings;

inline int Abs(const int value) {
    if (value < 0)
        return -value;
    return value;
}

void Solve() {
    CompressedStrings = vector< vector< pair<char, int> > >(N);
    for (int i = 0; i < N; ++i) {
        char symbol = Strings[i][0];
        int frequence = 1;
        for (int j = 1; j < int(Strings[i].length()); ++j) {
            if (Strings[i][j] != symbol) {
                CompressedStrings[i].push_back(make_pair(symbol, frequence));
                symbol = Strings[i][j];
                frequence = 1;
            } else {
                ++frequence;
            }
        }
        CompressedStrings[i].push_back(make_pair(symbol, frequence));
    }
    Answer = 0;
    int length = int(CompressedStrings[0].size());
    vector< vector<int> > frequences = vector< vector<int> >(length, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        if (int(CompressedStrings[i].size()) != length) {
            Answer = -1;
            return;
        }
        for (int j = 0; j < length; ++j) {
            if (CompressedStrings[i][j].first != CompressedStrings[0][j].first) {
                Answer = -1;
                return;
            }
            frequences[j][i] = CompressedStrings[i][j].second;
        }
    }
    for (int i = 0; i < length; ++i) {
        sort(frequences[i].begin(), frequences[i].end());
        int count = frequences[i][N / 2];
        for (int j = 0; j < N; ++j)
            Answer += Abs(frequences[i][j] - count);
    }
}

int main() {
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
    int testCount;
    cin >> testCount;
    for (int test = 1; test <= testCount; ++test) {
        cin >> N;
        Strings = vector<string>(N, "");
        for (int i = 0; i < N; ++i)
            cin >> Strings[i];
        Solve();
        cout << "Case #" << test << ": ";
        if (Answer == -1)
            cout << "Fegla Won\n";
        else
            cout << Answer << "\n";
    }
    return 0;
}
