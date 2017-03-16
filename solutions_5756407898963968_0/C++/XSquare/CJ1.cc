#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <vector <int> > M(4, vector <int> (4));
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t){
        vector <int> cont(16, 0);
        int n;
        cin >> n;
        --n;
        for (int i = 0; i < 4; ++i){
            for (int j = 0; j < 4; ++j){
                cin >> M[i][j];
                if (i == n) ++cont[M[i][j]-1];
            }
        }
        cin >> n;
        --n;
        for (int i = 0; i < 4; ++i){
            for (int j = 0; j < 4; ++j){
                cin >> M[i][j];
                if (i == n) ++cont[M[i][j]-1];
            }
        }
        int sols = 0;
        int sol = 0;
        for (int i = 0; i < 16; ++i){
            if (cont[i] == 2){
                        ++sols;
                        sol = i+1;
            }
        }
        cout << "Case #" << t << ": ";
        if (sols == 0) cout << "Volunteer cheated!" << endl;
        else if (sols == 1) cout << sol << endl;
        else cout << "Bad magician!" << endl;
    }
}
        
