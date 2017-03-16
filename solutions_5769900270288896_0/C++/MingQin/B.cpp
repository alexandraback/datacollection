/*
 * File:   main.cpp
 * Author: Ming Qin
 *
 * Created on February 27, 2015, 8:37 PM
 */

 //#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void assert(bool expression, int code = 0) {
    if (!expression) {
        cout << "assertion fail! Code=" << code << endl;
        system("pause");
        exit(-1);
    }
}
int r, c, n, rc;
int best;

vector<bool> ve;

bool checkCell(int i) {
    int row, col;
    row = i/c;
    col = i - row*c;
    assert((row < r && col < c), i);
    return ve[i];
}

int countHap() {
    int row, col,unhap;
    unhap = 0;
    for (int i = 0; i < ve.size()-1; ++i) {
        if (ve[i]) {
            row = i / c;
            col = i - row*c;
            if (col < c - 1 && checkCell(i + 1)) {
                ++unhap;
            }
            if (row < r - 1 && checkCell(i + c)) {
                ++unhap;
            }
            if (best < unhap) {
                return 0;
            }
        }
    }
    best = unhap;
    return 0;
}

void search(int i, int num) {
    if (num > n) return;
    if (rc - i < n - num) return;
    if (i==rc) {
        if (num == n) {
            countHap();
        }
        return;
    }
    ve[i] = true;
    search(i + 1, num + 1);
    ve[i] = false;
    search(i + 1, num);
}

int solve() {
    rc = r*c;
    //map = vector<vector<bool> >(r, vector<bool>(c, false));
    ve = vector<bool>(rc, false);
    best = INT_MAX;
    search(0,0);
    return best;
}

int main() {
    vector<string> strv;
    int TestCase;

    fstream infile("i0.in");
    ofstream outfile("out.txt");

    infile >> TestCase;
    for (int caseID = 1; caseID <= TestCase; ++caseID) {
        infile >> r >> c >> n;

        outfile << "Case #" << caseID << ": ";
        outfile << solve() << endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
