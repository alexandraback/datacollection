//
//  main.cpp
//  2015R1A
//
//  Created by apple on 15/4/18.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

int m[1001];

int main(int argc, const char * argv[]) {
    ofstream cout("/Users/apple/Desktop/output2.txt");
    ifstream cin("/Users/apple/Downloads/A-large.in.txt");
    int t = 0, T; cin >> T;
    while (t++ != T){
        int N; cin >> N;
        for (int i = 0; i < N; ++i)cin >> m[i];
        // solve for num 1
        int num1 = 0;
        for (int i = 1; i < N; ++i){
            if (m[i] < m[i - 1])num1 += m[i - 1] - m[i];
        }
        // solve for num 2
        int speed = 0;
        for (int i = 1; i < N; ++i){
            speed = MAX(speed, m[i - 1] - m [i]);
        }
        int num2 = 0;
        for (int i = 0; i < N - 1; ++i){
            num2 += MIN(m[i], speed);
        }
        cout << "Case #" << t << ": " << num1 << " " << num2 << endl;
    }
    return 0;
}
