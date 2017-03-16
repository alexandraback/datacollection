#include<bits/stdc++.h>
using namespace std;

int r, c, k;
int ret;
vector<vector<bool> > grid;

void init(){
    ret = INT_MAX;
    grid.assign(r, vector<bool>(c, false));
}

void computeCost(){
    int cost = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(grid[i][j]){
                if(i > 0 && grid[i - 1][j]) cost++;
                if(i < r - 1 && grid[i + 1][j]) cost++;
                if(j > 0 && grid[i][j - 1]) cost++;
                if(j < c - 1 && grid[i][j + 1]) cost++;
            }
        }
    }
    ret = min(ret, cost / 2);
}
    

void backtrack(int i, int j, int cur){
    if(cur == k){
        computeCost();
        return;
    }

    if(i == r) return;

    if(j == c - 1) backtrack(i + 1, 0, cur);
    else backtrack(i, j + 1, cur);

    grid[i][j] = true;
    if(j == c - 1) backtrack(i + 1, 0, cur + 1);
    else backtrack(i, j + 1, cur + 1);
    grid[i][j] = false;
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> r >> c >> k;
        init();
        backtrack(0, 0, 0);
        printf("Case #%d: %d\n", t, ret);
    }
    return 0;
}
