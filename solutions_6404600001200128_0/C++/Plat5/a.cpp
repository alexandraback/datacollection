//
//  a.cpp
//  CodeJam15Round1A
//
//  Created by Ahmed Mohammed on 4/18/15.
//  Copyright (c) 2015 Akhmed. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;


void solve_case(uint64_t case_no, ifstream &fin, ofstream &fout);

int main(int argc, const char * argv[])
{
    if (argc < 3) { printf("Usage: %s <input file> <output file>\n", argv[0]); exit(1);}
    
    ifstream fin(argv[1], ios::in|ios::ate);
    if (!fin.is_open()) { printf("Unable to open input file\n"); exit(1);}
    fin.seekg(0);
    
    ofstream fout(argv[2], ios::out|ios::ate);
    if (!fout.is_open()) { printf("Unable to open output file\n"); exit(1);}
    fout.seekp(0);
    
    fout.precision(7);
    fout.setf(ios::fixed);
    
    // solve cases
    uint64_t case_count; fin >> case_count;
    for (uint64_t case_no = 0; case_no < case_count; case_no++) solve_case(case_no + 1, fin, fout);
    
    fin.close();
    fout.close();
    
    return 0;
}









void solve_case(uint64_t case_no, ifstream &fin, ofstream &fout)
{
    fout << "Case #" << case_no << ": ";
    
    int N; fin >> N;
    int m[N]; for (int i = 0; i < N; i++) fin >> m[i];
    
    int a = 0;
    for (int i = 1; i < N; i++) if (m[i] < m[i-1]) a += m[i-1] - m[i];
    
    int b = 0;
    int md = 0;
    for (int i = 1; i < N; i++) { int d = m[i-1] - m[i]; if (d > md) md = d;}
    for (int i = 1; i < N; i++) { if (m[i-1] < md) b += m[i-1]; else b+= md;}
    
    fout << a << " " << b << endl;
}






