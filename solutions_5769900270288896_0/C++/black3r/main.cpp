#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<bool>> appartement;

ll build_appartement(ll r, ll c) {
    appartement.clear();
    for (int i = 0; i < r+2; i++) {
        vector<bool> wat;
        for (int j = 0; j < c+2; j++) {
            if (i == 0 || j == 0 || i == r+1 || j == c+1) {
                wat.push_back(false);
            }
            else {
                wat.push_back(true);
            }
        }
        appartement.push_back(wat);
    }
}

ll neighboring_walls(ll i, ll j) {
    ll dx[] = {1, 0, -1, 0};
    ll dy[] = {0, 1, 0, -1};
    ll result = 0;
    for (ll k = 0; k < 4; k++) {
        result += appartement[i+dx[k]][j+dy[k]];
    }
    return result;
}

ll count_walls() {
    ll result = 0;
    for (ll i = 1; i < appartement.size() - 1; i++) {
        for (ll j = 1; j < appartement[i].size() - 1; j++) {
            result += neighboring_walls(i, j) * appartement[i][j];
        }
    }
    return result/2;
}

ll greedy_erase() {
    ll maxi = -1, maxj = -1;
    ll maxw = 0;
    for (ll i = 1; i < appartement.size() - 1; i++) {
        for (ll j = 1; j < appartement[i].size() - 1; j++) {
            if (appartement[i][j]) {
                // if someone lives here
                ll cw = neighboring_walls(i, j);
                if (cw > maxw) {
                    maxw = cw;
                    maxi = i;
                    maxj = j;
                }
            }
        }
    }
    if (maxw != 0)
        appartement[maxi][maxj] = 0;
    return maxw;
}

int main()
{
    int T; cin >> T;
    for (int I = 1; I <= T; I++) {
        ll result = 0;
        ll R, C, N; cin >> R >> C >> N;
        build_appartement(R, C);
        if (N == 0) result = 0;
        else {
            for (ll tennants = R*C; tennants != N; tennants--) {
                if (!greedy_erase()) break;
            }
            result = count_walls();
        }
        for (ll i = 1; i < appartement.size() - 1; i++) {
            for (ll j = 1; j < appartement[i].size() - 1; j++) {
                //cout << appartement[i][j];
            }
            //cout << endl;
        }
        cout << "Case #" << I << ": " << result << endl;
    }
    return 0;
}

