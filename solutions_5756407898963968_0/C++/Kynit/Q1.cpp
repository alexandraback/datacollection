#include <iostream>
#include <fstream>

using namespace std;

int main(void){
    ifstream fin("Q1.in");
    ofstream fout("Q1.out");
    int cases, row, temp, ret = 0, retcard = 0;
    int *cards = new int[4];
    fin >> cases; fin.ignore();
    for(int i = 0; i < cases; i++){
        ret = 0;
        fin >> row;
        fin.ignore();
        for(int j = 0; j < 4; j++){
            if(j+1 == row){
                for(int k = 0; k < 4; k++){
                    fin >> cards[k]; 
                    fin.ignore();
                }
            } else{
                for(int k = 0; k < 4; k++){
                    fin >> temp;
                    fin.ignore();
                }
            }
        }
        fin >> row;
        fin.ignore();
        for(int j = 0; j < 4; j++){
            if(j+1 == row){
                for(int k = 0; k < 4; k++){
                    fin >> temp;
                    fin.ignore();
                    for(int l = 0; l < 4; l++){
                        if(temp == cards[l]){
                            ret++;
                            retcard = temp;
                        }
                    }
                }
            } else {
                for(int k = 0; k < 4; k++){
                    fin >> temp;
                    fin.ignore();
                }
            }
        }
        fout << "Case #" << i+1 << ": ";
        if(ret == 0){
            fout << "Volunteer cheated!" << endl;
        }
        else if(ret == 1){
            fout << retcard << endl;
        }
        else{
            fout << "Bad magician!" << endl;
        }
    }
    
    fout.close();
    
    getchar();
    return 0;
}
