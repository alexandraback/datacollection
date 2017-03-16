#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream _if("in.txt");
    ofstream _of("out.txt");
    int n;
    _if >> n;
    for(int i=0;i < n; i++){
        int a;
        int as[4][4];
        string smt;
        _if >> a;
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                _if >> as[j][k];

        int b;
        int bs[4][4];
        _if >> b;
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                _if >> bs[j][k];

        for(int j=0;j<4;j++)
            cout << as[a-1][j] << " ";
        cout << endl;
        for(int j=0;j<4;j++)
            cout << bs[b-1][j] << " ";
        cout << endl;

        int coll = 0;
        int num;
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                if(as[a-1][j] == bs[b-1][k]){
                    coll++;
                    num = as[a-1][j];
                }

        if (coll == 0)
            _of << "Case #" << i+1 << ": " << "Volunteer cheated!" << endl;
        if (coll > 1)
            _of << "Case #" << i+1 << ": " << "Bad magician!" << endl;
        if (coll == 1)
            _of << "Case #" << i+1 << ": " << num << endl;

    }
}
