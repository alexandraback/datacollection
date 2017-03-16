#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;
int main(void){
    ifstream fin("A-small-attempt1.in");
    //ifstream fin("aex.in");
    ofstream fout("As.txt");
    int T;
    cin >> T;
/*
    string st;
    getline(fin,st);
    stringstream ss(st);
    ss >> T;
*/
    //cout << T << endl;
    for(int t = 0 ; t < T ; t++){
        //Bad magician! Volunteer cheated!
        int firstR,secR;
        string frs,srs;
        string board[4][4];
        // 0 find 1 bad 2 cheat
        string ans="0";
        string r1[4];
        cin >> firstR;
    /*
        fin >> frs;
        //cout << frs << endl;
        ss.str(frs);
        ss.clear();
        ss >> firstR;
*/
        //cout << firstR << endl;
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 4 ; j++){
                cin >> board[i][j];
                //fin >> board[i][j];
                //cout << board[i][j] << " ";
                if(i == firstR-1)
                    r1[j] = board[i][j];
            }
            //cout << endl;
        }
        cin >> secR;
/*
        fin >> srs;
        ss.str(srs);
        ss.clear();
        ss >> secR;
*/
        int count = 0;
        for(int i = 0 ; i < 4 ; i++){
            for(int j = 0 ; j < 4 ; j++){
                cin >> board[i][j];
                //fin >> board[i][j];
                //cout << board[i][j] << " ";
                if(i == secR-1){
                    for(int k = 0 ; k < 4 ; k++){
                        if(r1[k] == board[i][j]){
                            count += 1;
                            ans = board[i][j];
                        }
                    }
                }
            }
            //cout << endl;
        }
        if(count > 1){
            cout << "Case #" << t+1 << ": " << "Bad magician!\n";
            //fout << "Case #" << t+1 << ": " << "Bad magician!\n";
        }
        else if(count == 1){
            cout << "Case #" << t+1 << ": " << ans << "\n";
            //fout << "Case #" << t+1 << ": " << ans << "\n";
        }
        else{
            cout << "Case #" << t+1 << ": " << "Volunteer cheated!\n";
            //fout << "Case #" << t+1 << ": " << "Volunteer cheated!\n";
        }

        //fout << "Case #" << t+1 << ": " << ans[result] << "\n";

    }
/*
    fin.close();
    fout.close();
*/
    return 0;
}
