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

ll B, N;
ll bar[1001];

ll gettotalindex(ll numofi, ll b){
    ll total = 0;
    ll time = bar[b] * (numofi - 1);
    for (ll i = 1; i <= b; ++i){
        total += time / bar[i] + 1;
    }
    for (ll i = b + 1; i <= B; ++i){
        total += (time - 1) / bar[i] + 1;
    }
    return total;
}

int main(int argc, const char * argv[]) {
    ofstream cout("/Users/apple/Desktop/output2.txt");
    ifstream cin("/Users/apple/Downloads/B-large.in.txt");
    ll t = 0, T; cin >> T;
    while (t++ != T){
        cin >> B >> N;
        ll n = 0;
        while (n++ != B){
            cin >> bar[n];
        }
        ll value = -1;
        for (ll i = 1; i <= B; ++i){
            ll numofi = 1;
            while(gettotalindex(numofi, i) < N){
                numofi *= 2;
            }
            ll begin = 1, end = numofi;
            while (begin <= end - 2){
                ll mid = (begin + end) / 2;
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