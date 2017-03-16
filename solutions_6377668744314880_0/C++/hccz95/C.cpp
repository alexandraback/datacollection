#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
typedef long long ll;
using namespace std;

char g[20][20][20];
char hc[6][15];
const char o[11][3][4] = {
   " _ ", "| |", "|_|",
   "   ", "  |", "  |",
   " _ ", " _|", "|_ ",
   " _ ", " _|", " _|",
   "   ", "|_|", "  |",
   " _ ", "|_ ", " _|",
   " _ ", "|_ ", "|_|",
   " _ ", "  |", "  |",
   " _ ", "|_|", "|_|",
   " _ ", "|_|", " _|"

};
inline void outp(int x, int del){
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            hc[i][del+j] = o[x][i][j];
}
int main(){
//    for (int k=0; k<=9; k++){
//    for (int i=0; i<5; i++)
//        puts(o[k][i]);
//    puts("");
//    }
    int a, b , c, d;
    memset(g, 0, sizeof(g));
    for (int i=0; i<=9; i++)
        for (int j=1; j<=5; j++)
            for (int k=1; k<=3; k++)
                g[i][j][k] = ' ';
    for (int i=1; i<=5; i++)
        for (int j=1; j<=3; j++) hc[i][j] = ' ';
    while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF){
        memset(hc, 0, sizeof(hc));
        outp(a, 0);
        outp(b, 3);
        outp(c, 6);
        outp(d, 9);
        for (int i=0; i<3; i++){
            for (int j=0; j<12; j++) putchar(hc[i][j]);
            puts("");
        }
    }
//    x(0, 1, 2);
//    x(0, 5, 2);
//    y(0, 2, 1);
//    y(0, 2, 3);
//    y(0, 4, 1);
//    y(0, 4, 3);
//
//    y(1, 2, 3);
//    y(1, 4, 3);


    return 0;
}


//    _  _  _
//  | _||_ |_
//  ||_  _||_|
//
//    _  _  _
//  | _||_ |_
//  ||_  _||_|
//    _  _  _
//  |  ||  |
//    _  _  _
//  ||    || |
//    _  _  _
//// _  _     _
//// _| _||_| _|
////|_  _|  ||_
