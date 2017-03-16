#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream filein;
    ofstream fileout;
    filein.open("A-small-attempt0.in",ios::in);
    fileout.open("output",ios::out);
    int T,n,m;
    int n1,n2,n3,n4;
    vector<int> tempv(4,0);
    vector<int> tempq(4,0);
    filein >> T;
    for (int i = 0;i < T;i++) {
        
        filein >> n;
        
        for (int j = 1;j < n;j++) {
            filein >> n1 >> n2 >> n3 >> n4;
        }
        
        filein >> tempv[0] >> tempv[1] >> tempv[2] >> tempv[3];
        
        for (int j = n+1;j <= 4;j++) {
            filein >> n1 >> n2 >> n3 >> n4;
        }
        
        filein >> n;
        
        for (int j = 1;j < n;j++) {
            filein >> n1 >> n2 >> n3 >> n4;
        }
        
        filein >> tempq[0] >> tempq[1] >> tempq[2] >> tempq[3];
        
        for (int j = n+1;j <= 4;j++) {
            filein >> n1 >> n2 >> n3 >> n4;
        }
        
        int sign = 0;
        int ans = 0;
        for (int j = 0;j < 4;j++) {
            int k = tempv[j];
            for (int r = 0;r < 4;r++) {
                if (tempq[r] == k) {
                    ans = k;
                    sign++;
                }
            }
        }
        
        fileout << "Case #" << i+1 << ": ";
        if (sign == 0) fileout << "Volunteer cheated!" << endl;
        if (sign == 1) fileout << ans << endl;
        if (sign > 1) fileout << "Bad magician!" << endl;
    }
    fileout.close();
}