//
//  b.cpp
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





int gcf(int x, int y)
{
    while (x && y)
    {
        if (x > y) x %= y;
        else y %= x;
    }
    
    return x ? x : y;
}



void solve_case(uint64_t case_no, ifstream &fin, ofstream &fout)
{
    fout << "Case #" << case_no << ": ";
    
    int B, N; fin >> B >> N;
    int m[1000]; for (int i = 0; i < B; i++) fin >> m[i];
    
    {
        int g = m[0]; int l = m[0];
        for (int i = 1; i < B; i++) { g = gcf(g, m[i]); l = (l * m[i]) / g;}
        
        int n = 0;
        for (int i = 0; i < B; i++) n += l / m[i];
        
        N--;
        N %= n;
        N++;
    }
    
    if (N <= B) { fout << N << endl; return;};
    
    int r[1000];
    for (int i = 0; i < B; i++) r[i] = m[i];
    int c = B;
    
    while (true)
    {
        int min = 0;
        for (int i = 1; i < B; i++) if (r[i] < r[min]) min = i;
        int el = r[min];
        for (int i = 0; i < B; i++) r[i] -= el;
        r[min] = m[min];
        c++;
        
        if (c == N) { fout << min + 1 << endl; return;}
    }
}






