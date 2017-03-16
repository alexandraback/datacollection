#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(){
    int a, b;
    cin >> a;
    int A[4][4];
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            cin >> A[i][j];
        }
    }
    cin >> b;
    a--; b--;
    int B[4][4];
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            cin >> B[i][j];
        }
    }
    sort(A[a], A[a]+4);
    sort(B[b], B[b]+4);
    vector<int> res;
    int x=0, y=0;
    while(x < 4 && y < 4){
        if(A[a][x] == B[b][y]) res.push_back(A[a][x]);
        if(x == 3) y++;
        else if(y == 3) x++;
        else if(A[a][x] < B[b][y]) x++;
        else y++;
    }
    if(res.size() == 1){
        cout << res[0];
    }
    else if(res.size() == 0){
        cout << "Volunteer cheated!";
    }
    else{
        cout << "Bad magician!";
    }
}

int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; ++t){
        cout << "Case #" << t+1 << ": ";
        solve();
        cout << '\n';
    }
}
