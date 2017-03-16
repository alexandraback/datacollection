#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;


const int MAX_N = 110;
const int INF = 1e9;
int count[MAX_N][MAX_N];

string normalize(const string& a, int count[MAX_N]) {
    string result;

    int c = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (i == 0 || a[i] != a[i - 1]) {
            count[c++] = 1;
            result.push_back(a[i]);
        }

        ++count[c-1];
    }

    return result;
}

int computeCountFor(int count[MAX_N][MAX_N], int pos, int sz, int target) {
    int result = 0;
    for (int i = 0; i < sz; ++i)
        result += abs(target - count[i][pos]);
    return result;
}

int computeCount(int count[MAX_N][MAX_N], int sz, int pos) {
    int result = INF;
    for (int i = 0; i <= 110; ++i)
        result = min(result, computeCountFor(count, pos, sz, i));
    return result;
}


int solve(const vector<string>& s) {
    memset(count, 0, sizeof(count));
    
    string norm = normalize(s[0], count[0]);
    for (int i = 1; i < s.size(); ++i) {
        string crtNorm = normalize(s[i], count[i]);
        if (crtNorm != norm)
            return -1;
    }

    int result = 0;
    for (int i = 0; i < norm.size(); ++i)
        result += computeCount(count, s.size(), i);

    return result;
}

void readData(vector<string>& s) {
    int count;
    cin >> count;

    for (int i = 0; i < count; ++i) {
        string w;
        cin >> w;
        s.push_back(w);
    }
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; ++i) {
        vector<string> s;
        readData(s);
        int res = solve(s);
        cout << "Case #" << i << ": ";
        if (res < 0)
            cout << "Fegla Won" << endl;
        else
            cout << res << endl;
    }

    return 0;
}

