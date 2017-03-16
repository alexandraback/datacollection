#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


int method1(vector<int> m) {
    int eat = 0;
    for (int i = 1; i < m.size(); ++i) {
        if (m[i] < m[i-1])
            eat += m[i-1] - m[i];
    }

    return eat;
}

int method2(vector<int> m) {
    int max_interval = 0;
    for (int i = 1; i < m.size(); ++i) {
        if (m[i] < m[i-1])
            max_interval = max(max_interval, m[i-1] - m[i]);
    }

    int min_eat = max_interval;

    int eat = 0;
    for (int i = 0; i < m.size()-1; ++i) {
        if (min_eat > m[i])
            eat += m[i];
        else
            eat += min_eat;
    }

    return eat;
}

int main() {
    int N;
    cin >> N;

    for (int test=1; test <= N; ++test) {
        int T;
        cin >> T;
        vector<int> m(T);
        for (int i = 0; i < T; ++i)
            cin >> m[i];

        printf("Case #%d: %d %d\n", test, method1(m), method2(m));
    }
    return 0;
}
