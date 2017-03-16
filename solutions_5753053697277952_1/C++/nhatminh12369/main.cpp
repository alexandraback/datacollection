#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <math.h>
#include <stdlib.h>

using namespace std;

bool checkBalance(int *P, int N, int totalSenator) {
    bool result = true;
    for (int i=0;i<N;i++) {
        if (P[i]*2 > totalSenator) {
            result = false;
        }
    }
    return result;
}

int main() {
    ifstream fin ("/Users/LeonardNguyen/Documents/projects/ios/usaco/A-large.in");
    ofstream fout ("/Users/LeonardNguyen/Documents/projects/ios/usaco/A-large.out");
    
    int T;
    fin >> T;
    
    for (int iCase = 0;iCase<T;iCase++) {
        int N;
        fin >> N;
        int *P = new int[N];
        
        fout<<"Case #"<<iCase+1<<": ";
        
        int totalSenator = 0;
        for (int i=0;i<N;i++) {
            fin >> P[i];
            totalSenator += P[i];
        }
        
        while (totalSenator > 0) {
            bool flagValidPair = false;
            for (int i=0;i<N;i++) {
                if (P[i] == 0) continue;
                else {
                    P[i]--;
                }
                for (int j=0;j<N;j++) {
                    if (P[j] == 0) continue;
                    else {
                        P[j]--;
                    }
                    flagValidPair = checkBalance(P, N, totalSenator-2);
                    if (!flagValidPair)
                        P[j]++;
                    else {
                        fout<<(char)('A'+i)<<(char)('A'+j)<<" ";
                        totalSenator -= 2;
                        break;
                    }
                }
                if (!flagValidPair) {
                    flagValidPair = checkBalance(P,N,totalSenator-1);
                    
                    if (!flagValidPair)
                        P[i]++;
                    else {
                        fout<<(char)('A' + i)<<" ";
                        totalSenator -= 1;
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        
        fout<<endl;
        
        delete[] P;
    }
    
    fin.close();
    fout.close();
    return 0;
}

