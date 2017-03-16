//Problem A. Magic Trick
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    freopen("CJA.in", "r", stdin);
    freopen("CJA.out", "w", stdout);


    int T;
    cin >> T;
    for(int cse = 1; cse <= T; cse++) {
        int ans[2], grids[2][4][4];

        for(int i = 0; i < 2; i++) {
            cin >> ans[i];
            ans[i]--;
            for(int j = 0; j < 4; j++)
                for(int k = 0; k < 4; k++)
                    cin >> grids[i][j][k];
        }

        int num = 0, lnum;

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(grids[ 0 ][ ans[0] ][ i ] == grids[ 1 ][ ans[1] ][ j ])
                    num++, lnum = grids[ 0 ][ ans[0] ][i];

        cout << "Case #" << cse << ": ";

        if(num == 0)
            cout << "Volunteer cheated!" << endl;
        else if(num == 1)
            cout << lnum << endl;
        else
            cout << "Bad magician!" << endl;
    }
}
