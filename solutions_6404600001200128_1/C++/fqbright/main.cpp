//
//  main.cpp
//  codejam
//
//  Created by fq_bright on 10/4/15.
//  Copyright (c) 2015 fq_bright. All rights reserved.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int min(int a,int b) {return a>b?b:a;}
int max(int a,int b) {return a>b?a:b;}

bool cmp(string s1, string s2) { return s1.length() < s2.length(); }

int main() {
    string path = "/Users/fq_bright/Desktop/A-large.in";
    string out_path = "/Users/fq_bright/Desktop/ret.txt";
    ifstream ifs;
    ofstream ofs;
    
    ofs.open(out_path.c_str());
    ifs.open(path.c_str());
    int T;
    string tt = "Case #";
    ifs >> T;
    int time = 1;
    while (time <= T) {
        int D;
        ifs >> D;
        int ret1 = 0, ret2 = 0;
        int a[1001];
        for (int i = 0; i < D; ++i)
            ifs >> a[i];
        
        int tmp = 0;
        for (int i = 0; i < D-1; ++i) {
            if (a[i+1] < a[i])
                ret1 += a[i] - a[i+1];
            
            tmp = max(tmp, a[i] - a[i+1]);
        }
        
        for (int i = 0; i < D-1; ++i) {
            ret2 += min(tmp, a[i]);        }
        ofs << tt;
        ofs << time++;
        ofs << ": ";
        ofs << ret1 << " " << ret2 << endl;
        
    }
    ifs.close();
    ofs.close();
    system("pause");
}










