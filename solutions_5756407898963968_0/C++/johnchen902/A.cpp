#include <iostream>
#include <algorithm>

using namespace std;

int solve(){
    bool x[16] = {};
    unsigned r1; cin >> r1; r1--;
    for(unsigned i = 0; i < 16; i++){
        unsigned j; cin >> j;
        if(r1 * 4 <= i && i < (r1 + 1) * 4)
            x[j - 1] = true;
    }
    unsigned r2; cin >> r2; r2--;
    for(unsigned i = 0; i < 16; i++){
        unsigned j; cin >> j;
        if(r2 * 4 > i || i >= (r2 + 1) * 4)
            x[j - 1] = false;
    }
    unsigned u = count(x, x + 16, true);
    if(u == 0) return -2;
    else if(u > 1) return -1;
    else return find(x, x + 16, true) - x + 1;
}

int main(){
    unsigned t;
    cin >> t;
    for(unsigned i = 1; i <= t; i++){
        int x = solve();
        cout << "Case #" << i << ": ";
        if(x == -1)
            cout << "Bad magician!";
        else if(x == -2)
            cout << "Volunteer cheated!";
        else
            cout << x;
        cout << endl;
    }
}
