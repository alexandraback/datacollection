#include <bits/stdc++.h>

using namespace std;

typedef long long llong;

int solve(vector<int>& deg, int n, int size){
    if(size >= n) return 0;
    sort(deg.begin(), deg.end());
    int sol = 0;
    for(int i = 0; i < n - size; i++){
        sol += deg[i];
    }
    return sol;
}

int main(){
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        int r, c, n;
        cin >> r >> c >> n;
        vector<int> deg[2];
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int side = (i + j) % 2;
                int cnt = 0;
                if(i > 0) cnt++;
                if(i + 1 < r) cnt++;
                if(j > 0) cnt++;
                if(j + 1 < c) cnt++;
                deg[side].push_back(cnt);

            }
        }


        int sol = min(solve(deg[0], n, deg[1].size()), solve(deg[1], n, deg[0].size()));

        cout << "Case #" << tc << ": " << sol << endl;
    }
}
