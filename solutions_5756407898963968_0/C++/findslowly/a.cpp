#include <iostream> 
#include <fstream> 
using namespace std; 

ifstream fin("A-small-attempt3.in"); 
ofstream fout("A-small-attempt3.out"); 
int main() {
    int T ; 
    fin >> T ; 
    for (int num = 0; num < T; ++num) {
        int arr[17] ; 
        for (int i = 1; i < 17; ++i) 
            arr[i] = 0 ; 

        int row1, row2, card; 
        fin >> row1; 
        for (int i = 1; i < 17; ++i) {
            fin >> card ; 
            if (i > 4*(row1-1) && i <= 4*row1) 
                arr[card]++ ; 
        }

        fin >> row2; 
        for (int i = 1; i < 17; ++i) {
            fin >> card ; 
            if (i > 4*(row2-1) && i <= 4*row2) 
                arr[card]++ ; 
        }

        int sum = 0 ; 
        int ans ; 

        for (int i = 1; i < 17; ++i) 
            if (arr[i] == 2) {
                sum++ ; 
                ans = i ; 
            }
        if (sum == 1) 
            fout << "Case #" << num+1 << ": " << ans << endl;
        else if (sum == 0) 
            fout << "Case #" << num+1 << ": Volunteer cheated!" << endl;
        else  
            fout << "Case #" << num+1 << ": Bad magician!" << endl;
    }
    return 0 ; 
}
