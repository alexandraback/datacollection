#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a;

void input() {
    a.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        a.push_back(j);
    }
}

int work1() {
    int ans = 0;
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] > a[i]) {
            ans += a[i - 1] - a[i];
        }
    }
    return ans;
}

int work2() {
    int m = 0;
    for (int i = 1; i < a.size(); i++) {
        m = max(m, a[i - 1] - a[i]);
    }
    int ans = 0;
    for (int i = 1; i < a.size(); i++) {
        ans += min(m, a[i - 1]);
    }
    return ans;
}

int main() {
    cin.sync_with_stdio(false);
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; i++) {
        input();
        cout << "Case #" << i << ": " << work1() << " " << work2() << "\n";
    }
}
