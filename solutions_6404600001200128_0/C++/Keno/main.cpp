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


int main(int argc, const char * argv[]) {
    
    ifstream fin;
//    fin.open("example.txt", ios::in);
    fin.open("A-small-attempt0.in.txt", ios::in);
    
    ofstream fout;
    fout.open("output-A-s.txt", ios::out);
    
    string out;
    
    // read parameters and calculate
    
    int T;
    fin >> T;
    
    for (int i = 0; i < T; i++) {
        int N;
        fin >> N;
        
        vector <int>a;
        
        int maxDif = 0;
        int lastNum = 0;
        for(int j = 0; j < N; j++) {
            int temp;
            fin >> temp;
            a.push_back(temp);
            if (lastNum - temp > maxDif) {
                maxDif = lastNum - temp;
            }
            lastNum = temp;
        }
        
        int t1 = 0;
        int t2 = 0;
        for(int j = 1; j < N; j++) {
            t1 += max(0, a[j-1] - a[j]);
            t2 += min(maxDif, a[j-1]);
        }
        
        fout << "Case #" << (i+1) << ": " << t1 << " " << t2 << endl;
//        cout << "Case #" << (i+1) << ": " << t1 << " " << t2 << endl;
        
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
