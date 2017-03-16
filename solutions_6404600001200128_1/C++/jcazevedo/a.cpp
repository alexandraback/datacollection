#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
vector<int> mushrooms;

pair<int, int> getEaten() {
    int res1 = 0;
    int rate = 0;
    for (int i = 1; i < N; i++) {
        res1 += max(mushrooms[i - 1] - mushrooms[i], 0);
        if (mushrooms[i - 1] - mushrooms[i] > rate)
            rate = mushrooms[i - 1] - mushrooms[i];
    }

    int res2 = 0;
    for (int i = 0; i < N - 1; i++) {
        res2 += min(rate, mushrooms[i]);
    }

    return make_pair(res1, res2);
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> N;
        mushrooms.assign(N, 0);

        for (int j = 0; j < N; j++)
            cin >> mushrooms[j];

        pair<int, int> res = getEaten();
        cout << "Case #" << i << ": " << res.first << " " << res.second << endl;
    }

    return 0;
}
