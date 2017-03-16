#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>
#include <utility>
#include <stdlib.h>
#include <stdio.h>


using namespace std;
typedef unsigned long long ull;

int T, N;


long long m[10005];

int main(){
   
    ifstream ins("A-large.in");
    //ifstream ins("A-small.txt");
    ofstream ofs("A-large-out.txt");
    
    ins >> T;
    
    for (int cse = 1; cse <= T; cse++){
        ins >> N;
        
        long long sumA = 0;
        double rateB = -1;
        for (int i = 0; i < N; i++){
            ins >> m[i];
            if (i && (m[i] <= m[i-1] )){
                sumA += (m[i-1] - m[i]);
                rateB = max(rateB,1.0*(m[i-1] - m[i])/10.0);
            }
        }
        
        
        
        long long numB = 0;
        
        for (int i = 0; i < N-1; i++){
            numB += min(m[i], static_cast<long long> (rateB*10) );
        }
        
        
        
        ofs << "Case #" << cse << ": " << sumA << " " << numB << endl;
    }
    
    return 0;
}


