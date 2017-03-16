#include <fstream>
using namespace std;


int main(int argc, char * argv[])
{
    if (argc != 2)
        return 1;
    
    ifstream fin(argv[1]);
    ofstream fout("output.txt");
    
    int T, t;
    int sen[26];
    int N, i;
    int max, secmax;
    
    fin >> T;
    
    for (t = 1; t <= T; t++) {
        fin >> N;
        
        for (i = 0; i < N; i++)
            fin >> sen[i];
        
        max = 0;
        
        for (i = 0; i < N; i++)
            if (sen[i] > sen[max])
                max = i;
        
        secmax = (max > 0 ? max - 1 : max + 1);
        
        for (i = 0; i < N; i++)
            if (i != max && sen[i] > sen[secmax])
                secmax = i;
        
        fout << "Case #" << t << ":";
        
        while (sen[max] > sen[secmax]) {
            if (sen[max] - sen[secmax] >= 2) {
                fout << ' ' << (char) ('A' + max) << (char) ('A' + max);
                sen[max] -= 2;
            }
            else {
                sen[max]--;
                fout << ' ' << (char) ('A' + max);
            }
        }
        
        for (i = 0; i < N; i++)
            if (i != max && i != secmax) {
                while (sen[i] > 0) {
                    if (sen[i] >= 2) {
                        fout << ' ' << (char) ('A' + i) << (char) ('A' + i);
                        sen[i] -= 2;
                    }
                    else {
                        fout << ' ' << (char) ('A' + i);
                        sen[i] -= 1;
                    }
                }
            }
        
        while (sen[max] > 0) {
            fout << ' ' << (char) ('A' + max) << (char) ('A' + secmax);
            sen[max]--;
            sen[secmax]--;
        }
        
        fout << endl;
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
