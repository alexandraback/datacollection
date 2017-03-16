#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream infile;
    infile.open("A-small-attempt6.in");
    if(!infile){
        cerr << "error open" << endl;
        return -1;
    }
    ofstream out;
    out.open("magic.in");

    int n;
    infile >> n;
    int matrix[4][4];
    int check[4];
    int row, col;
    for(int i = 0; i < n; i++){
            infile >> row;
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                infile >> matrix[j][k];
                if(j == row-1){
                    check[k] = matrix[j][k];
                }
            }
        }
        infile >> col;
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                infile >> matrix[j][k];
            }
        }
        int num = 0, mj;
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++)
            if(check[j] == matrix[col-1][k]){
                num++;
                mj = j;
            }
        }
        if(num == 0){
            out << "Case #" << i+1 << ": Volunteer Cheated!\n";         
        }else if(num == 1){
            out << "Case #" << i+1 << ": " << check[mj] << "\n";         
        }else
            out << "Case #" << i+1 << ": Bad magician!\n";         
    }
    infile.close();
    out.close();
    return 0;
}
