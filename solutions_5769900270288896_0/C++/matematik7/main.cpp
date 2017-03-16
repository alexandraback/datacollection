/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*  Mafijski praktikum naloga
 *  =========================
 *  Copyright 2015 Domen Ipavec <domen.ipavec@z-v.si>
 *
 *  Licensed under the MIT License (the "License");
 */


#include <iostream>
#include <cmath>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
#include <string>
#include <stdint.h>
using namespace std;

int evaluate(char *grid, int R, int C) {
    int noise = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i >= 1 && grid[R*j + i] == 1 && grid[R*j + i-1] == 1) {
                noise++;
            }
            if (j >= 1 && grid[R*j + i] == 1 && grid[R*(j-1) + i] == 1) {
                noise++;
            }
        }
    }
    return noise;
}

int exponential(char * grid, int R, int C, int j, int N, int total) {
    if (j < R*C) {
        if (R*C - j > N-total) {
            if (N > total) {
                char *ngrid = new char[R*C];
                grid[j] = 0;
                for (int i =0; i < j; i++) {
                    ngrid[i] = grid[i];
                }
                ngrid[j] = 1;
                
                int g = exponential(grid, R, C, j+1, N, total);
                int ng = exponential(ngrid, R, C, j+1, N, total+1);
                
                delete[] ngrid;
                
                return min(g,ng);
            } else {
                grid[j] = 0;
                return exponential(grid, R, C, j+1, N, total);
            }
        } else {
            grid[j] = 1;
            return exponential(grid, R, C, j+1, N, total+1);
        }
    } else {
        return evaluate(grid, R, C);
    }
}

int main(int argc, char *argv[]) {
    cout.precision(10);
    ifstream input;
   
    if (argc < 2) {
        input.open("data.dat");
    } else {
        input.open(argv[1]);
    }
    
    
    uint64_t n;
    input >> n;
    
    for (uint64_t u = 0; u < n; u++) {
        cerr << "Start " << u << endl;
        
        int R, C, N, noise;
        input >> R >> C >> N;
        
        noise = 0;
        
        char * grid = new char[R*C];
        
        noise = exponential(grid, R, C, 0, N,0);
        
        
        delete grid;
        
        cout << "Case #" << u+1 << ": ";
        cout << noise;
        cout << endl;
        cerr << "done" << endl;

    }

    return 0;
}
