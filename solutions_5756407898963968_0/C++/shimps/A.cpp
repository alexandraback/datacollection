#include <iostream>
using namespace std;

#define FOR(i,n) for(int i=1;i<=(n);i++)

int main() {
    int T;
    cin >> T;
    FOR(cn,T) {
        cout << "Case #" << cn << ": ";
        int a;
        cin >> a;
        int A[5][5];
        FOR(i,4) FOR(j,4) cin >> A[i][j];
        int b;
        cin >> b;
        int B[5][5];
        FOR(i,4) FOR(j,4) cin >> B[i][j];
        int nu, cnt = 0;
        FOR(i,4) FOR(j,4) if(A[a][i] == B[b][j]) {
            cnt++;
            nu = A[a][i];
        }
        if (cnt == 0) {
            cout << "Volunteer cheated!" << endl;
        }
        if (cnt == 1) {
            cout << nu << endl;
        }
        if (cnt > 1) {
            cout << "Bad magician!" << endl;
        }
    }
    return 0;
}

