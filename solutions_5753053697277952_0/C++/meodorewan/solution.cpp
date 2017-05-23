#include <bits/stdc++.h>

#define reset(a, b) memset(a, b, sizeof(a))
#define REP(i, a) for (int i = 0; i < a.size(); i++)

using namespace std;

const int N = 100100;
const int INF = 1000000007;

vector<pair<int,int> > arr;

int getMax() {
    int mx = 0, result;
    REP(i, arr)
        if (arr[i].first > arr[mx].first)
            mx = i;
    result = arr[mx].second;
    arr[mx].first--;
    if (arr[mx].first == 0) {
        swap(arr[mx], arr[arr.size() - 1]);
        arr.pop_back();
    }
    return result;
}

bool valid() {
    int sum = 0;
    REP(i, arr)
        sum += arr[i].first;
    REP(i, arr)
        if (arr[i].first > sum / 2)
            return false;
    return true;
}

int n;

void solve(int testCase) {
    arr.clear();
    cout << "Case #" << testCase << ": ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(make_pair(x, i));
    }

    while (!arr.empty()) {
        int senator = getMax();

        if (valid())
            printf("%c ", senator + 'A');
        else  {
            int senator2 = getMax();
            printf("%c%c ", senator + 'A', senator2 + 'A');
        }
    }
    cout << endl;
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int T;
    cin >> T;
    for (int i = 1;i<=T; i++) {
        solve(i);
    }
}
