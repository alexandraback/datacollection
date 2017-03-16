#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream in("A-small.in");
ofstream out("Aout.txt");

int main() {
    int T;
    in >> T;
    for( int TC= 1; TC <=T; TC++ ) {
        int A[2], cans;
        int arr[2][4][4];

        vector<int> fAns, sAns[4];

        in >> A[0]; A[0]--;
        for( int i=0; i<4; i++ ) {
            for( int j=0; j<4; j++ ) {
                in >> arr[0][i][j];
            }
        }

        in >> A[1]; A[1]--;
        for( int i=0; i<4; i++ ) {
                for( int j=0; j<4; j++ ) in >> arr[1][i][j];
        }

        //check volunteer cheating
        int gFound = 0;
        for( int i=0; i<4; i++ ) {
            bool tF = false;
            for( int j=0; j<4; j++ ) {
                if( arr[0][A[0]][i] == arr[1][A[1]][j] ) {tF=true; cans = arr[1][A[1]][j]; break;}
            }
            if(tF) {gFound++;}
        }

        if( gFound==0 ) cans = -2;
        else if (gFound > 1) cans = -1; //magician error

        switch(cans) {
            case -2:
                out << "Case #" << TC << ": " << "Volunteer cheated!" << endl; break;
            case -1:
                out << "Case #" << TC << ": " << "Bad magician!" << endl; break;
            default:
                out << "Case #" << TC << ": " << cans << endl; break;
        }

    }

    return 0;
}
