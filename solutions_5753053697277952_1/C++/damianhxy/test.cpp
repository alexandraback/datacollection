#include <iostream>
#include <map>
using namespace std;

int T, N, P, TOT;
multimap<int, char> M;

void greedy() {
    while (TOT) {
        auto fir = prev(M.end());
        auto sec = fir;
        if (M.size() > 1)
            sec = prev(M.end(), 2);
        if (M.size() > 1 && TOT - 1 < sec->first * 2) { // Remove both
            cout << " " << fir->second << sec->second;
            if (fir->first > 1)
                M.insert({fir->first - 1, fir->second});
            if (sec->first > 1)
                M.insert({sec->first - 1, sec->second});
            M.erase(fir);
            M.erase(sec);
            TOT -= 2;
        } else { // Remove one
            cout << " " << fir->second;
            if (fir->first > 1)
                M.insert({fir->first - 1, fir->second});
            M.erase(fir);
            --TOT;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int a = 1; a <= T; ++a) {
        cin >> N;
        M.clear();
        TOT = 0;
        for (int a = 0; a < N; ++a) {
            cin >> P;
            TOT += P;
            M.insert({P, a + 'A'});
        }
        cout << "Case #" << a << ":";
        greedy();
        cout << "\n";
    }
    return 0;
}
