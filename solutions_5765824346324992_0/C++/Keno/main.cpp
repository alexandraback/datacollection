//
//  main.cpp
//  GCJ
//
//  Created by Keno on 2015/04/11.
//  Copyright (c) 2015年 Keno. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

struct tree {
    double x;
    double y;
};

double outerProduct(tree vec1, tree vec2) {
    return vec1.x * vec2.y - vec1.y * vec2.x;
}


int main(int argc, const char * argv[]) {
    
    ifstream fin;
//    fin.open("example.txt", ios::in);
    fin.open("B-small-attempt2.in.txt", ios::in);
    
    ofstream fout;
    fout.open("output-B-s2.txt", ios::out);
    
    string out;
    
    // read parameters and calculate
    
    int T;
    fin >> T;
    
    for (int i = 0; i < T; i++) {
        int B;
        fin >> B;
        int N;
        fin >> N;
        
        vector <int> M;
        
        int simpleProduct = 1;
        for(int j = 0; j < B; j++) {
            int m;
            fin >> m;
            M.push_back(m);
            simpleProduct *= m;
        }
        int numberOfCustomers = 0;
        
        for (int j = 0; j < B; j++) {
            numberOfCustomers += simpleProduct / M[j];
        }
        
        N = N % numberOfCustomers;
        
        int targetB = B - 1;
        bool done = false;
        if (N > 0) {
            if (N <= B) {
                targetB = N - 1;
            } else {
                int totalN = 0;
                N -= B;
                for (int j = 1; j < simpleProduct; j++) {
                    for (int k = 0; k < B; k++) {
                        totalN += (j / M[k]);
                        totalN -= ((j - 1) / M[k]);
                        if (totalN >= N) {
                            targetB = k;
                            done = true;
                            break;
                        }
                    }
//                    cout << j << " min, " << totalN << " customers" << endl;
                    if (done) {
                        break;
                    }
                }
            }
        }
        
        fout << "Case #" << (i+1) << ": " <<  (targetB + 1) << endl;
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
