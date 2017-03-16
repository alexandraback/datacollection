//
//  main.cpp
//  MagicTrick
//
//  Created by Ahmed Mohammed Abdurahman on 4/12/14.
//  Copyright (c) 2014 Better LLC. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;



int main(int argc, const char * argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }
    
    
    // open files
    ifstream fin(argv[1], ios::in|ios::ate);
    if (!fin.is_open())
    {
        printf("Unable to open input file\n");
        exit(1);
    }
    fin.seekg(0);
    
    ofstream fout(argv[2], ios::out|ios::ate);
    if (!fout.is_open())
    {
        printf("Unable to open output file\n");
        exit(1);
    }
    fout.seekp(0);
    
    
    // solve test cases
    uint64_t testcase_count;
    fin >> testcase_count;
    for (uint64_t tcase = 0; tcase < testcase_count; tcase++)
    {
        int f[4][4], s[4][4];
        
        // read first arrangement
        int fr;
        fin >> fr; fr--;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                fin >> f[i][j];
        
        // read second arrangement
        int sr;
        fin >> sr; sr--;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                fin >> s[i][j];
        
        // do the rest
        int matchIndex = -1;     // in first arrangement
        int matchCount = 0;
        
        for (int i = 0; i < 4;
             i++)
            for (int j = 0; j < 4; j++)
                if (f[fr][i] == s[sr][j])
                {
                    matchCount++;
                    if (matchCount > 1) goto LoopExit;
                    matchIndex = i;
                }
        
    LoopExit:
        fout << "Case #" << (tcase + 1) << ": ";
        if (matchCount == 0) fout << "Volunteer cheated!" << endl;
        else if (matchCount == 1) fout << f[fr][matchIndex] << endl;
        else fout << "Bad magician!" << endl;
    }
    
    
    fin.close();
    fout.close();

    
    
    return 0;
}

