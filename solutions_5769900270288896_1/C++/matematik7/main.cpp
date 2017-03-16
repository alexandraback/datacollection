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

int permutation(char *grid, int R, int C, int oldnoise) {
    int newnoise;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            for (int it = 0; it < R; it++) {
                for (int jt = 0; jt < C; jt++) {
                    if (grid[R*j + i] == 1 && grid[R*jt + it] == 0) {
                        grid[R*j + i] = 0;
                        grid[R*jt + it] = 1;
                        newnoise = evaluate(grid, R, C);
                        if (newnoise < oldnoise) {
                            return newnoise;
                        }
                        grid[R*j + i] = 1;
                        grid[R*jt + it] = 0;
                    }
                }
            }
        }
    }
    return oldnoise;
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
        
        int R, C, N, noise, newnoise;
        input >> R >> C >> N;
        
        noise = 0;
        
        char * grid = new char[R*C];
        
        for (int i = 0; i < R; i++) {
            if (N <= 0) {
                break;
            }
            for (int j = 0; j < C; j++) {
                if (N <= 0) {
                    break;
                }
                if (i % 2 == 0) {
                    if (j%2 == 0) {
                        grid[R*j + i] = 1;
                        N--;
                    } else {
                        grid[R*j + i] = 0;
                    }
                } else {
                    if (j%2 == 0) {
                        grid[R*j + i] = 0;
                    } else {
                        grid[R*j + i] = 1;
                        N--;
                    }
                }
            }
        }
        
        // vogali
        if (N > 0 && grid[R-1] == 0) {
            grid[R-1] = 1;
            N--;
        }
        if (N > 0 && grid[R*(C-1)] == 0) {
            grid[R*(C-1)] = 1;
            N--;
        }
        if (N > 0 && grid[R*(C-1) + R-1] == 0) {
            grid[R*(C-1) + R-1] = 1;
            N--;
        }
        
        
        // stranice
        for (int i = 0; i < R; i++) {
            if (N <= 0) {
                break;
            }
            if (grid[i] == 0) {
                grid[i] = 1;
                N--;
            }
            if (N <= 0) {
                break;
            }
            if (grid[R*(C-1) + i] == 0) {
                grid[R*(C-1) + i] = 1;
                N--;
            }
        }
        for (int j = 0; j < C; j++) {
            if (N <= 0) {
                break;
            }
            if (grid[j*R] == 0) {
                grid[j*R] = 1;
                N--;
            }
            if (N <= 0) {
                break;
            }
            if (grid[j*R + R-1] == 0) {
                grid[j*R + R-1] = 1;
                N--;
            }
        }
        
        for (int i = 0; i < R; i++) {
            if (N <= 0) {
                break;
            }
            for (int j = 0; j < C; j++) {
                if (N <= 0) {
                    break;
                }
                if (grid[j*R + i] == 0) {
                    grid[j*R + i] = 1;
                    N--;
                }
            }
        }
        
        noise = evaluate(grid, R, C);
        
        delete grid;
        
        cout << "Case #" << u+1 << ": ";
        cout << noise;
        cout << endl;
        cerr << "done" << endl;

    }

    return 0;
}
