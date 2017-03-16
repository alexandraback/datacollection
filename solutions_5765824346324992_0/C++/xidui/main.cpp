//
//  main.cpp
//  2015R1B
//
//  Created by apple on 15/4/18.
//  Copyright (c) 2015年 apple. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

int B, N;
ll bar[1001];

int gettotalindex(int numofi, int b){
    int total = 0;
    ll time = bar[b] * (numofi - 1);
    for (int i = 1; i <= b; ++i){
        total += time / bar[i] + 1;
    }
    for (int i = b + 1; i <= B; ++i){
        total += (time - 1) / bar[i] + 1;
    }
    return total;
}

int main(int argc, const char * argv[]) {
    ofstream cout("/Users/apple/Desktop/output1.txt");
    ifstream cin("/Users/apple/Downloads/B-small-attempt0.in.txt");
    int t = 0, T; cin >> T;
    while (t++ != T){
        cin >> B >> N;
        int n = 0;
        while (n++ != B){
            cin >> bar[n];
        }
        int value = -1;
        for (int i = 1; i <= B; ++i){
            int numofi = 1;
            while(gettotalindex(numofi, i) < N){
                numofi *= 2;
            }
            int begin = 1, end = numofi;
            while (begin <= end - 2){
                int mid = (begin + end) / 2;
                if (gettotalindex(mid, i) < N){
                    begin = mid;
                }else{
                    end = mid;
                }
            }
            if (gettotalindex(end, i) == N || gettotalindex(begin, i) == N){
                value = i;
                break;
            }
        }
        
        cout << "Case #" << t << ": " << value << endl;
    }
    return 0;
}